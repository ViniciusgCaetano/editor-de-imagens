import cv2
import os


files = os.listdir('originais')
c = 1

for file in files:
    img = cv2.imread('originais/' + file, cv2.IMREAD_GRAYSCALE)
    cv2.imwrite(f"pgm/image{c}.pgm", img, [cv2.IMWRITE_PXM_BINARY, 0])
    c += 1
