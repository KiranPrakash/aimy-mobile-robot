#CHANGE WORKING DIRECTORY!!!!!!!!!!!!!!!!!!!!!

import serial
import cv2
import numpy as np

vid = cv2.VideoCapture(0)
counter = 0
ser = serial.Serial('COM7', 9600)

while (1):    
    #read video
    rel, still = vid.read()
    
    #convert camera to gray scale
    img_gray = cv2.cvtColor(still, cv2.COLOR_BGR2GRAY)
    
    #read in image to check against
    template = cv2.imread('penonwhite.jpg',0)
    
    #get shape of template
    w, h = template.shape[::-1]
    
    #check if template is a match
    res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)
    
    #set matching threshold
    threshold = 0.5
    
    
    #MAGIC
    loc = np.where( res >= threshold)
    #if nothing is detected
    if len(loc[0]) == 0: 
        arduino = chr(126)
        ser.write(arduino)
        print arduino
    else:    
        sumx = 0
        sumy = 0
        count = 0
        for pt in zip(*loc[::-1]):
            cv2.rectangle(still, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2)
            sumx += pt[0]
            sumy += pt[1]
            count += 1
        datax = sumx / count
        datay = sumy / count
        x = int((datax+0)/25.6)
        y = int((datay+0)/96)
        arduino = chr(y*25+x)
        ser.write(arduino)
        print x, y, arduino    

    #show what thee camera sees with red box
    cv2.imshow('still',still)
    
    #time.sleep(1)
    #break if esc is pressed
    k = cv2.waitKey(5) & 0xFF
    if k ==27:
        break

cv2.destroyAllWindows()
