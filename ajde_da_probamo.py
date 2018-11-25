import serial
import numpy as np
from matplotlib import pyplot as plt
import cv2
import imutils
cap = cv2.VideoCapture(0)

kraj = False
lower = (200, 200, 200)
upper = (255, 255, 255)

while(not kraj):
    ret, frame = cap.read()

    frame = imutils.resize(frame,width=600)
    blurred = cv2.GaussianBlur(frame, (11, 11), 0)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    ret1, thresh1 = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)
    img = cv2.bilateralFilter(thresh1, 11, 30, 30)

    cnts = cv2.findContours(img.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = cnts[0] if imutils.is_cv2() else cnts[1]
    center = None
    if len(cnts) > 0:
        c = max(cnts, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

        if radius > 10:
            cv2.circle(frame, (int(x), int(y)), int(radius), (0, 255, 255), 2)
            cv2.circle(frame, center, 5, (0, 0, 255), -1)

    cv2.imshow('perica', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        kraj = True

cap.release()

cv2.destroyAllWindows()