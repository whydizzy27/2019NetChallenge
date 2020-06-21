#! /usr/bin/python
# Written by Dan Mandle http://dan.mandle.me September 2012
# http://www.danmandle.com/blog/getting-gpsd-to-work-with-python/
# License: GPL 2.0 

# This code runs compatibly under Python 2 and 3.x for x >= 2.
# Preserve this property!
from __future__ import absolute_import, print_function, division

import os
from gps import *
from time import *
import time
import math 
import threading

gpsd = None #seting the global variable

os.system('clear') #clear the terminal (optional)

class GpsPoller(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)
    global gpsd #bring it in scope
    gpsd = gps(mode=WATCH_ENABLE) #starting the stream of info
    self.current_value = None
    self.running = True #setting the thread running to true

  def run(self):
    global gpsd
    while gpsp.running:
      next(gpsd) #this will continue to loop and grab EACH set of gpsd info to clear the buffer

if __name__ == '__main__':
  gpsp = GpsPoller() # create the thread
  try:
    gpsp.start() # start it up
    a = [0,0]
    while True:
      #It may take a second or two to get good data
      #print gpsd.fix.latitude,', ',gpsd.fix.longitude,'  Time: ',gpsd.utc
        os.system('clear')
        
        
        #traffic light no 1    
        if gpsd.fix.longitude <= 126.978995333 and gpsd.fix.longitude >= 126.975394667 and gpsd.fix.latitude <= 37.211746667 and gpsd.fix.latitude >= 37.207723333:
            tn = "0001"
            
            R = 6371
            x = (gpsd.fix.longitude - 126.977065) * math.cos(0.5*(gpsd.fix.latitude + 37.209555))
            y = gpsd.fix.latitude - 37.209555
            d = R * math.sqrt(x*x + y*y)
            if gpsd.fix.speed==0:
                ct=0
            else:
                ct = (d*1000)/gpsd.fix.speed #dan we meter
            f2=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/distance.txt",'w')
            f2.write(str(ct))
            f2.close()
            #d dan we km/h
            #before 0 now 1
            a[0]=a[1]
            a[1]=d
        
            if a[0]>a[1]:
                w=1
            else:
                w=0
         
            if gpsd.fix.longitude <= 126.976825 and gpsd.fix.longitude >= 126.975381667 and gpsd.fix.latitude <= 37.209626667 and gpsd.fix.latitude >= 37.209406667 and w==1:
                rn = "000"
                fn = "0001000"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 126.977123333 and gpsd.fix.longitude >= 126.976711667 and gpsd.fix.latitude <= 37.209353333 and gpsd.fix.latitude >= 37.207723333 and w==1:
                rn = "001"
                fn = "0001001"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 126.978995333 and gpsd.fix.longitude >= 126.977258333 and gpsd.fix.latitude <= 37.209678333 and gpsd.fix.latitude >= 37.209488333 and w==1:
                rn = "010"
                fn = "0001010"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 126.977921667 and gpsd.fix.longitude >= 126.977015 and gpsd.fix.latitude <= 37.211746667 and gpsd.fix.latitude >= 37.209706667 and w==1:
                rn = "011"
                fn = "0001011"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            else :
                rn = "none"
                fn = "none"
                head = "out of range or get out"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
                
        #traffic light 2
        elif gpsd.fix.longitude <= 126.974781667 and gpsd.fix.longitude >= 126.972843 and gpsd.fix.latitude <= 37.209856667 and gpsd.fix.latitude >= 37.208941667:
            tn = "0002"
            
            R = 6371
            x = (gpsd.fix.longitude - 126.973345) * math.cos(0.5*(gpsd.fix.latitude + 37.209448333))
            y = gpsd.fix.latitude - 37.209448333
            d = R * math.sqrt(x*x + y*y)
            if gpsd.fix.speed==0:
                ct=0
            else:
                ct = (d*1000)/gpsd.fix.speed #dan we meter
            f2=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/distance.txt",'w')
            f2.write(str(ct))
            f2.close()
            #d dan we km/h
            #before 0 now 1
            a[0]=a[1]
            a[1]=d
        
            if a[0]>a[1]:
                w=1
            else:
                w=0
         
            if gpsd.fix.longitude <= 126.974781667 and gpsd.fix.longitude >= 126.973573333 and gpsd.fix.latitude <= 37.209856667 and gpsd.fix.latitude >= 37.209473333 and w==1:
                rn = "000"
                fn = "0002000"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 126.973138333 and gpsd.fix.longitude >= 126.972843 and gpsd.fix.latitude <= 37.209725 and gpsd.fix.latitude >= 37.20952 and w==1:
                rn = "001"
                fn = "0002001"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 126.973383333 and gpsd.fix.longitude >= 126.973153333 and gpsd.fix.latitude <= 37.209333333 and gpsd.fix.latitude >= 37.208941667 and w==1:
                rn = "010"
                fn = "0002010"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            elif gpsd.fix.longitude <= 1.1 and gpsd.fix.longitude >= 1.0 and gpsd.fix.latitude <= 1.1 and gpsd.fix.latitude >= 1.0 and w==1:
                rn = "011"
                fn = "0002011"
                head = "entry"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            else :
                rn = "none"
                fn = "none"
                head = "out of range or get out"
                f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
                f.write(fn)
                f.close()
            
        else :
            tn = "none"
            rn = "none"
            fn = "none"
            d  = "none"
            head = "out of range"
            #f1=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data2.txt",'w')
            #f1.write(tn)
            #f1.close()
            f=open("/home/pi/rpi-lora-tranceiver-master/dragino_lora_app/data.txt",'w')
            f.write(fn)
            f.close()
                        
        print()
        print(' GPS reading ')
        print('----------------------------------------')
        print('latitude    :' , gpsd.fix.latitude)
        print('longitude   :' , gpsd.fix.longitude)
        print('Trf Lgt num :' , tn)    
        print('road number :' , rn)    
        print('time utc    :' , gpsd.utc,' + ', gpsd.fix.time)
        print('altitude (m):' , gpsd.fix.altitude)
        print('distance(km):' , d)
        print('entry or no :' , head)
        print('speed (m/s) :' , gpsd.fix.speed)
        print('speed (km/h):' , gpsd.fix.speed/3.6)
        #print('a number', an)      
        print()

        time.sleep(1.000) #set to whatever

  except (KeyboardInterrupt, SystemExit): #when you press ctrl+c
    print("\nKilling Thread...")
    gpsp.running = False
    gpsp.join() # wait for the thread to finish what it's doing
    print("Done.\nExiting.")
