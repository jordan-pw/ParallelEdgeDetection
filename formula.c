#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "formula.h"

/*
* Can move row, col input back to equal -1 of input if need be
*/
double convolution(double *image, int mask[3][3], int row, int col, struct dimensions d) {

	int i, j;
	int row_offset, col_offset;
	double sum = 0.0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			sum += image[col + (d.height * row) + i + (j * d.width)] * mask[i][j];
		}
	}

	return sum;
}


//Sobel Edge Detection Algorithm method
double* sobel_edge_detection(double *grayscaleImg, struct dimensions dim) {

	int i, j;
	double gx, gy;

	//malloc if necessary
	double* outputImg = malloc(dim.width * dim.height * sizeof(double));
	memcpy(outputImg, grayscaleImg, dim.width * dim.height * sizeof(double));

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
	for (i = 1; i < dim.height-2; i++) {
		for (j = 1; j < dim.width - 2; j++) {
			gx = convolution(grayscaleImg, vMask, i, j, dim);
			gy = convolution(grayscaleImg, hMask, i, j, dim);
			outputImg[j + i*dim.width] = sqrt(gx * gx + gy * gy);

			printf("finished iteration%d\n",j+i );
			//Can add these if want to see the independent horizontal and vertical edges
			//outputX[i][j] = gx;
			//outputY[i][j] = gy;
		}
	}

	return outputImg;

}
