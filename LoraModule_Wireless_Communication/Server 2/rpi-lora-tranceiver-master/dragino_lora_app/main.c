/*******************************************************************************
 *server2
 * Copyright (c) 2018 Dragino
 *
 * http://www.dragino.com
 *
 *******************************************************************************/

#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <time.h>


// #############################################
// #############################################
#define _CRT_SECURE_NO_WARNINGS
#define REG_FIFO                    0x00
#define REG_OPMODE                  0x01
#define REG_FIFO_ADDR_PTR           0x0D
#define REG_FIFO_TX_BASE_AD         0x0E
#define REG_FIFO_RX_BASE_AD         0x0F
#define REG_RX_NB_BYTES             0x13
#define REG_FIFO_RX_CURRENT_ADDR    0x10
#define REG_IRQ_FLAGS               0x12
#define REG_DIO_MAPPING_1           0x40
#define REG_DIO_MAPPING_2           0x41
#define REG_MODEM_CONFIG            0x1D
#define REG_MODEM_CONFIG2           0x1E
#define REG_MODEM_CONFIG3           0x26
#define REG_SYMB_TIMEOUT_LSB  		0x1F
#define REG_PKT_SNR_VALUE			0x19
#define REG_PAYLOAD_LENGTH          0x22
#define REG_IRQ_FLAGS_MASK          0x11
#define REG_MAX_PAYLOAD_LENGTH 		0x23
#define REG_HOP_PERIOD              0x24
#define REG_SYNC_WORD				0x39
#define REG_VERSION	  				0x42

#define PAYLOAD_LENGTH              0x40

// LOW NOISE AMPLIFIER
#define REG_LNA                     0x0C
#define LNA_MAX_GAIN                0x23
#define LNA_OFF_GAIN                0x00
#define LNA_LOW_GAIN		    	0x20

#define RegDioMapping1                             0x40 // common
#define RegDioMapping2                             0x41 // common

#define RegPaConfig                                0x09 // common
#define RegPaRamp                                  0x0A // common
#define RegPaDac                                   0x5A // common

#define SX72_MC2_FSK                0x00
#define SX72_MC2_SF7                0x70
#define SX72_MC2_SF8                0x80
#define SX72_MC2_SF9                0x90
#define SX72_MC2_SF10               0xA0
#define SX72_MC2_SF11               0xB0
#define SX72_MC2_SF12               0xC0

#define SX72_MC1_LOW_DATA_RATE_OPTIMIZE  0x01 // mandated for SF11 and SF12

// sx1276 RegModemConfig1
#define SX1276_MC1_BW_125                0x70
#define SX1276_MC1_BW_250                0x80
#define SX1276_MC1_BW_500                0x90
#define SX1276_MC1_CR_4_5            0x02
#define SX1276_MC1_CR_4_6            0x04
#define SX1276_MC1_CR_4_7            0x06
#define SX1276_MC1_CR_4_8            0x08

#define SX1276_MC1_IMPLICIT_HEADER_MODE_ON    0x01

// sx1276 RegModemConfig2
#define SX1276_MC2_RX_PAYLOAD_CRCON        0x04

// sx1276 RegModemConfig3
#define SX1276_MC3_LOW_DATA_RATE_OPTIMIZE  0x08
#define SX1276_MC3_AGCAUTO                 0x04

// preamble for lora networks (nibbles swapped)
#define LORA_MAC_PREAMBLE                  0x34

#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG1 0x0A
#ifdef LMIC_SX1276
#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG2 0x70
#elif LMIC_SX1272
#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG2 0x74
#endif

// FRF
#define        REG_FRF_MSB              0x06
#define        REG_FRF_MID              0x07
#define        REG_FRF_LSB              0x08

#define        FRF_MSB                  0xD9 // 868.1 Mhz
#define        FRF_MID                  0x06
#define        FRF_LSB                  0x66

// ----------------------------------------
// Constants for radio registers
#define OPMODE_LORA      0x80
#define OPMODE_MASK      0x07
#define OPMODE_SLEEP     0x00
#define OPMODE_STANDBY   0x01
#define OPMODE_FSTX      0x02
#define OPMODE_TX        0x03
#define OPMODE_FSRX      0x04
#define OPMODE_RX        0x05
#define OPMODE_RX_SINGLE 0x06
#define OPMODE_CAD       0x07

// ----------------------------------------
// Bits masking the corresponding IRQs from the radio
#define IRQ_LORA_RXTOUT_MASK 0x80
#define IRQ_LORA_RXDONE_MASK 0x40
#define IRQ_LORA_CRCERR_MASK 0x20
#define IRQ_LORA_HEADER_MASK 0x10
#define IRQ_LORA_TXDONE_MASK 0x08
#define IRQ_LORA_CDDONE_MASK 0x04
#define IRQ_LORA_FHSSCH_MASK 0x02
#define IRQ_LORA_CDDETD_MASK 0x01

// DIO function mappings                D0D1D2D3
#define MAP_DIO0_LORA_RXDONE   0x00  // 00------
#define MAP_DIO0_LORA_TXDONE   0x40  // 01------
#define MAP_DIO1_LORA_RXTOUT   0x00  // --00----
#define MAP_DIO1_LORA_NOP      0x30  // --11----
#define MAP_DIO2_LORA_NOP      0xC0  // ----11--
#define SIZE 18
#define DELAY_SIZE 125

// #############################################
// #############################################
//
typedef bool boolean;
typedef unsigned char byte;

static const int CHANNEL = 0;

char message[SIZE]={'\0',};
char buffer[8]={'\0',};
//char buffer2[5]={'\0',};

bool sx1272 = true;

byte receivedbytes;

enum sf_t { SF7=7, SF8, SF9, SF10, SF11, SF12 };

/*******************************************************************************
 *
 * Configure these values!
 *
 *******************************************************************************/

// SX1272 - Raspberry connections
int ssPin = 6;
int dio0  = 7;
int RST   = 0;

// Set spreading factor (SF7 - SF12)
sf_t sf = SF7;

// Set center frequency
uint32_t  freq = 868100000; // in Mhz! (868.1)

byte hello[SIZE] = {'0','0','0','2',    //tn
                    '0','0','0',            //rn   
                    '0','0','0',        //now
                    '0','0','0',             //remain sec
                    '0','1','0',        //next
                    '2',};            //checksum & null
byte hello2[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello3[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','0','0',
                    '0','0','0',
                    '0','1','0',
                    '2',};
byte hello4[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
                    
byte hello5[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','0',
                    '0','0','0',
                    '1','0','0',
                    '2',};
byte hello6[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello7[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','0',
                    '0','0','0',
                    '1','0','0',
                    '2',};
byte hello8[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello9[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '1','0','0',
                    '0','0','0',
                    '0','1','0',
                    '2',};
byte hello10[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello11[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '1','0','0',
                    '0','0','0',
                    '0','1','0',
                    '2',};
byte hello12[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello13[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','0',
                    '0','0','0',
                    '0','1','1',
                    '3',};
byte hello14[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello15[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','0',
                    '0','0','0',
                    '0','1','1',
                    '3',};
byte hello16[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello17[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello18[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '1','0','1',
                    '5',};
byte hello19[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello20[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello21[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello22[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '1','0','1',
                    '0','0','0',
                    '0','1','0',
                    '4',};
byte hello23[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello24[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello25[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello26[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','0',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello27[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello28[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello29[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello30[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello31[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello32[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '1','0','1',
                    '5',};
byte hello33[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello34[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello35[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello36[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '1','0','1',
                    '0','0','0',
                    '0','1','0',
                    '4',};
byte hello37[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello38[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};
byte hello39[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello40[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','0',
                    '0','0','0',
                    '0','1','1',
                    '4',};
byte hello41[SIZE] = {'0','0','0','2',
                    '0','0','0',
                    '0','1','1',
                    '0','0','0',
                    '0','0','0',
                    '3',};
byte hello42[SIZE] = {'0','0','0','2',
                    '0','0','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};                   
byte hello43[SIZE] = {'0','0','0','2',
                    '0','1','0',
                    '0','1','1',
                    '0','0','0',
                    '0','0','0',
                    '3',};
byte hello44[SIZE] = {'0','0','0','2',
                    '0','1','1',
                    '0','1','1',
                    '0','0','0',
                    '0','1','1',
                    '5',};

                                                            
void die(const char *s)  // packet die
{
    perror(s);
    exit(1);
}

void selectreceiver()  // 
{
    digitalWrite(ssPin, LOW);
}

void unselectreceiver()  
{
    digitalWrite(ssPin, HIGH);
}

byte readReg(byte addr)
{
    unsigned char spibuf[2]; // [0] [1]

    selectreceiver();
    spibuf[0] = addr & 0x7F;    
    spibuf[1] = 0x00;
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);
    unselectreceiver();

    return spibuf[1];
}

void writeReg(byte addr, byte value)
{
    unsigned char spibuf[2];

    spibuf[0] = addr | 0x80;
    spibuf[1] = value;
    selectreceiver();
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);

    unselectreceiver();
}

static void opmode (uint8_t mode) {
    writeReg(REG_OPMODE, (readReg(REG_OPMODE) & ~OPMODE_MASK) | mode);
}

static void opmodeLora() {
    uint8_t u = OPMODE_LORA;
    if (sx1272 == false)
        u |= 0x8;   // TBD: sx1276 high freq
    writeReg(REG_OPMODE, u);
}


void SetupLoRa()
{
    digitalWrite(RST, HIGH);
    delay(100);
    digitalWrite(RST, LOW);
    delay(100);
    byte version = readReg(REG_VERSION);
    
    if (version == 0x22) 
    {
        // sx1272
        printf("SX1272 detected, starting.\n");
        sx1272 = true;
    } 
    else 
    {
        // sx1276?
        digitalWrite(RST, LOW);
        delay(100);
        digitalWrite(RST, HIGH);
        delay(100);
        version = readReg(REG_VERSION);
        if (version == 0x12) 
        {
            // sx1276
            printf("SX1276 detected, starting.\n");
            sx1272 = false;
        } 
        else 
        {
            printf("Unrecognized transceiver.\n");
            //printf("Version: 0x%x\n",version);
            exit(1);
        }
    }

    opmode(OPMODE_SLEEP);

    // set frequency
    uint64_t frf = ((uint64_t)freq << 19) / 32000000;
    writeReg(REG_FRF_MSB, (uint8_t)(frf>>16) );
    writeReg(REG_FRF_MID, (uint8_t)(frf>> 8) );
    writeReg(REG_FRF_LSB, (uint8_t)(frf>> 0) );

    writeReg(REG_SYNC_WORD, 0x34); // LoRaWAN public sync word

    if (sx1272) 
    {
        if (sf == SF11 || sf == SF12) 
        {
            writeReg(REG_MODEM_CONFIG,0x0B);
        } 
        else 
        {
            writeReg(REG_MODEM_CONFIG,0x0A);
        }
        
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    } 
    
    else 
    {
        if (sf == SF11 || sf == SF12) 
        {
            writeReg(REG_MODEM_CONFIG3,0x0C);
        } 
        else 
        {
            writeReg(REG_MODEM_CONFIG3,0x04);
        }
        
        writeReg(REG_MODEM_CONFIG,0x72);
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    }

    if (sf == SF10 || sf == SF11 || sf == SF12) 
    {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x05);
    } 
    else 
    {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x08);
    }
    
    writeReg(REG_MAX_PAYLOAD_LENGTH,0x80);
    writeReg(REG_PAYLOAD_LENGTH,PAYLOAD_LENGTH);
    writeReg(REG_HOP_PERIOD,0xFF);
    writeReg(REG_FIFO_ADDR_PTR, readReg(REG_FIFO_RX_BASE_AD));
    writeReg(REG_LNA, LNA_MAX_GAIN);
    
}

boolean receive(char *payload) {
    // clear rxDone
    writeReg(REG_IRQ_FLAGS, 0x40);

    int irqflags = readReg(REG_IRQ_FLAGS);

    //  payload crc: 0x20
    if((irqflags & 0x20) == 0x20)
    {
        printf("CRC error\n");
        writeReg(REG_IRQ_FLAGS, 0x20);
        return false;
    } 
    else 
    {

        byte currentAddr = readReg(REG_FIFO_RX_CURRENT_ADDR);
        byte receivedCount = readReg(REG_RX_NB_BYTES);
        receivedbytes = receivedCount;
        writeReg(REG_FIFO_ADDR_PTR, currentAddr);

        for(int i = 0; i < receivedCount; i++)
        {
            payload[i] = (char)readReg(REG_FIFO);
        }
    }
    
    return true;
}

void receivepacket() {

    long int SNR;
    int rssicorr;

    if(digitalRead(dio0) == 1)
    {
        if(receive(message)) {
            byte value = readReg(REG_PKT_SNR_VALUE);
            if( value & 0x80 ) // The SNR sign bit is 1
            {
                // Invert and divide by 4
                value = ( ( ~value + 1 ) & 0xFF ) >> 2;
                SNR = -value;
            }
            else
            {
                // Divide by 4
                SNR = ( value & 0xFF ) >> 2;
            }
            
            if (sx1272) {
                rssicorr = 139;
            } else {
                rssicorr = 157;
            }
            
            //reading txt and bring infos
            FILE *fp = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt","r");
            fgets(buffer,sizeof(buffer),fp);
            fclose(fp);
            
            //checksum source : 3 6 9 15 sum compare with 16
            
            int i=0;
            int j=0;
            int k=0;
            int x=0;
            
            int sum=0;
            int checksum=0;
            
            if(message[3]=='0')
                i=0;
            else if(message[3]=='1')
                i=1;
                
            if(message[6]=='0')
                j=0;
            else if(message[6]=='1')
                j=1;
                
            if(message[9]=='0')
                k=0;
            else if(message[9]=='1')
                k=1;
                
            if(message[15]=='0')
                x=0;
            else if(message[15]=='1')
                x=1;
            
            if(message[16]=='0')
                checksum=0;
            else if(message[16]=='1')
                checksum=1;
            else if(message[16]=='2')
                checksum=2;
            else if(message[16]=='3')
                checksum=3;
            else if(message[16]=='4')
                checksum=4;
                
            sum = i+j+k+x;                
            
            
            if(checksum==sum){                      
                if(message[0]==buffer[0]&&message[1]==buffer[1]&&message[2]==buffer[2]&&message[3]==buffer[3]){ //buf: traffic0000road000
                  
                    if(message[4]==buffer[4]&&message[5]==buffer[5]&&message[6]==buffer[6]){
                
                        printf("Packet RSSI: %d, ", readReg(0x1A)-rssicorr);
                        printf("RSSI: %d, ", readReg(0x1B)-rssicorr);
                        printf("SNR: %li, ", SNR);
                        printf("Length: %i", (int)receivedbytes);
                        printf("\n");
                        printf("[receive] %s\n", message);
                        printf("TL : %c%c%c%c  RN : %c%c%c\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
                    
                        if(message[7]=='0'&&message[8]=='0'&&message[9]=='0')
                            printf("signal : 000 (green)\n");
                        else if(message[7]=='0'&&message[8]=='0'&&message[9]=='1')
                            printf("signal : 001 (green left)\n");
                        else if(message[7]=='0'&&message[8]=='1'&&message[9]=='0')
                            printf("signal : 010 (yellow)\n");
                        else if(message[7]=='0'&&message[8]=='1'&&message[9]=='1')
                            printf("signal : 011 (red)\n");
                        else if(message[7]=='1'&&message[8]=='0'&&message[9]=='0')
                            printf("signal : 100 (green X green left O)\n");
                        else if(message[7]=='1'&&message[8]=='0'&&message[9]=='1')
                            printf("signal : 101 (green O green left O)\n");
                        else
                            printf("Wrong Packet\n");
                        
                        printf("remain time : %c%c%c sec\n",message[10],message[11],message[12]);
                    
                        if(message[13]=='0'&&message[14]=='0'&&message[15]=='0')
                            printf("next signal : 000 (green)\n");
                        else if(message[13]=='0'&&message[14]=='0'&&message[15]=='1')
                            printf("next signal : 001 (green left)\n");
                        else if(message[13]=='0'&&message[14]=='1'&&message[15]=='0')
                            printf("next signal : 010 (yellow)\n");
                        else if(message[13]=='0'&&message[14]=='1'&&message[15]=='1')
                            printf("next signal : 011 (red)\n");
                        else if(message[13]=='1'&&message[14]=='0'&&message[15]=='0')
                            printf("next signal : 100 (green X green left O)\n");
                        else if(message[13]=='1'&&message[14]=='0'&&message[15]=='1')
                            printf("next signal : 101 (green O green left O)\n");
                        else
                            printf("Wrong Packet\n");
                            
                        printf("checksum : %c\n",message[16]);

                    
                    }
                    //else
                    //    printf("[rn wrong] %s\n", message);
                    
                    
                }
                //else
                //    printf("[tn wrong] %s\n", message);
                
            }
            else{
                printf("Drop Wrong Packet.\n");
                printf("[wrong receive] %s\n", message);
            }
            printf("\n");
            
        } // received a message
      
    } // dio0=1
}

static void configPower (int8_t pw) {
    if (sx1272 == false) {
        // no boost used for now
        if(pw >= 17) {
            pw = 15;
        } else if(pw < 2) {
            pw = 2;
        }
        // check board type for BOOST pin
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw&0xf)));
        writeReg(RegPaDac, readReg(RegPaDac)|0x4);

    } else {
        // set PA config (2-17 dBm using PA_BOOST)
        if(pw > 17) {
            pw = 17;
        } else if(pw < 2) {
            pw = 2;
        }
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw-2)));
    }
}


static void writeBuf(byte addr, byte *value, byte len) {                                                       
    unsigned char spibuf[256];                                                                          
    spibuf[0] = addr | 0x80;                                                                            
    for (int i = 0; i < len; i++) {                                                                         
        spibuf[i + 1] = value[i];                                                                       
    }                                                                                                   
    selectreceiver();                                                                                   
    wiringPiSPIDataRW(CHANNEL, spibuf, len + 1);                                                        
    unselectreceiver();                                                                                 
}

void txlora(byte *frame, byte datalen) {

    // set the IRQ mapping DIO0=TxDone DIO1=NOP DIO2=NOP
    writeReg(RegDioMapping1, MAP_DIO0_LORA_TXDONE|MAP_DIO1_LORA_NOP|MAP_DIO2_LORA_NOP);
    // clear all radio IRQ flags
    writeReg(REG_IRQ_FLAGS, 0xFF);
    // mask all IRQs but TxDone
    writeReg(REG_IRQ_FLAGS_MASK, ~IRQ_LORA_TXDONE_MASK);

    // initialize the payload size and address pointers
    writeReg(REG_FIFO_TX_BASE_AD, 0x00);
    writeReg(REG_FIFO_ADDR_PTR, 0x00);
    writeReg(REG_PAYLOAD_LENGTH, datalen);

    // download buffer to the radio FIFO
    writeBuf(REG_FIFO, frame, datalen);
    // now we actually start the transmission
    opmode(OPMODE_TX);

    printf("[send] %s\n", frame);
}

int main (int argc, char *argv[]) {
    
    if (argc < 2) {
        printf ("Usage: argv[0] sender|rec [message]\n");
        exit(1);
    }

    wiringPiSetup () ;
    pinMode(ssPin, OUTPUT);
    pinMode(dio0, INPUT);
    pinMode(RST, OUTPUT);

    wiringPiSPISetup(CHANNEL, 500000);

    SetupLoRa();

    if (!strcmp("sender", argv[1])) {
        opmodeLora();
        // enter standby mode (required for FIFO loading))
        opmode(OPMODE_STANDBY);

        writeReg(RegPaRamp, (readReg(RegPaRamp) & 0xF0) | 0x08); // set PA ramp-up time 50 uSec

        configPower(23);

        printf("Send packets at SF%i on %.6lf Mhz.\n", sf,(double)freq/1000000);
        printf("------------------\n");

        if (argc > 2){
            strncpy((char *)hello, argv[2], sizeof(hello));
            strncpy((char *)hello2, argv[2], sizeof(hello2));
            strncpy((char *)hello3, argv[2], sizeof(hello3));
            strncpy((char *)hello4, argv[2], sizeof(hello4));
            strncpy((char *)hello5, argv[2], sizeof(hello5));
            strncpy((char *)hello6, argv[2], sizeof(hello6));
            strncpy((char *)hello7, argv[2], sizeof(hello7));
            strncpy((char *)hello8, argv[2], sizeof(hello8));
            strncpy((char *)hello9, argv[2], sizeof(hello9));
            strncpy((char *)hello10, argv[2], sizeof(hello10));
            strncpy((char *)hello11, argv[2], sizeof(hello11));
            strncpy((char *)hello12, argv[2], sizeof(hello12));
            strncpy((char *)hello13, argv[2], sizeof(hello13));
            strncpy((char *)hello14, argv[2], sizeof(hello14));
            strncpy((char *)hello15, argv[2], sizeof(hello15));
            strncpy((char *)hello16, argv[2], sizeof(hello16));
            strncpy((char *)hello17, argv[2], sizeof(hello17));
            strncpy((char *)hello18, argv[2], sizeof(hello18));
            strncpy((char *)hello19, argv[2], sizeof(hello19));
            strncpy((char *)hello20, argv[2], sizeof(hello20));
            strncpy((char *)hello21, argv[2], sizeof(hello21));
            strncpy((char *)hello22, argv[2], sizeof(hello22));
            strncpy((char *)hello23, argv[2], sizeof(hello23));
            strncpy((char *)hello24, argv[2], sizeof(hello24));
            strncpy((char *)hello25, argv[2], sizeof(hello25));
            strncpy((char *)hello26, argv[2], sizeof(hello26));
            strncpy((char *)hello27, argv[2], sizeof(hello27));
            strncpy((char *)hello28, argv[2], sizeof(hello28));
            strncpy((char *)hello29, argv[2], sizeof(hello29));
            strncpy((char *)hello30, argv[2], sizeof(hello30));
            strncpy((char *)hello31, argv[2], sizeof(hello31));
            strncpy((char *)hello32, argv[2], sizeof(hello32));
            strncpy((char *)hello33, argv[2], sizeof(hello33));
            strncpy((char *)hello34, argv[2], sizeof(hello34));
            strncpy((char *)hello35, argv[2], sizeof(hello35));
            strncpy((char *)hello36, argv[2], sizeof(hello36));
            strncpy((char *)hello37, argv[2], sizeof(hello37));
            strncpy((char *)hello38, argv[2], sizeof(hello38));
            strncpy((char *)hello39, argv[2], sizeof(hello39));
            strncpy((char *)hello40, argv[2], sizeof(hello40));
            strncpy((char *)hello41, argv[2], sizeof(hello41));
            strncpy((char *)hello42, argv[2], sizeof(hello42));
            strncpy((char *)hello43, argv[2], sizeof(hello43));
            strncpy((char *)hello44, argv[2], sizeof(hello44));
            
        }
        
        //traffic light pattern
        byte h,i,j,k,x;
        while(1) {
            FILE* f = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f,"A");
            fclose(f);
            
            //term1
                //57~48 : 9~0 
                /////////////////////////////insert part///////////////    
                h=48;                                //insert 100 ja ri su h
                i=49;                               //insert 10 ja ri su i
                for(k=52;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////// 014sec
                    hello[10]=h;
                    hello2[10]=h;
                    hello3[10]=h;
                    hello4[10]=h;
                    hello[11]=i; 
                    hello2[11]=i;
                    hello3[11]=i;
                    hello4[11]=i;
                    hello[12]=k;
                    hello2[12]=k;
                    hello3[12]=k;
                    hello4[12]=k;

                    txlora(hello, strlen((char *)hello));
                    delay(DELAY_SIZE);
                    txlora(hello2, strlen((char *)hello2));
                    delay(DELAY_SIZE);
                    txlora(hello3, strlen((char *)hello3));
                    delay(DELAY_SIZE);
                    txlora(hello4, strlen((char *)hello4));
                    delay(DELAY_SIZE);
                    txlora(hello, strlen((char *)hello));
                    delay(DELAY_SIZE);
                    txlora(hello2, strlen((char *)hello2));
                    delay(DELAY_SIZE);
                    txlora(hello3, strlen((char *)hello3));
                    delay(DELAY_SIZE);
                    txlora(hello4, strlen((char *)hello4));
                    delay(DELAY_SIZE);
            
                    }
                    
                    //////////////////////
                    
                for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello[11]=x;
                hello2[11]=x;
                hello3[11]=x;
                hello4[11]=x;
                hello[12]=j;
                hello2[12]=j;
                hello3[12]=j;
                hello4[12]=j;

            txlora(hello, strlen((char *)hello));
            delay(DELAY_SIZE);
            txlora(hello2, strlen((char *)hello2));
            delay(DELAY_SIZE);
            txlora(hello3, strlen((char *)hello3));
            delay(DELAY_SIZE);
            txlora(hello4, strlen((char *)hello4));
            delay(DELAY_SIZE);
            txlora(hello, strlen((char *)hello));
            delay(DELAY_SIZE);
            txlora(hello2, strlen((char *)hello2));
            delay(DELAY_SIZE);
            txlora(hello3, strlen((char *)hello3));
            delay(DELAY_SIZE);
            txlora(hello4, strlen((char *)hello4));
            delay(DELAY_SIZE);
            
            }
            
            
           FILE* f1 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f1,"B");
            fclose(f1); 
            
            //term2
          //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello5[10]=h;
                    hello6[10]=h;
                    hello7[10]=h;
                    hello8[10]=h;
                    hello5[11]=i; //this is 14sec
                    hello6[11]=i;
                    hello7[11]=i;
                    hello8[11]=i;
                    hello5[12]=k;
                    hello6[12]=k;
                    hello7[12]=k;
                    hello8[12]=k;
                    
            txlora(hello5, strlen((char *)hello5));
            delay(DELAY_SIZE);
            txlora(hello6, strlen((char *)hello6));
            delay(DELAY_SIZE);
            txlora(hello7, strlen((char *)hello7));
            delay(DELAY_SIZE);
            txlora(hello8, strlen((char *)hello8));
            delay(DELAY_SIZE);
            txlora(hello5, strlen((char *)hello5));
            delay(DELAY_SIZE);
            txlora(hello6, strlen((char *)hello6));
            delay(DELAY_SIZE);
            txlora(hello7, strlen((char *)hello7));
            delay(DELAY_SIZE);
            txlora(hello8, strlen((char *)hello8));
            delay(DELAY_SIZE);
            
                    }
             for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello5[11]=x;
                hello6[11]=x;
                hello7[11]=x;
                hello8[11]=x;
                hello5[12]=j;
                hello6[12]=j;
                hello7[12]=j;
                hello8[12]=j;
                
             txlora(hello5, strlen((char *)hello5));
            delay(DELAY_SIZE);
            txlora(hello6, strlen((char *)hello6));
            delay(DELAY_SIZE);
            txlora(hello7, strlen((char *)hello7));
            delay(DELAY_SIZE);
            txlora(hello8, strlen((char *)hello8));
            delay(DELAY_SIZE);
            txlora(hello5, strlen((char *)hello5));
            delay(DELAY_SIZE);
            txlora(hello6, strlen((char *)hello6));
            delay(DELAY_SIZE);
            txlora(hello7, strlen((char *)hello7));
            delay(DELAY_SIZE);
            txlora(hello8, strlen((char *)hello8));
            
            }
            
            
            FILE* f2 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f2,"C");
            fclose(f2);
            
            
            //term3
               //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=49;                               //insert 10 ja ri su i
                for(k=52;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello9[10]=h;
                    hello10[10]=h;
                    hello11[10]=h;
                    hello12[10]=h;
                    hello9[11]=i; //this is 14sec
                    hello10[11]=i;
                    hello11[11]=i;
                    hello12[11]=i;
                    hello9[12]=k;
                    hello10[12]=k;
                    hello11[12]=k;
                    hello12[12]=k;
                    
            txlora(hello9, strlen((char *)hello9));
            delay(DELAY_SIZE);
            txlora(hello10, strlen((char *)hello10));
            delay(DELAY_SIZE);
            txlora(hello11, strlen((char *)hello11));
            delay(DELAY_SIZE);
            txlora(hello12, strlen((char *)hello12));
            delay(DELAY_SIZE);
            txlora(hello9, strlen((char *)hello9));
            delay(DELAY_SIZE);
            txlora(hello10, strlen((char *)hello10));
            delay(DELAY_SIZE);
            txlora(hello11, strlen((char *)hello11));
            delay(DELAY_SIZE);
            txlora(hello12, strlen((char *)hello12));
            delay(DELAY_SIZE);
            }
              for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello9[11]=x;
                hello10[11]=x;
                hello11[11]=x;
                hello12[11]=x;
                hello9[12]=j;
                hello10[12]=j;
                hello11[12]=j;
                hello12[12]=j;
             txlora(hello9, strlen((char *)hello9));
            delay(DELAY_SIZE);
            txlora(hello10, strlen((char *)hello10));
            delay(DELAY_SIZE);
            txlora(hello11, strlen((char *)hello11));
            delay(DELAY_SIZE);
            txlora(hello12, strlen((char *)hello12));
            delay(DELAY_SIZE);
            txlora(hello9, strlen((char *)hello9));
            delay(DELAY_SIZE);
            txlora(hello10, strlen((char *)hello10));
            delay(DELAY_SIZE);
            txlora(hello11, strlen((char *)hello11));
            delay(DELAY_SIZE);
            txlora(hello12, strlen((char *)hello12));
            delay(DELAY_SIZE);
            }
            
            FILE* f3 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f3,"D");
            fclose(f3);
            
            //term4
            
             //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello13[10]=h;
                    hello14[10]=h;
                    hello15[10]=h;
                    hello16[10]=h;
                    hello13[11]=i; //this is 14sec
                    hello14[11]=i;
                    hello15[11]=i;
                    hello16[11]=i;
                    hello13[12]=k;
                    hello14[12]=k;
                    hello15[12]=k;
                    hello16[12]=k;
                    
            txlora(hello13, strlen((char *)hello13));
            delay(DELAY_SIZE);
            txlora(hello14, strlen((char *)hello14));
            delay(DELAY_SIZE);
            txlora(hello15, strlen((char *)hello15));
            delay(DELAY_SIZE);
            txlora(hello16, strlen((char *)hello16));
            delay(DELAY_SIZE);
            txlora(hello13, strlen((char *)hello13));
            delay(DELAY_SIZE);
            txlora(hello14, strlen((char *)hello14));
            delay(DELAY_SIZE);
            txlora(hello15, strlen((char *)hello15));
            delay(DELAY_SIZE);
            txlora(hello16, strlen((char *)hello16));
            delay(DELAY_SIZE);
            }
            
            for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello13[11]=x;
                hello14[11]=x;
                hello15[11]=x;
                hello16[11]=x;
                hello13[12]=j;
                hello14[12]=j;
                hello15[12]=j;
                hello16[12]=j;
                
              txlora(hello13, strlen((char *)hello13));
            delay(DELAY_SIZE);
            txlora(hello14, strlen((char *)hello14));
            delay(DELAY_SIZE);
            txlora(hello15, strlen((char *)hello15));
            delay(DELAY_SIZE);
            txlora(hello16, strlen((char *)hello16));
            delay(DELAY_SIZE);
            txlora(hello13, strlen((char *)hello13));
            delay(DELAY_SIZE);
            txlora(hello14, strlen((char *)hello14));
            delay(DELAY_SIZE);
            txlora(hello15, strlen((char *)hello15));
            delay(DELAY_SIZE);
            txlora(hello16, strlen((char *)hello16));
            delay(DELAY_SIZE);
            }
            
            FILE* f4 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f4,"E");
            fclose(f4);
            //term5
           //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello17[10]=h;
                    hello18[10]=h;
                    hello19[10]=h;
                    hello20[10]=h;
                    hello17[11]=i; //this is 14sec
                    hello18[11]=i;
                    hello19[11]=i;
                    hello20[11]=i;
                    hello17[12]=k;
                    hello18[12]=k;
                    hello19[12]=k;
                    hello20[12]=k;
                    
            txlora(hello17, strlen((char *)hello17));
            delay(DELAY_SIZE);
            txlora(hello18, strlen((char *)hello18));
            delay(DELAY_SIZE);
            txlora(hello19, strlen((char *)hello19));
            delay(DELAY_SIZE);
            txlora(hello20, strlen((char *)hello20));
            delay(DELAY_SIZE);
            txlora(hello17, strlen((char *)hello17));
            delay(DELAY_SIZE);
            txlora(hello18, strlen((char *)hello18));
            delay(DELAY_SIZE);
            txlora(hello19, strlen((char *)hello19));
            delay(DELAY_SIZE);
            txlora(hello20, strlen((char *)hello20));
            delay(DELAY_SIZE);
            }
            
               for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello17[11]=x;
                hello18[11]=x;
                hello19[11]=x;
                hello20[11]=x;
                hello17[12]=j;
                hello18[12]=j;
                hello19[12]=j;
                hello20[12]=j;
                
                 txlora(hello17, strlen((char *)hello17));
            delay(DELAY_SIZE);
            txlora(hello18, strlen((char *)hello18));
            delay(DELAY_SIZE);
            txlora(hello19, strlen((char *)hello19));
            delay(DELAY_SIZE);
            txlora(hello20, strlen((char *)hello20));
            delay(DELAY_SIZE);
            txlora(hello17, strlen((char *)hello17));
            delay(DELAY_SIZE);
            txlora(hello18, strlen((char *)hello18));
            delay(DELAY_SIZE);
            txlora(hello19, strlen((char *)hello19));
            delay(DELAY_SIZE);
            txlora(hello20, strlen((char *)hello20));
            delay(DELAY_SIZE);
            }
            
            
            FILE* f5 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f5,"F");
            fclose(f5);
            //term6
        //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=49;                               //insert 10 ja ri su i
                for(k=52;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello21[10]=h;
                    hello22[10]=h;
                    hello23[10]=h;
                    hello24[10]=h;
                    hello21[11]=i; //this is 14sec
                    hello22[11]=i;
                    hello23[11]=i;
                    hello24[11]=i;
                    hello21[12]=k;
                    hello22[12]=k;
                    hello23[12]=k;
                    hello24[12]=k;
                    
            txlora(hello21, strlen((char *)hello21));
            delay(DELAY_SIZE);
            txlora(hello22, strlen((char *)hello22));
            delay(DELAY_SIZE);
            txlora(hello23, strlen((char *)hello23));
            delay(DELAY_SIZE);
            txlora(hello24, strlen((char *)hello24));
            delay(DELAY_SIZE);
            txlora(hello21, strlen((char *)hello21));
            delay(DELAY_SIZE);
            txlora(hello22, strlen((char *)hello22));
            delay(DELAY_SIZE);
            txlora(hello23, strlen((char *)hello23));
            delay(DELAY_SIZE);
            txlora(hello24, strlen((char *)hello24));
            delay(DELAY_SIZE);
            }
            
                for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello21[11]=x;
                hello22[11]=x;
                hello23[11]=x;
                hello24[11]=x;
                hello21[12]=j;
                hello22[12]=j;
                hello23[12]=j;
                hello24[12]=j;
                
               txlora(hello21, strlen((char *)hello21));
            delay(DELAY_SIZE);
            txlora(hello22, strlen((char *)hello22));
            delay(DELAY_SIZE);
            txlora(hello23, strlen((char *)hello23));
            delay(DELAY_SIZE);
            txlora(hello24, strlen((char *)hello24));
            delay(DELAY_SIZE);
            txlora(hello21, strlen((char *)hello21));
            delay(DELAY_SIZE);
            txlora(hello22, strlen((char *)hello22));
            delay(DELAY_SIZE);
            txlora(hello23, strlen((char *)hello23));
            delay(DELAY_SIZE);
            txlora(hello24, strlen((char *)hello24));
            delay(DELAY_SIZE);
            }
            
            FILE* f6 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f6,"G");
            fclose(f6);
            //term7
       //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello25[10]=h;
                    hello26[10]=h;
                    hello27[10]=h;
                    hello28[10]=h;
                    hello25[11]=i; //this is 14sec
                    hello26[11]=i;
                    hello27[11]=i;
                    hello28[11]=i;
                    hello25[12]=k;
                    hello26[12]=k;
                    hello27[12]=k;
                    hello28[12]=k;
                    
                    
            txlora(hello25, strlen((char *)hello25));
            delay(DELAY_SIZE);
            txlora(hello26, strlen((char *)hello26));
            delay(DELAY_SIZE);
            txlora(hello27, strlen((char *)hello27));
            delay(DELAY_SIZE);
            txlora(hello28, strlen((char *)hello28));
            delay(DELAY_SIZE);
            txlora(hello25, strlen((char *)hello25));
            delay(DELAY_SIZE);
            txlora(hello26, strlen((char *)hello26));
            delay(DELAY_SIZE);
            txlora(hello27, strlen((char *)hello27));
            delay(DELAY_SIZE);
            txlora(hello28, strlen((char *)hello28));
            delay(DELAY_SIZE);
            }
                 for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello25[11]=x;
                hello26[11]=x;
                hello27[11]=x;
                hello28[11]=x;
                hello25[12]=j;
                hello26[12]=j;
                hello27[12]=j;
                hello28[12]=j;
            
            txlora(hello25, strlen((char *)hello25));
            delay(DELAY_SIZE);
            txlora(hello26, strlen((char *)hello26));
            delay(DELAY_SIZE);
            txlora(hello27, strlen((char *)hello27));
            delay(DELAY_SIZE);
            txlora(hello28, strlen((char *)hello28));
            delay(DELAY_SIZE);
            txlora(hello25, strlen((char *)hello25));
            delay(DELAY_SIZE);
            txlora(hello26, strlen((char *)hello26));
            delay(DELAY_SIZE);
            txlora(hello27, strlen((char *)hello27));
            delay(DELAY_SIZE);
            txlora(hello28, strlen((char *)hello28));
            delay(DELAY_SIZE);
            }
            
            FILE* f7 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f7,"H");
            fclose(f7);
            //term8
            //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello29[10]=h;
                    hello30[10]=h;
                    hello31[10]=h;
                    hello32[10]=h;
                    hello29[11]=i; //this is 14sec
                    hello30[11]=i;
                    hello31[11]=i;
                    hello32[11]=i;
                    hello29[12]=k;
                    hello30[12]=k;
                    hello31[12]=k;
                    hello32[12]=k;
                    
                    
            txlora(hello29, strlen((char *)hello29));
            delay(DELAY_SIZE);
            txlora(hello30, strlen((char *)hello30));
            delay(DELAY_SIZE);
            txlora(hello31, strlen((char *)hello31));
            delay(DELAY_SIZE);
            txlora(hello32, strlen((char *)hello32));
            delay(DELAY_SIZE);
            txlora(hello29, strlen((char *)hello29));
            delay(DELAY_SIZE);
            txlora(hello30, strlen((char *)hello30));
            delay(DELAY_SIZE);
            txlora(hello31, strlen((char *)hello31));
            delay(DELAY_SIZE);
            txlora(hello32, strlen((char *)hello32));
            delay(DELAY_SIZE);
            }
            for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello29[11]=x;
                hello30[11]=x;
                hello31[11]=x;
                hello32[11]=x;
                hello29[12]=j;
                hello30[12]=j;
                hello31[12]=j;
                hello32[12]=j;
             txlora(hello29, strlen((char *)hello29));
            delay(DELAY_SIZE);
            txlora(hello30, strlen((char *)hello30));
            delay(DELAY_SIZE);
            txlora(hello31, strlen((char *)hello31));
            delay(DELAY_SIZE);
            txlora(hello32, strlen((char *)hello32));
            delay(DELAY_SIZE);
            txlora(hello29, strlen((char *)hello29));
            delay(DELAY_SIZE);
            txlora(hello30, strlen((char *)hello30));
            delay(DELAY_SIZE);
            txlora(hello31, strlen((char *)hello31));
            delay(DELAY_SIZE);
            txlora(hello32, strlen((char *)hello32));
            delay(DELAY_SIZE);
            }
            
            FILE* f8 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f8,"I");
            fclose(f8);
            //term9
         //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=49;                               //insert 10 ja ri su i
                for(k=52;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello33[10]=h;
                    hello34[10]=h;
                    hello35[10]=h;
                    hello36[10]=h;
                    hello33[11]=i; //this is 14sec
                    hello34[11]=i;
                    hello35[11]=i;
                    hello36[11]=i;
                    hello33[12]=k;
                    hello34[12]=k;
                    hello35[12]=k;
                    hello36[12]=k;
                    
            txlora(hello33, strlen((char *)hello33));
            delay(DELAY_SIZE);
            txlora(hello34, strlen((char *)hello34));
            delay(DELAY_SIZE);
            txlora(hello35, strlen((char *)hello35));
            delay(DELAY_SIZE);
            txlora(hello36, strlen((char *)hello36));
            delay(DELAY_SIZE);
            txlora(hello33, strlen((char *)hello33));
            delay(DELAY_SIZE);
            txlora(hello34, strlen((char *)hello34));
            delay(DELAY_SIZE);
            txlora(hello35, strlen((char *)hello35));
            delay(DELAY_SIZE);
            txlora(hello36, strlen((char *)hello36));
            delay(DELAY_SIZE);
            }       
              for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello33[11]=x;
                hello34[11]=x;
                hello35[11]=x;
                hello36[11]=x;
                hello33[12]=j;
                hello34[12]=j;
                hello35[12]=j;
                hello36[12]=j;
             txlora(hello33, strlen((char *)hello33));
            delay(DELAY_SIZE);
            txlora(hello34, strlen((char *)hello34));
            delay(DELAY_SIZE);
            txlora(hello35, strlen((char *)hello35));
            delay(DELAY_SIZE);
            txlora(hello36, strlen((char *)hello36));
            delay(DELAY_SIZE);
            txlora(hello33, strlen((char *)hello33));
            delay(DELAY_SIZE);
            txlora(hello34, strlen((char *)hello34));
            delay(DELAY_SIZE);
            txlora(hello35, strlen((char *)hello35));
            delay(DELAY_SIZE);
            txlora(hello36, strlen((char *)hello36));
            delay(DELAY_SIZE);
            }     
            
            FILE* f9 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f9,"J");
            fclose(f9);
            //term10
         //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello37[10]=h;
                    hello38[10]=h;
                    hello39[10]=h;
                    hello40[10]=h;
                    hello37[11]=i; //this is 14sec
                    hello38[11]=i;
                    hello39[11]=i;
                    hello40[11]=i;
                    hello37[12]=k;
                    hello38[12]=k;
                    hello39[12]=k;
                    hello40[12]=k;
                    
            txlora(hello37, strlen((char *)hello37));
            delay(DELAY_SIZE);
            txlora(hello38, strlen((char *)hello38));
            delay(DELAY_SIZE);
            txlora(hello39, strlen((char *)hello39));
            delay(DELAY_SIZE);
            txlora(hello40, strlen((char *)hello40));
            delay(DELAY_SIZE);
            txlora(hello37, strlen((char *)hello37));
            delay(DELAY_SIZE);
            txlora(hello38, strlen((char *)hello38));
            delay(DELAY_SIZE);
            txlora(hello39, strlen((char *)hello39));
            delay(DELAY_SIZE);
            txlora(hello40, strlen((char *)hello40));
            delay(DELAY_SIZE);
            }
            for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello37[11]=x;
                hello38[11]=x;
                hello39[11]=x;
                hello40[11]=x;
                hello37[12]=j;
                hello38[12]=j;
                hello39[12]=j;
                hello40[12]=j;
            txlora(hello37, strlen((char *)hello37));
            delay(DELAY_SIZE);
            txlora(hello38, strlen((char *)hello38));
            delay(DELAY_SIZE);
            txlora(hello39, strlen((char *)hello39));
            delay(DELAY_SIZE);
            txlora(hello40, strlen((char *)hello40));
            delay(DELAY_SIZE);
            txlora(hello37, strlen((char *)hello37));
            delay(DELAY_SIZE);
            txlora(hello38, strlen((char *)hello38));
            delay(DELAY_SIZE);
            txlora(hello39, strlen((char *)hello39));
            delay(DELAY_SIZE);
            txlora(hello40, strlen((char *)hello40));
            delay(DELAY_SIZE);
            }
            
            FILE* f10 = fopen("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt","w");
            fprintf(f10,"K");
            fclose(f10);
            //term11
                 //57~48 : 9~0 
                /////////////////////////////insert part///////////////     
                h=48;
                i=48;                               //insert 10 ja ri su i
                for(k=50;k>47;k--){                 //insert 1 ja ri su k
                ////////////////////////////////////////////////////////
                    hello41[10]=h;
                    hello42[10]=h;
                    hello43[10]=h;
                    hello44[10]=h;
                    hello41[11]=i; //this is 14sec
                    hello42[11]=i;
                    hello43[11]=i;
                    hello44[11]=i;
                    hello41[12]=k;
                    hello42[12]=k;
                    hello43[12]=k;
                    hello44[12]=k;
                    
            txlora(hello41, strlen((char *)hello41));
            delay(DELAY_SIZE);
            txlora(hello42, strlen((char *)hello42));
            delay(DELAY_SIZE);
            txlora(hello43, strlen((char *)hello43));
            delay(DELAY_SIZE);
            txlora(hello44, strlen((char *)hello44));
            delay(DELAY_SIZE);
            txlora(hello41, strlen((char *)hello41));
            delay(DELAY_SIZE);
            txlora(hello42, strlen((char *)hello42));
            delay(DELAY_SIZE);
            txlora(hello43, strlen((char *)hello43));
            delay(DELAY_SIZE);
            txlora(hello44, strlen((char *)hello44));
            delay(DELAY_SIZE);
            }
                for(x=i-1;x>47;x--)//general 10 1 counter part
                for(j=57;j>47;j--){
                
                hello41[11]=x;
                hello42[11]=x;
                hello43[11]=x;
                hello44[11]=x;
                hello41[12]=j;
                hello42[12]=j;
                hello43[12]=j;
                hello44[12]=j;
            txlora(hello41, strlen((char *)hello41));
            delay(DELAY_SIZE);
            txlora(hello42, strlen((char *)hello42));
            delay(DELAY_SIZE);
            txlora(hello43, strlen((char *)hello43));
            delay(DELAY_SIZE);
            txlora(hello44, strlen((char *)hello44));
            delay(DELAY_SIZE);
            txlora(hello41, strlen((char *)hello41));
            delay(DELAY_SIZE);
            txlora(hello42, strlen((char *)hello42));
            delay(DELAY_SIZE);
            txlora(hello43, strlen((char *)hello43));
            delay(DELAY_SIZE);
            txlora(hello44, strlen((char *)hello44));
            delay(DELAY_SIZE);
            }
            
        }
    
    } else {

        // radio init
        opmodeLora();
        opmode(OPMODE_STANDBY);
        opmode(OPMODE_RX);
        printf("Listening at SF%i on %.6lf Mhz.\n", sf,(double)freq/1000000);
        printf("------------------\n");
        while(1) {
            receivepacket(); 
            delay(1);
        }

    }

    return (0);
}
