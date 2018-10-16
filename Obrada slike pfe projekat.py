import serial
import numpy as np
from matplotlib import pyplot as plt
import sys
sys.path.append('C:\\Users\\Pavle\\AppData\\Local\\Programs\\Python\\Python36-32\\Lib\\site-packages')
import cv2
cap = cv2.VideoCapture(0)
cap.get(3)

while(True):
    ret, frame = cap.read()
    x=[]
    y=[]
    k=0
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    ret1, thresh1 = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)

    filtrirana = cv2.bilateralFilter(thresh1, 11, 30, 30)

    for i in range(len(filtrirana)):
        for j in range(len(filtrirana[i])):
            if filtrirana[i][j] == 255:
                x.append(j)
                y.append(i)
                k+=1

    a=sum(x)
    b=sum(y)
    if k!=0:
        a/=k
        b/=k
        print(a)
        print(b)




    cv2.imshow('frame',filtrirana)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()
