import cv2 as cv
import numpy as np
img = cv.imread('Photos/Noise.png')
rows,cols = img.shape[:2]

#gaussian Blur
output_gaus= cv.GaussianBlur(img,(5,5),0)

#median Blur(reduction of noise)
output_med = cv.medianBlur(img,5)

#Bilateral filtering (Reduction of noise + Preserving of edges)
output_bilateral = cv.bilateralFilter(img,5,6,6)


cv.imshow('Noise',img)
cv.imshow('Gaussian',output_gaus)
cv.imshow('Median',output_med)
cv.imshow('Bilateral',output_bilateral)
cv.waitKey(0)