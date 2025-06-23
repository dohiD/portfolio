/*
 * main.c
 * define following↓
 * int main()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagedata.h"

#define MSIZE 3

void shuffle();
void show();
int check();
void move(char *key, int *posx, int *posy);
void puzzle_image();

// パズル行列
int matrix[MSIZE][MSIZE];

unsigned char img[HEIGHT][WIDTH][3];
unsigned char out[HEIGHT][WIDTH][3];
unsigned char header[54];


int main(void)
{
    int i, j;
    char key[64];

    // posx, posy: "0"のパズル上の位置
    // 右下に設定
    int posx = MSIZE - 1;
    int posy = MSIZE - 1;
    
    // パズル行列(matrix)の初期化
    for ( i = 0; i < MSIZE; i++ )
    {
        for ( j = 0; j < MSIZE; j++ )
        {
            matrix[i][j] = i * MSIZE + j + 1;
        }
    }
    matrix[posx][posy] = 0;

    // パズルをシャッフルする
    shuffle();

    // パズル画像データの生成
    read_image("apple.bmp");
    puzzle_image();
    write_image("puzzle.bmp");

    // パズルが完成するまでループ
    while ( check() > 0)
    {
        // 現在のパズルの状況を表示
        show();

        // キー入力を促す
        printf("↑:W  ←:A  ↓:S  →:D  exit:C: ");
        scanf("%s", key);

        // "c" or "C" が入力されれば強制終了
        if ( strcmp(key, "c") == 0 || strcmp(key, "C") == 0 )
        {
            printf("Exit\n");
            return 0;
        }

        // キー入力で指定した方向へ"0"を移動する
        move(key, &posx, &posy);
        puzzle_image(matrix, MSIZE);
        write_image("puzzle.bmp");

    }

    show();
    printf("Congratulations!!\n");
    write_image("puzzle.bmp");
    return 0;
}

