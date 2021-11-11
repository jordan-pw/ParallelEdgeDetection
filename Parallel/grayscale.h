#ifndef GRAYSCALE_H_
#define GRAYSCALE_H_

struct dimensions
{
  int width;
  int height;
};

struct dimensions bmp_dimensions(char *file_name);

int * bmp_to_grayscale(char *file_name);

void matrix_to_file(char *file_name, int *matrix);

#endif
