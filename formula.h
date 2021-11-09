#ifndef FORMULA_H_
#define FORMULA_H_
#include "grayscale.h"

double convolution(double* image, int mask[3][3], int row, int col, struct dimensions d);

double* sobel_edge_detection(double* grayscaleImg, struct dimensions dim);

#endif
