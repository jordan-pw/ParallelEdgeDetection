'''
    Description: Will show the image data that is stored in a csv file
        As an image. Should be a black and white image
    Author: Jordan
    Run Command:
'''
import numpy as np
import matplotlib.pyplot as plt

X = np.genfromtxt('data.csv', delimiter=',')
X = X[::-1]

plt.imshow(X, cmap='gray')
plt.show()
