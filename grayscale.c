#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grayscale.h"

struct dimensions bmp_dimensions(char *file_name)
{
    FILE *fIn = fopen(file_name, "rb");
    if (!fIn)
    {
        printf("File error.\n");
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fIn);

    int width = *(int*)&header[18];
    int height = abs(*(int*)&header[22]);

    struct dimensions d;
    d.width = width;
    d.height = height;
    return d;
}

double * bmp_to_grayscale(char *file_name)
{
    FILE *fIn = fopen(file_name, "rb");
    if (!fIn)
    {
        printf("File error.\n");
        return 0;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fIn);

    int width = *(int*)&header[18];
    int height = abs(*(int*)&header[22]);

    double *grayscale_pix = malloc(width * height * sizeof(double));

    unsigned char pixel[3];
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fread(pixel, 3, 1, fIn);
            double gray = (pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11)/255;
            grayscale_pix[(y*width) + x] = gray;
        }
    }
    fclose(fIn);

    return grayscale_pix;
}

void matrix_to_file(char *file_name, double *matrix)
{
    struct dimensions dim = bmp_dimensions(file_name);
    char output[8];
    FILE *dataOut = fopen("data.csv", "w+");

    for (int y = 0; y < dim.height; ++y)
    {
        for (int x = 0; x < dim.width; ++x)
        {
            snprintf(output, 318, "%f,", matrix[(y*dim.width) + x]);
            fwrite(output, sizeof(double), 1, dataOut);
            fwrite(",", sizeof(char), 1, dataOut);
        }
        fwrite("\n", sizeof(char), 1, dataOut);
    }
    fclose(dataOut);
}
