import serial
import numpy as np
from matplotlib import pyplot as plt
import sys
sys.path.append('C:\\Users\\Pavle\\AppData\\Local\\Programs\\Python\\Python36-32\\Lib\\site-packages')
import cv2

'''bitna stvar, kad se ukljuci kamera treba je ugasiti na q , ostalo nece raditi'''

cap = cv2.VideoCapture(0)
ser=serial.Serial("com4", 9600)#ovde posle com treba da pise na koji port smo zakacili arduino
while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    ret1, thresh1 = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)
    filtrirana = cv2.bilateralFilter(thresh1, 11, 30, 30)
    circles = cv2.HoughCircles(filtrirana, cv2.HOUGH_GRADIENT, 0.9, 150, param1=50, param2=30, minRadius=30, maxRadius=200)
    if circles is not None:
        circles = np.uint16(np.around(circles))
        for i in circles[0, :]: #ovo je jedini nacin koji sam nasao da pristupim x i y koordinati od circles
            x=i[0]
            y=i[1]
            sx=x.astype('string')#konvertujemo u stringove
            sy=y.astype('string')
            ser.write(sx.encode()) #ovo sranje encode je metod samo za stringove zato sam se cimao ovako
            ser.write(sy.encode())
            #ove stvarcice dole su tu prosto
    cv2.imshow('frame', filtrirana)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()



