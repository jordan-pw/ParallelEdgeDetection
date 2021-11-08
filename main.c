#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grayscale.h"

int main()
{
    struct dimensions test = bmp_dimensions("small.bmp");
    printf("Width = %d, Height = %d\n", test.width, test.height);

    double *grayscale_pix = bmp_to_grayscale("small.bmp");

    matrix_to_file("small.bmp", grayscale_pix);

    return 0;
}
