/*
 * puzzle.c
 * define following↓
 * void swap()
 * void shuffle()
 * void show()
 * void check()
 * void move()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MSIZE 3
extern int matrix[MSIZE][MSIZE];


// matrix[iy][ix] と matrix[jy][jx] を入れ替える
void swap(int iy, int ix, int jy, int jx)
{
    int tmp;
    tmp = matrix[iy][ix];
    matrix[iy][ix] = matrix[jy][jx];
    matrix[jy][jx] = tmp;
}


// matrix (0 ~ 8の数字) をランダムに並べ替える
void shuffle()
{
    // 入れ替えを行う2つのmatrixを指定する値
    int i, j;
 
    // 乱数の初期化   
    srand((unsigned int) time(NULL));

    // 解が存在することを保証するため偶数回の入れ替えを行う
    // ただし右下の値(0)は固定
    for ( i = 0; i < MSIZE*MSIZE-1; i++ )
    {
        j = rand() % 8;
        // 必ず入れ替えを行うために2つのmatrixは異なるものを選択する必要がある
        // "0"を選択しないように条件分岐
        if(j == i)
        {
            if(j == 0)
            {
                j = j+1;
            }else
            {
                j = j-1;
            }
        }
        swap(i/MSIZE, i%MSIZE, j/MSIZE, j%MSIZE);
    }
}


// matrix を表示する
void show()
{
    int i, j;

    for ( i = 0; i < MSIZE; i++ )
    {
        for ( j = 0; j < MSIZE; j++ )
        {
            printf("%d ", matrix[i][j]);
            if ( j == MSIZE-1 )
            {
                printf("\n"); 
            }
        }
    }
}


// matrix が0～8の順番に並び終えたかチェックする
int check()
{
    int i, j;
    // flag = 0(正解)/1(不正解)
    int flag = 0;
    for ( i = 0; i < MSIZE; i++ )
    {
        for ( j = 0; j < MSIZE; j++ )
        {
            // matrix[MSIZE-1][MSIZE-1]は0が正解であるため判定を省略
            if ( i == MSIZE-1 && j == MSIZE-1)
            {
                break;
            }

            // matrixの値が不正であればflagを更新
            if ( matrix[i][j] != (i*MSIZE+j+1) )
            {
                flag = 1;
            }
        }
    }
    return flag;
}

// キー入力(key)に従って，"0"の位置(*posx, *posy)を上下左右に移動させる
void move(char *key, int *posx, int *posy)
{
    // "a" or "A"を入力
    if ( strcmp(key, "a") == 0 || strcmp(key, "A") == 0 )
    {
        // 左へ移動可能(*posx > 0)であれば，左(posx-1)へ移動する
        if (*posx > 0)
        {
            printf("←\n");
            // "0"(posx, posy)とその左の値(posx-1,posy)を入れ替え
            swap(*posy, *posx, *posy, *posx-1);
            // "0"の位置情報を更新
            *posx -= 1;
        }
    }

    // "d" or "D" を入力
    if ( strcmp(key, "d") == 0 || strcmp(key, "D") == 0 )
    {
        // 右へ移動可能(*posx < MSIZE-1)であれば，右(posx+1)へ移動する
        if (*posx < MSIZE-1)
        {
            printf("→\n");
            // "0"(posx, posy)とその左の値(posx+1,posy)を入れ替え
            swap(*posy, *posx, *posy, *posx+1);
            // "0"の位置情報を更新
            *posx += 1;
        }
    }

    // "w" or "W" を入力
    if ( strcmp(key, "w") == 0 || strcmp(key, "W") == 0 )
    {
        // 上へ移動可能(*posy > 0)であれば，上(posy-1)へ移動する
        if (*posy > 0)
        {
            printf("↑\n");
            // "0"(posx, posy)とその上の値(posx,posy-1)を入れ替え
            swap(*posy, *posx, *posy-1, *posx);
            // "0"の位置情報を更新
            *posy -= 1;
        }
    }

    // "s" or "S" を入力
    if ( strcmp(key, "s") == 0 || strcmp(key, "S") == 0 )
    {
        // 下へ移動可能(*posy < MSIZE-1)であれば，下(posy+1)へ移動する
        if (*posy < MSIZE-1)
        {
            printf("↓\n");
            // "0"(posx, posy)とその下の値(posx,posy+1)を入れ替え
            swap(*posy, *posx, *posy+1, *posx);
            // "0"の位置情報を更新
            *posy += 1;
        }
    }
}
