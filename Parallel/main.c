/*
 *  Authors:  Jordan, Dillon & Conley
 *
 *  Complie command:
 *              gcc -g -Wall -o sobel main.c grayscale.c formula.c -lm
 *  Run Command:
 *              ./sobel <filename> 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grayscale.h"
#include "formula.h"

int main(int argc, char *argv[])
{

    char *input_file = argv[1];

    if (!argv[1])
    {
      printf("File name required\nUsage: ./grayscale file_name.bmp\n");
      return 0;
    }

    struct dimensions dim = bmp_dimensions(input_file);
    printf("Width = %d, Height = %d\n", dim.width, dim.height);

    int *grayscale_pix = bmp_to_grayscale(input_file);

    int *result = sobel_edge_detection(grayscale_pix, dim);

    matrix_to_file(input_file, result);

    free(grayscale_pix);
    free(result);

    return 0;
}
