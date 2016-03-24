from cv2 import *
import numpy as np

img=imread("test.jpg",0)
img=bitwise_not(img)
src=imread("test.jpg")
ret, otsu = threshold(img,0,255,THRESH_BINARY+THRESH_OTSU)
imshow("Initial Image",otsu)
waitKey(0)
destroyWindow("Initial Image")
dist = np.zeros((img.shape[0], img.shape[1], 3), dtype = np.uint8)
contours, hierarchy = findContours(otsu,RETR_TREE,CHAIN_APPROX_SIMPLE)
drawContours(dist,contours,-1,(255,255,255),-1)
gray=cvtColor(dist,COLOR_BGR2GRAY)
imwrite("Contour_Image.jpg",gray);
#output=distanceTransform(gray,cv.CV_DIST_L2,5)
#output=normalize(output, 0.0, 1.0, NORM_MINMAX);
#circles = HoughCircles(img,cv.CV_HOUGH_GRADIENT,1,20,200,100,1,5)
#circles = np.uint16(np.around(circles))
#for i in circles[0,:]:
#circle(src,(i[0],i[1]),i[2],(0,255,0),2)


imshow('detected contours',dist)
#imshow("Applied Distance transform",output)
waitKey(0)
destroyWindow("detected circles")
