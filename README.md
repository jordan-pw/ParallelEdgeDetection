# ParallelEdgeDetection
Parallel edge detection algo in C using Prewitt operator on BMP files. Python to output the results. 

Requires .bmp files with 24bit color depth.

# Usage
gcc -g -Wall -o grayscale main.c grayscale.c

./grayscale file_name.bmp

python plot_image.py
