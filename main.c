#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grayscale.h"

int main(int argc, char *argv[])
{
    char *input_file = argv[1];

    if (!argv[1])
    {
      printf("File name required\nUsage: ./grayscale file_name.bmp\n");
      return 0;
    }

    struct dimensions test = bmp_dimensions(input_file);
    printf("Width = %d, Height = %d\n", test.width, test.height);

    double *grayscale_pix = bmp_to_grayscale(input_file);

    matrix_to_file(input_file, grayscale_pix);

    return 0;
}
