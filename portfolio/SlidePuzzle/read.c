/*
 * read.c
 * define following↓
 * int read_image()
 */
#include <stdio.h>
#include "imagedata.h"

int read_image(char* filename)
{
    FILE *fr;
    int i, j;

    fr = fopen(filename, "rb");

    if( fr == NULL ){
        printf("Cannot open file\n");
        return 1;
    }

    fread(header, sizeof(unsigned char), 54, fr);

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            fread(img[i][j], sizeof(unsigned char), 3, fr);
        }
    }

    fclose(fr);

    return 0;
}

