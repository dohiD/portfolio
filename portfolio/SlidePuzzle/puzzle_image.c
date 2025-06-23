/*
 * puzzle_image.c
 * define following↓
 * int puzzle_image()
 */
#include <stdio.h>
#include "imagedata.h"

#define MSIZE 3
extern int matrix[MSIZE][MSIZE];

void puzzle_image(){
    int x, y;
    int i, j, k;

    // パズル１ピースの px 数
    double pcx = (double)WIDTH / (double)MSIZE;
    double pcy = (double)HEIGHT / (double)MSIZE;

    // 正解時のパズルピースのx, y座標(0 ~ MSIZE - 1)
    int x_coodinate, y_coodinate;

    for(y = MSIZE - 1; y >= 0; y--){
        for(x = 0; x < MSIZE; x++){
            x_coodinate = ((matrix[y][x] % MSIZE) + MSIZE - 1) % MSIZE;
            y_coodinate = (matrix[y][x] - 1) / MSIZE;

            // matrix = 0のピースを黒く塗りつぶす
            if(matrix[y][x] == 0){

                for(i = 0; i < (int)((y_coodinate + 1) * pcy) - (int)(y_coodinate * pcy); i++){
                    for(j = 0; j < (int)((x_coodinate + 1) * pcx) - (int)(x_coodinate * pcx); j++){
                        for(k = 0; k < 3; k++){
                            out[(int)((MSIZE - 1 - y) * pcy) + i][(int)(x * pcx) + j][k] = 0;
                        }
                    }
                }

            }

            // 正解時の座標を用いて元の入力画像からパズルピースの画像をコピー
            else{
                for(i = 0; i < (int)((y_coodinate + 1) * pcy) - (int)(y_coodinate * pcy); i++){
                    for(j = 0; j < (int)((x_coodinate + 1) * pcx) - (int)(x_coodinate * pcx); j++){
                        for(k = 0; k < 3; k++){
                            out[(int)((MSIZE - 1 - y) * pcy) + i][(int)(x * pcx) + j][k] = img[(int)((MSIZE - y_coodinate - 1) * pcy) + i][(int)(x_coodinate * pcx) + j][k];
                        }
                    }
                }

            }
        }
    }
}
