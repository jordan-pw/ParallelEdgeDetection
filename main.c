#include <stdio.h>
#include <stdlib.h>

#include "grayscale.h"

int main()
{
    struct dimensions test = bmp_dimensions("frog.bmp");
    printf("Width = %d, Height = %d\n", test.width, test.height);

    double *grayscale_pix = bmp_to_grayscale("frog.bmp");

    for (int i = 0; i < test.width; ++i)
    {
        for (int j = 0; j < test.height; ++j)
        {
            printf("%f\n", grayscale_pix[i * j]);
        }
    }

    return 0;
}
