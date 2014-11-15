#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265
#define TRUE 1
#define FALSE 0
#define WIDTH       640
#define HEIGHT      400


#define min(a,b) (((a) < (b)) ? (a) : (b)) 

void savebmp_mem(unsigned char *img,unsigned char *filedata,int filesize);