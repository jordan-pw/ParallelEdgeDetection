#ifndef FORMULA_H_
#define FORMULA_H_
#include "grayscale.h"

int convolution(int* image, int mask[3][3], int row, int col, struct dimensions d);

int* sobel_edge_detection(int* grayscaleImg, struct dimensions dim);

#endif
