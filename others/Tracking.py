import cv2
import numpy as np

vid = cv2.VideoCapture(0)

while (1):
    rel, still = vid.read()
    
    img_gray = cv2.cvtColor(still, cv2.COLOR_BGR2GRAY)
    template = cv2.imread('block.jpg',0)
    w, h = template.shape[::-1]
    
    res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)
    threshold = 0.5
    loc = np.where( res >= threshold)
    detect = 'false'
    for pt in zip(*loc[::-1]):
        cv2.rectangle(still, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2)
        if detect == 'false':
            detect = 'true'
            print 'match'
    
    cv2.imwrite('res.png',still)
    cv2.imshow('still',still)
    k = cv2.waitKey(5) & 0xFF
    if k ==27:
        break
        
cv2.destroyAllWindows()