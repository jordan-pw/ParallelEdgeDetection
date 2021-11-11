from PIL import Image
#import numpy as np

img = Image.new('RGB', (63,40))


flag = 0

flagColor = 0

for x in range(0,40):
    for y in range(0,63):
        flagColor = y / 21
        if flag == 0:
            print("255, ")
            if flagColor == 0:
                img.putpixel((y,x),(255,0,0))
            elif flagColor == 1:
                img.putpixel((y,x),(0,255,0))
            else:
                img.putpixel((y,x),(0,0,255))
            flag = 1
        else:
            img.putpixel((y,x),(0,0,0))
            print("0, ")
            flag = 0
    

img.save('image.bmp')