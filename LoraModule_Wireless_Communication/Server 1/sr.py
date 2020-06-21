import serial
import time

port = '/dev/ttyUSB0'
ser = serial.Serial(port,9600)

while True:
    
    f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/tfdata.txt",'r')
    data = f.read()
    f.close()
    #led = raw_input(" 'A-K' , 'z' : ") 
    ser.write(data)
   # if led == "e" :
    #        print("program End")
     #       break