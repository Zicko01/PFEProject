import serial
import numpy as np
from matplotlib import pyplot as plt
import sys
sys.path.append('C:\\Users\\Pavle\\AppData\\Local\\Programs\\Python\\Python36-32\\Lib\\site-packages')
import cv2
cap = cv2.VideoCapture(0)

while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    ret1, thresh1 = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)
    filtrirana = cv2.bilateralFilter(thresh1, 11, 30, 30)
    a = cv2.HoughCircles(filtrirana, cv2.HOUGH_GRADIENT, 0.9, 150, param1=50, param2=30, minRadius=30, maxRadius=200)
    #ovde bi kao trebalo da se niz a prebaci u intove al ne radi nesto
    print(a)
    cv2.imshow('frame', filtrirana)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()
