import numpy as np
import matplotlib.pyplot as plt

X = np.genfromtxt('data.csv', delimiter=',')

plt.imshow(X, cmap='gray')
plt.show()
