/*
 * imagedata.h
 */
#define HEIGHT 384
#define WIDTH 384

extern unsigned char img[HEIGHT][WIDTH][3];
extern unsigned char out[HEIGHT][WIDTH][3];
extern unsigned char header[54];

extern int read_image(char* filename);
extern int write_image(char* filename);
