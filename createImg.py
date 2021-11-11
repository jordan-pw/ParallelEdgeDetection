from PIL import Image
import numpy as np

img = Image.new('L', (459,306))

result = np.genfromtxt('data.csv', delimiter=',')
X = result[::-1]

#for i in range(0,len(X)):
    #X[i]= X[i]*1000
    
print("width: " , img.size[0])
print("Height: ", img.size[1])

pixel_map = img.load()

for i in range(img.size[1]):
    #print(i)
    for j in range(img.size[0]):
        grayscale = X[i][j]
        #print(i," j:",j, " grayscale:", grayscale)
        pixel_map[j,i ] = int(grayscale)
        #if i == 0 :
           # print(i," j:",j, " grayscale:", grayscale)
            #print(grayscale, " index:", j)
    #pixel_map[1600,i] = 0
        

img.save("grayscale",format="bmp")

img.putdata(X)
img.save('imagewee.bmp')