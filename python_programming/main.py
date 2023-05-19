import cv2
import pandas as pd
from datetime import datetime, timedelta
import os

cap =cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

imgBackground =cv2.imread('python_programming/recources/background.png')
 
folderModePath = 'python_programming/recources/modes/'
modePathList = os.listdir(folderModePath)
imgModeList = [] 
for path in folderModePath:
    imgModeList.append(cv2.imread(os.path.join(folderModePath,path)))
#print(len(imgModeList))

while True:
    success, img = cap.read()
    
    imgBackground[130:130+480,57:57+640] = img
    #imgBackground[49:49+574,854:854+346] = imgModeList[0]
   # cv2.imshow("Webcam", img)
    cv2.imshow("Face Attendance", imgBackground)
    cv2.waitKey(1)