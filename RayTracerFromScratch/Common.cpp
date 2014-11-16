
#include "Common.h"

void savebmp_mem(unsigned char *img,unsigned char *filedata, int filesize){
        
        unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
        unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};;
       
        /* Construct header with filesize part */
        bmpfileheader[ 2] = (unsigned char)(filesize    );
        bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
        bmpfileheader[ 4] = (unsigned char)(filesize>>16);
        bmpfileheader[ 5] = (unsigned char)(filesize>>24);
        
        /* Construct header with width and height part */
        bmpinfoheader[ 4] = (unsigned char)(       WIDTH    );
        bmpinfoheader[ 5] = (unsigned char)(       WIDTH>> 8);
        bmpinfoheader[ 6] = (unsigned char)(       WIDTH>>16);
        bmpinfoheader[ 7] = (unsigned char)(       WIDTH>>24);
        bmpinfoheader[ 8] = (unsigned char)(       HEIGHT    );
        bmpinfoheader[ 9] = (unsigned char)(       HEIGHT>> 8);
        bmpinfoheader[10] = (unsigned char)(       HEIGHT>>16);
        bmpinfoheader[11] = (unsigned char)(       HEIGHT>>24);
        
        memcpy(filedata, bmpfileheader, 14);
        memcpy(filedata+14, bmpinfoheader, 40);
        memcpy(filedata+54, img, filesize-54);

}
