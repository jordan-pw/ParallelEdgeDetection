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

int * bmp_to_grayscale(char *file_name)
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
    int padding = (4-((3*width)%4))%4;

    // printf("W:%d, H:%d\n", width,height);

    int *grayscale_pix = malloc(width * height * sizeof(int));

    unsigned char pixel[3];

    fseek(fIn, 54, SEEK_SET);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fread(&pixel, 3, 1, fIn);
            int gray = (pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11);
            grayscale_pix[(y*width) + x] = gray;
        }
        fseek(fIn, padding, SEEK_CUR);
    }

    fclose(fIn);

    return grayscale_pix;
}

void matrix_to_file(char *file_name, int *matrix)
{
    struct dimensions dim = bmp_dimensions(file_name);
    // char output[4];
    FILE *dataOut = fopen("data.csv", "w+");

    for (int y = 0; y < dim.height; ++y)
    {
        for (int x = 0; x < dim.width; ++x)
        {
            char output[4] = {'0','0','0','0'};
            // snprintf(output, sizeof(char)*4, "%d", matrix[(y*dim.width) + x]);
            output[0] = '0' + matrix[(y*dim.width) + x] / 100;
            output[1] = '0' + (matrix[(y*dim.width) + x] % 100)/10;
            output[2] = '0' + matrix[(y*dim.width) + x] % 10;
            // printf("%c%c%c\n",output[0],output[1],output[2]);
            fwrite(output, sizeof(char), 3, dataOut);
            fwrite(",", sizeof(char), 1, dataOut);
        }
        fwrite("\n", sizeof(char), 1, dataOut);
    }
    fclose(dataOut);
}
