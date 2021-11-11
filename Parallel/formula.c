#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "formula.h"

/*
* Can move row, col input back to equal -1 of input if need be
*/
int convolution(int *image, int mask[3][3], int row, int col, struct dimensions d) {

	int i, j;
	int sum = 0;

	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			int x = col + j;				//horizontal pixel value
			int y = (row + i ) * d.width;	//Vertical pixel value
			// if(row > 301)
				// printf("image[%d], row:%d,col:%d, i:%d, j:%d, x:%d, y:%d  sum:%d\n", x+y,row,col,i,j, x,y, sum);
			sum += image[x+y] * mask[i+1][j+1];
		}
	}

	return sum;
}


//Sobel Edge Detection Algorithm method
int* sobel_edge_detection(int *grayscaleImg, struct dimensions dim) {

	int i, j;
	int gx, gy;

	//malloc if necessary
	int* outputImg = malloc(dim.width * dim.height * sizeof(int));
	memcpy(outputImg, grayscaleImg, dim.width * dim.height * sizeof(int));

	int vMask[3][3] = {
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};

	int hMask[3][3] = {
		{-1, -2, -1},
		{0, 0, 0},
		{1, 2, 1}
	};

printf("beginning formula for loop\n");

	/*
	 * i,j = 1 as we will be getting the 8 surrounding pixels, makes no sense to start on the picture's edge
	 */
	//	Add omp Parrall
	for (i = 1; i < dim.height-2; i++) {
		for (j = 1; j < dim.width - 2; j++) {
			gx = convolution(grayscaleImg, vMask, i, j, dim);
			gy = convolution(grayscaleImg, hMask, i, j, dim);
			outputImg[j + i*dim.width] = sqrt(gx * gx + gy * gy);

			// printf("finished iteration I=%d, j=%d\n",i,j );
			//Can add these if want to see the independent horizontal and vertical edges
			//outputX[i][j] = gx;
			//outputY[i][j] = gy;
		}
	}

	return outputImg;

}