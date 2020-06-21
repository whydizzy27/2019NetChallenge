#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN3        3 
#define PIN4        4 
#define PIN5        5 
#define PIN6        6 

#define PIN7        7 
#define PIN8        8 
#define PIN9        9 
#define PIN10        10 

#define PIN11        11 
#define PIN12        12 
#define PIN13        13 
#define PIN14        14

#define PIN15        15 
#define PIN16        16 
#define PIN17        17 
#define PIN18        18 
 



#define NUMPIXELS 24 // 연결된 LED 갯수
#define LEFTNUMPIXELS 14 

#define OFF 0

#define DELAYVAL 500 

//  standard   :  Red , Yellow , Left , Green

Adafruit_NeoPixel pixels3(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800); //red
Adafruit_NeoPixel pixels4(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800); //yellow
Adafruit_NeoPixel pixels5(LEFTNUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800); //left
Adafruit_NeoPixel pixels6(NUMPIXELS, PIN6, NEO_GRB + NEO_KHZ800); // green

Adafruit_NeoPixel pixels7(NUMPIXELS, PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels8(NUMPIXELS, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels9(LEFTNUMPIXELS, PIN9, NEO_GRB + NEO_KHZ800); //left
Adafruit_NeoPixel pixels10(NUMPIXELS, PIN10, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels11(NUMPIXELS, PIN11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels12(NUMPIXELS, PIN12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels13(LEFTNUMPIXELS, PIN13, NEO_GRB + NEO_KHZ800); //left
Adafruit_NeoPixel pixels14(NUMPIXELS, PIN14, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels15(NUMPIXELS, PIN15, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels16(NUMPIXELS, PIN16, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels17(LEFTNUMPIXELS, PIN17, NEO_GRB + NEO_KHZ800); //left
Adafruit_NeoPixel pixels18(NUMPIXELS, PIN18, NEO_GRB + NEO_KHZ800);






void setup() {
  Serial.begin(9600);
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels3.begin();
  pixels4.begin(); 
  pixels5.begin();
  pixels6.begin();
  
  pixels7.begin();
  pixels8.begin(); 
  pixels9.begin();
  pixels10.begin();
  
  pixels11.begin();
  pixels12.begin(); 
  pixels13.begin();
  pixels14.begin();
  
  pixels15.begin();
  pixels16.begin(); 
  pixels17.begin();
  pixels18.begin();
}

//RGB

void red3(){
   pixels3.setPixelColor(0, pixels3.Color(150, 0, 0));
   pixels3.setPixelColor(1, pixels3.Color(150, 0, 0));
   pixels3.setPixelColor(2, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(3, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(4, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(5, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(6, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(7, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(8, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(9, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(10, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(11, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(12, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(13, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(14, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(15, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(16, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(17, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(18, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(19, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(20, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(21, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(22, pixels3.Color(150, 0, 0)); 
   pixels3.setPixelColor(23, pixels3.Color(150, 0, 0));
}

void yellow4(){
   pixels4.setPixelColor(0, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(1, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(2, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(3, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(4, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(5, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(6, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(7, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(8, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(9, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(10, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(11, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(12, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(13, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(14, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(15, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(16, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(17, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(18, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(19, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(20, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(21, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(22, pixels4.Color(180,70 , 0)); 
   pixels4.setPixelColor(23, pixels4.Color(180,70 , 0)); 
}


void left5(){
   pixels5.setPixelColor(0, pixels5.Color(0, 150, 0));
   pixels5.setPixelColor(1, pixels5.Color(0, 150, 0));
   pixels5.setPixelColor(2, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(3, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(4, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(5, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(6, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(7, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(8, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(9, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(10, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(11, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(12, pixels5.Color(0, 150, 0)); 
   pixels5.setPixelColor(13, pixels5.Color(0, 150, 0)); 
   
}

void green6(){
   pixels6.setPixelColor(0, pixels6.Color(0, 150, 0));
   pixels6.setPixelColor(1, pixels6.Color(0, 150, 0));
   pixels6.setPixelColor(2, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(3, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(4, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(5, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(6, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(7, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(8, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(9, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(10, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(11, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(12, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(13, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(14, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(15, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(16, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(17, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(18, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(19, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(20, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(21, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(22, pixels6.Color(0, 150, 0)); 
   pixels6.setPixelColor(23, pixels6.Color(0, 150, 0));
}


void red7(){
   pixels7.setPixelColor(0, pixels7.Color(150, 0, 0));
   pixels7.setPixelColor(1, pixels7.Color(150, 0, 0));
   pixels7.setPixelColor(2, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(3, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(4, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(5, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(6, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(7, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(8, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(9, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(10, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(11, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(12, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(13, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(14, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(15, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(16, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(17, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(18, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(19, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(20, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(21, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(22, pixels7.Color(150, 0, 0)); 
   pixels7.setPixelColor(23, pixels7.Color(150, 0, 0));
}


void yellow8(){
   pixels8.setPixelColor(0, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(1, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(2, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(3, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(4, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(5, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(6, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(7, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(8, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(9, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(10, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(11, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(12, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(13, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(14, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(15, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(16, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(17, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(18, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(19, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(20, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(21, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(22, pixels8.Color(180,70 , 0)); 
   pixels8.setPixelColor(23, pixels8.Color(180,70 , 0)); 
}


void left9(){
   pixels9.setPixelColor(0, pixels9.Color(0, 150, 0));
   pixels9.setPixelColor(1, pixels9.Color(0, 150, 0));
   pixels9.setPixelColor(2, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(3, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(4, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(5, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(6, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(7, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(8, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(9, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(10, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(11, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(12, pixels9.Color(0, 150, 0)); 
   pixels9.setPixelColor(13, pixels9.Color(0, 150, 0)); 
   
}

void green10(){
   pixels10.setPixelColor(0, pixels10.Color(0, 150, 0));
   pixels10.setPixelColor(1, pixels10.Color(0, 150, 0));
   pixels10.setPixelColor(2, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(3, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(4, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(5, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(6, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(7, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(8, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(9, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(10, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(11, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(12, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(13, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(14, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(15, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(16, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(17, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(18, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(19, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(20, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(21, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(22, pixels10.Color(0, 150, 0)); 
   pixels10.setPixelColor(23, pixels10.Color(0, 150, 0));
}
void red11(){
   pixels11.setPixelColor(0, pixels11.Color(150, 0, 0));
   pixels11.setPixelColor(1, pixels11.Color(150, 0, 0));
   pixels11.setPixelColor(2, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(3, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(4, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(5, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(6, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(7, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(8, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(9, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(10, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(11, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(12, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(13, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(14, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(15, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(16, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(17, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(18, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(19, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(20, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(21, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(22, pixels11.Color(150, 0, 0)); 
   pixels11.setPixelColor(23, pixels11.Color(150, 0, 0));
}

void yellow12(){
   pixels12.setPixelColor(0, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(1, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(2, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(3, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(4, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(5, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(6, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(7, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(8, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(9, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(10, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(11, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(12, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(13, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(14, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(15, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(16, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(17, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(18, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(19, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(20, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(21, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(22, pixels12.Color(180,70 , 0)); 
   pixels12.setPixelColor(23, pixels12.Color(180,70 , 0)); 
}


void left13(){
   pixels13.setPixelColor(0, pixels13.Color(0, 150, 0));
   pixels13.setPixelColor(1, pixels13.Color(0, 150, 0));
   pixels13.setPixelColor(2, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(3, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(4, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(5, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(6, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(7, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(8, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(9, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(10, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(11, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(12, pixels13.Color(0, 150, 0)); 
   pixels13.setPixelColor(13, pixels13.Color(0, 150, 0)); 
   
}

void green14(){
   pixels14.setPixelColor(0, pixels14.Color(0, 150, 0));
   pixels14.setPixelColor(1, pixels14.Color(0, 150, 0));
   pixels14.setPixelColor(2, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(3, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(4, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(5, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(6, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(7, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(8, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(9, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(10, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(11, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(12, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(13, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(14, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(15, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(16, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(17, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(18, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(19, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(20, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(21, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(22, pixels14.Color(0, 150, 0)); 
   pixels14.setPixelColor(23, pixels14.Color(0, 150, 0));
}
void red15(){
   pixels15.setPixelColor(0, pixels15.Color(150, 0, 0));
   pixels15.setPixelColor(1, pixels15.Color(150, 0, 0));
   pixels15.setPixelColor(2, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(3, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(4, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(5, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(6, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(7, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(8, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(9, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(10, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(11, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(12, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(13, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(14, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(15, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(16, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(17, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(18, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(19, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(20, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(21, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(22, pixels15.Color(150, 0, 0)); 
   pixels15.setPixelColor(23, pixels15.Color(150, 0, 0));
}

void yellow16(){
   pixels16.setPixelColor(0, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(1, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(2, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(3, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(4, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(5, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(6, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(7, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(8, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(9, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(10, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(11, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(12, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(13, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(14, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(15, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(16, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(17, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(18, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(19, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(20, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(21, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(22, pixels16.Color(180,70 , 0)); 
   pixels16.setPixelColor(23, pixels16.Color(180,70 , 0)); 
}


void left17(){
   pixels17.setPixelColor(0, pixels17.Color(0, 150, 0));
   pixels17.setPixelColor(1, pixels17.Color(0, 150, 0));
   pixels17.setPixelColor(2, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(3, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(4, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(5, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(6, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(7, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(8, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(9, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(10, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(11, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(12, pixels17.Color(0, 150, 0)); 
   pixels17.setPixelColor(13, pixels17.Color(0, 150, 0)); 
   
}

void green18(){
     pixels18.setPixelColor(0, pixels18.Color(0, 150, 0));
   pixels18.setPixelColor(1, pixels18.Color(0, 150, 0));
   pixels18.setPixelColor(2, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(3, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(4, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(5, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(6, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(7, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(8, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(9, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(10, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(11, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(12, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(13, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(14, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(15, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(16, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(17, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(18, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(19, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(20, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(21, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(22, pixels18.Color(0, 150, 0)); 
   pixels18.setPixelColor(23, pixels18.Color(0, 150, 0));
}


///////////////////////////////////////////////////////////////////
void ledoff3(){
  pixels3.setPixelColor(0, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(1, pixels3.Color(0,OFF, 0));  
  pixels3.setPixelColor(2, pixels3.Color(0, OFF, 0)); 
  pixels3.setPixelColor(3, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(4, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(5, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(6, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(7, pixels3.Color(0, OFF, 0)); 
  pixels3.setPixelColor(8, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(9, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(10, pixels3.Color(0, OFF, 0)); 
  pixels3.setPixelColor(11, pixels3.Color(0, OFF, 0));
  pixels3.setPixelColor(12, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(13, pixels3.Color(0, OFF, 0));
  pixels3.setPixelColor(14, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(15, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(16, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(17, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(18, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(19, pixels3.Color(0, OFF, 0)); 
  pixels3.setPixelColor(20, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(21, pixels3.Color(0, OFF, 0));  
  pixels3.setPixelColor(22, pixels3.Color(0, OFF, 0)); 
  pixels3.setPixelColor(23, pixels3.Color(0, OFF, 0));    
}


void ledoff4(){
  pixels4.setPixelColor(0, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(1, pixels4.Color(0,OFF, 0));  
  pixels4.setPixelColor(2, pixels4.Color(0, OFF, 0)); 
  pixels4.setPixelColor(3, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(4, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(5, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(6, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(7, pixels4.Color(0, OFF, 0)); 
  pixels4.setPixelColor(8, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(9, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(10, pixels4.Color(0, OFF, 0)); 
  pixels4.setPixelColor(11, pixels4.Color(0, OFF, 0));
  pixels4.setPixelColor(12, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(13, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(14, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(15, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(16, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(17, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(18, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(19, pixels4.Color(0, OFF, 0)); 
  pixels4.setPixelColor(20, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(21, pixels4.Color(0, OFF, 0));  
  pixels4.setPixelColor(22, pixels4.Color(0, OFF, 0)); 
  pixels4.setPixelColor(23, pixels4.Color(0, OFF, 0));  
}

void ledoff5(){
  pixels5.setPixelColor(0, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(1, pixels5.Color(0,OFF, 0));  
  pixels5.setPixelColor(2, pixels5.Color(0, OFF, 0)); 
  pixels5.setPixelColor(3, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(4, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(5, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(6, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(7, pixels5.Color(0, OFF, 0)); 
  pixels5.setPixelColor(8, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(9, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(10, pixels5.Color(0, OFF, 0)); 
  pixels5.setPixelColor(11, pixels5.Color(0, OFF, 0));
  pixels5.setPixelColor(12, pixels5.Color(0, OFF, 0));  
  pixels5.setPixelColor(13, pixels5.Color(0, OFF, 0));  
  
}

void ledoff6(){
  pixels6.setPixelColor(0, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(1, pixels6.Color(0,OFF, 0));  
  pixels6.setPixelColor(2, pixels6.Color(0, OFF, 0)); 
  pixels6.setPixelColor(3, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(4, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(5, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(6, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(7, pixels6.Color(0, OFF, 0)); 
  pixels6.setPixelColor(8, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(9, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(10, pixels6.Color(0, OFF, 0)); 
  pixels6.setPixelColor(11, pixels6.Color(0, OFF, 0));
  pixels6.setPixelColor(12, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(13, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(14, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(15, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(16, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(17, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(18, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(19, pixels6.Color(0, OFF, 0)); 
  pixels6.setPixelColor(20, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(21, pixels6.Color(0, OFF, 0));  
  pixels6.setPixelColor(22, pixels6.Color(0, OFF, 0)); 
  pixels6.setPixelColor(23, pixels6.Color(0, OFF, 0));  
}



void ledoff7(){
   pixels7.setPixelColor(0, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(1, pixels7.Color(0,OFF, 0));  
  pixels7.setPixelColor(2, pixels7.Color(0, OFF, 0)); 
  pixels7.setPixelColor(3, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(4, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(5, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(6, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(7, pixels7.Color(0, OFF, 0)); 
  pixels7.setPixelColor(8, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(9, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(10, pixels7.Color(0, OFF, 0)); 
  pixels7.setPixelColor(11, pixels7.Color(0, OFF, 0));
  pixels7.setPixelColor(12, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(13, pixels7.Color(0, OFF, 0));
  pixels7.setPixelColor(14, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(15, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(16, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(17, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(18, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(19, pixels7.Color(0, OFF, 0)); 
  pixels7.setPixelColor(20, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(21, pixels7.Color(0, OFF, 0));  
  pixels7.setPixelColor(22, pixels7.Color(0, OFF, 0)); 
  pixels7.setPixelColor(23, pixels7.Color(0, OFF, 0));   
}


void ledoff8(){
   pixels8.setPixelColor(0, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(1, pixels8.Color(0,OFF, 0));  
  pixels8.setPixelColor(2, pixels8.Color(0, OFF, 0)); 
  pixels8.setPixelColor(3, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(4, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(5, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(6, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(7, pixels8.Color(0, OFF, 0)); 
  pixels8.setPixelColor(8, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(9, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(10, pixels8.Color(0, OFF, 0)); 
  pixels8.setPixelColor(11, pixels8.Color(0, OFF, 0));
  pixels8.setPixelColor(12, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(13, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(14, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(15, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(16, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(17, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(18, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(19, pixels8.Color(0, OFF, 0)); 
  pixels8.setPixelColor(20, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(21, pixels8.Color(0, OFF, 0));  
  pixels8.setPixelColor(22, pixels8.Color(0, OFF, 0)); 
  pixels8.setPixelColor(23, pixels8.Color(0, OFF, 0)); 
}

void ledoff9(){
   pixels9.setPixelColor(0, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(1, pixels9.Color(0,OFF, 0));  
  pixels9.setPixelColor(2, pixels9.Color(0, OFF, 0)); 
  pixels9.setPixelColor(3, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(4, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(5, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(6, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(7, pixels9.Color(0, OFF, 0)); 
  pixels9.setPixelColor(8, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(9, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(10, pixels9.Color(0, OFF, 0)); 
  pixels9.setPixelColor(11, pixels9.Color(0, OFF, 0));
  pixels9.setPixelColor(12, pixels9.Color(0, OFF, 0));  
  pixels9.setPixelColor(13, pixels9.Color(0, OFF, 0)); 
  
}

void ledoff10(){
  pixels10.setPixelColor(0, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(1, pixels10.Color(0,OFF, 0));  
  pixels10.setPixelColor(2, pixels10.Color(0, OFF, 0)); 
  pixels10.setPixelColor(3, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(4, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(5, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(6, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(7, pixels10.Color(0, OFF, 0)); 
  pixels10.setPixelColor(8, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(9, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(10, pixels10.Color(0, OFF, 0)); 
  pixels10.setPixelColor(11, pixels10.Color(0, OFF, 0));
  pixels10.setPixelColor(12, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(13, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(14, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(15, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(16, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(17, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(18, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(19, pixels10.Color(0, OFF, 0)); 
  pixels10.setPixelColor(20, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(21, pixels10.Color(0, OFF, 0));  
  pixels10.setPixelColor(22, pixels10.Color(0, OFF, 0)); 
  pixels10.setPixelColor(23, pixels10.Color(0, OFF, 0));  
}

void ledoff11(){
    pixels11.setPixelColor(0, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(1, pixels11.Color(0,OFF, 0));  
  pixels11.setPixelColor(2, pixels11.Color(0, OFF, 0)); 
  pixels11.setPixelColor(3, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(4, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(5, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(6, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(7, pixels11.Color(0, OFF, 0)); 
  pixels11.setPixelColor(8, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(9, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(10, pixels11.Color(0, OFF, 0)); 
  pixels11.setPixelColor(11, pixels11.Color(0, OFF, 0));
  pixels11.setPixelColor(12, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(13, pixels11.Color(0, OFF, 0));
  pixels11.setPixelColor(14, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(15, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(16, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(17, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(18, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(19, pixels11.Color(0, OFF, 0)); 
  pixels11.setPixelColor(20, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(21, pixels11.Color(0, OFF, 0));  
  pixels11.setPixelColor(22, pixels11.Color(0, OFF, 0)); 
  pixels11.setPixelColor(23, pixels11.Color(0, OFF, 0));  
}


void ledoff12(){
  pixels12.setPixelColor(0, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(1, pixels12.Color(0,OFF, 0));  
  pixels12.setPixelColor(2, pixels12.Color(0, OFF, 0)); 
  pixels12.setPixelColor(3, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(4, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(5, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(6, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(7, pixels12.Color(0, OFF, 0)); 
  pixels12.setPixelColor(8, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(9, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(10, pixels12.Color(0, OFF, 0)); 
  pixels12.setPixelColor(11, pixels12.Color(0, OFF, 0));
  pixels12.setPixelColor(12, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(13, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(14, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(15, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(16, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(17, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(18, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(19, pixels12.Color(0, OFF, 0)); 
  pixels12.setPixelColor(20, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(21, pixels12.Color(0, OFF, 0));  
  pixels12.setPixelColor(22, pixels12.Color(0, OFF, 0)); 
  pixels12.setPixelColor(23, pixels12.Color(0, OFF, 0));  
}

void ledoff13(){
   pixels13.setPixelColor(0, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(1, pixels13.Color(0,OFF, 0));  
  pixels13.setPixelColor(2, pixels13.Color(0, OFF, 0)); 
  pixels13.setPixelColor(3, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(4, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(5, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(6, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(7, pixels13.Color(0, OFF, 0)); 
  pixels13.setPixelColor(8, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(9, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(10, pixels13.Color(0, OFF, 0)); 
  pixels13.setPixelColor(11, pixels13.Color(0, OFF, 0));
  pixels13.setPixelColor(12, pixels13.Color(0, OFF, 0));  
  pixels13.setPixelColor(13, pixels13.Color(0, OFF, 0)); 
  
}

void ledoff14(){
  pixels14.setPixelColor(0, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(1, pixels14.Color(0,OFF, 0));  
  pixels14.setPixelColor(2, pixels14.Color(0, OFF, 0)); 
  pixels14.setPixelColor(3, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(4, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(5, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(6, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(7, pixels14.Color(0, OFF, 0)); 
  pixels14.setPixelColor(8, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(9, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(10, pixels14.Color(0, OFF, 0)); 
  pixels14.setPixelColor(11, pixels14.Color(0, OFF, 0));
  pixels14.setPixelColor(12, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(13, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(14, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(15, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(16, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(17, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(18, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(19, pixels14.Color(0, OFF, 0)); 
  pixels14.setPixelColor(20, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(21, pixels14.Color(0, OFF, 0));  
  pixels14.setPixelColor(22, pixels14.Color(0, OFF, 0)); 
  pixels14.setPixelColor(23, pixels14.Color(0, OFF, 0));  
}

void ledoff15(){
     pixels15.setPixelColor(0, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(1, pixels15.Color(0,OFF, 0));  
  pixels15.setPixelColor(2, pixels15.Color(0, OFF, 0)); 
  pixels15.setPixelColor(3, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(4, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(5, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(6, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(7, pixels15.Color(0, OFF, 0)); 
  pixels15.setPixelColor(8, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(9, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(10, pixels15.Color(0, OFF, 0)); 
  pixels15.setPixelColor(11, pixels15.Color(0, OFF, 0));
  pixels15.setPixelColor(12, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(13, pixels15.Color(0, OFF, 0));
  pixels15.setPixelColor(14, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(15, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(16, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(17, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(18, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(19, pixels15.Color(0, OFF, 0)); 
  pixels15.setPixelColor(20, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(21, pixels15.Color(0, OFF, 0));  
  pixels15.setPixelColor(22, pixels15.Color(0, OFF, 0)); 
  pixels15.setPixelColor(23, pixels15.Color(0, OFF, 0)); 
}


void ledoff16(){
  pixels16.setPixelColor(0, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(1, pixels16.Color(0,OFF, 0));  
  pixels16.setPixelColor(2, pixels16.Color(0, OFF, 0)); 
  pixels16.setPixelColor(3, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(4, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(5, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(6, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(7, pixels16.Color(0, OFF, 0)); 
  pixels16.setPixelColor(8, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(9, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(10, pixels16.Color(0, OFF, 0)); 
  pixels16.setPixelColor(11, pixels16.Color(0, OFF, 0));
  pixels16.setPixelColor(12, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(13, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(14, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(15, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(16, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(17, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(18, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(19, pixels16.Color(0, OFF, 0)); 
  pixels16.setPixelColor(20, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(21, pixels16.Color(0, OFF, 0));  
  pixels16.setPixelColor(22, pixels16.Color(0, OFF, 0)); 
  pixels16.setPixelColor(23, pixels16.Color(0, OFF, 0));  
}

void ledoff17(){
  pixels17.setPixelColor(0, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(1, pixels17.Color(0,OFF, 0));  
  pixels17.setPixelColor(2, pixels17.Color(0, OFF, 0)); 
  pixels17.setPixelColor(3, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(4, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(5, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(6, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(7, pixels17.Color(0, OFF, 0)); 
  pixels17.setPixelColor(8, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(9, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(10, pixels17.Color(0, OFF, 0)); 
  pixels17.setPixelColor(11, pixels17.Color(0, OFF, 0));
  pixels17.setPixelColor(12, pixels17.Color(0, OFF, 0));  
  pixels17.setPixelColor(13, pixels17.Color(0, OFF, 0));  
  
}

void ledoff18(){
  pixels18.setPixelColor(0, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(1, pixels18.Color(0,OFF, 0));  
  pixels18.setPixelColor(2, pixels18.Color(0, OFF, 0)); 
  pixels18.setPixelColor(3, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(4, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(5, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(6, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(7, pixels18.Color(0, OFF, 0)); 
  pixels18.setPixelColor(8, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(9, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(10, pixels18.Color(0, OFF, 0)); 
  pixels18.setPixelColor(11, pixels18.Color(0, OFF, 0));
  pixels18.setPixelColor(12, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(13, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(14, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(15, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(16, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(17, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(18, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(19, pixels18.Color(0, OFF, 0)); 
  pixels18.setPixelColor(20, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(21, pixels18.Color(0, OFF, 0));  
  pixels18.setPixelColor(22, pixels18.Color(0, OFF, 0)); 
  pixels18.setPixelColor(23, pixels18.Color(0, OFF, 0));  
}


void ledclear(){
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels6.clear();
  pixels7.clear();
  pixels8.clear();
  pixels9.clear();
  pixels10.clear();
  pixels11.clear();
  pixels12.clear();
  pixels13.clear();
  pixels14.clear();
  pixels15.clear();
  pixels16.clear();
  pixels17.clear();
  pixels18.clear();
}

void show(){
  pixels3.show();
  pixels4.show();
  pixels5.show();
  pixels6.show();
  pixels7.show();
  pixels8.show();
  pixels9.show();
  pixels10.show();
  pixels11.show();
  pixels12.show();
  pixels13.show();
  pixels14.show();
  pixels15.show();
  pixels16.show();
  pixels17.show();
  pixels18.show();
}

void loop() {
  
 char ch = Serial.read();
 
 if(ch == 'A'){
      
  ledclear();
  // road 1
  
   ledoff3(); 
   ledoff4();
   ledoff5();
   green6();
 
  // road 2  
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
  // road 3
   ledoff11();
   ledoff12();
   ledoff13();
   green14();
   
  // road 4
   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show();
//   ledclear();


 }
 
 else if(ch == 'B'){
   
 ledclear();  
  
   ledoff3(); //red
   yellow4(); // yellow
   ledoff5();// green
   ledoff6();// left
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   ledoff11();
   yellow12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 
   

 }
 
 else if(ch == 'C'){
     
  ledclear();
   red3();    //red
   ledoff4(); 
   left5(); 
   ledoff6();  //left
   
   red7();    //red
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();   //red
   ledoff12();
   left13();
   ledoff14(); //left

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'D'){
   
ledclear();   
   ledoff3();
   yellow4();
   ledoff5();
   ledoff6();
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   ledoff11();
   yellow12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'E'){
     
ledclear();  
   red3();
   ledoff4();
   ledoff5();
   ledoff6();
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'F'){
     
  ledclear();  
   red3();
   ledoff4();
   ledoff5();
   ledoff6();
   
   ledoff7();
   ledoff8();
   left9();
   green10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 


 }
 
 else if(ch == 'G'){

   
  ledclear();  
   red3();
   ledoff4();
   ledoff5();
   ledoff6();
   
   ledoff7();
   yellow8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'H'){

   
  ledclear();  
   red3();
   ledoff4();
   ledoff5();
   ledoff6();
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'I'){
     
ledclear();  
   red3();
   ledoff4();
   ledoff5();// yellow
   ledoff6();// red
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   ledoff15();
   ledoff16();
   left17();
   green18();

   show(); 

 }
 
 else if(ch == 'J'){
     
  ledclear();
   red3();
   ledoff4();
   ledoff5();// yellow
   ledoff6();// red
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   ledoff15();
   yellow16();
   ledoff17();
   ledoff18();

   show(); 

 }
 
 else if(ch == 'K'){
     
  ledclear();  
   red3();
   ledoff4();
   ledoff5();
   ledoff6();
   
   red7();
   ledoff8();
   ledoff9();
   ledoff10();
   
   red11();
   ledoff12();
   ledoff13();
   ledoff14();

   red15();
   ledoff16();
   ledoff17();
   ledoff18();

   show(); 

 }

}
