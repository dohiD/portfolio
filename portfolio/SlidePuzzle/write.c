/*
 * write.c
 * define following↓
 * int write_image()
 */
#include <stdio.h>
#include "imagedata.h"

int write_image(char* filename)
{
    FILE *fw;
    int i, j;

    fw = fopen(filename, "wb");

    if( fw == NULL ){
        printf("Cannot open file\n");
        return 1;
    }

    fwrite(header, sizeof(unsigned char), 54, fw);

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            fwrite(out[i][j], sizeof(unsigned char), 3, fw);
        }
    }

    fclose(fw);

    return 0;
}

