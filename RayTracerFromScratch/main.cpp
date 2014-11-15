//Using SDL and standard IO
#include <SDL.h>
#include "Common.h"
#include <memory.h>
#include "RayTracer.h"

//The window we'll be rendering to
SDL_Window* window = NULL;    
//The surface contained by the window
SDL_Renderer* sdlRenderer = NULL;

unsigned char *img = NULL;
unsigned char *filedata = NULL;

int main( int argc, char* args[] )
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}
	
    //Create window & sdlRenderer
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_SWSURFACE | SDL_RENDERER_ACCELERATED, &window, &sdlRenderer );
    if( window == NULL )
    {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}
	if( sdlRenderer == NULL )
    {
		printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);


    RayTracer rayTracer = RayTracer();
    img = (unsigned char *)malloc(3*WIDTH*HEIGHT);
    memset(img,0,sizeof(img));
    int filesize = 54 + 3*WIDTH*HEIGHT;
    if(filedata){ free(filedata); }
    filedata = (unsigned char *)malloc(filesize);


    rayTracer.render(img);

    SDL_RWops *rw;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    savebmp_mem(img, filedata, filesize);
    

        printf("%d\n", filedata[54+(0+0)*3+2]);
    rw = SDL_RWFromMem(filedata, 54+(3*WIDTH*HEIGHT));
    bitmapSurface = SDL_LoadBMP_RW(rw, 0);
    bitmapTex = SDL_CreateTextureFromSurface(sdlRenderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    SDL_RenderClear(sdlRenderer);
    SDL_RenderCopy(sdlRenderer, bitmapTex, NULL, NULL);
	SDL_RenderPresent(sdlRenderer);


	/* Starting Main loop */
	SDL_Event event;
	int loop = 1;
	while( loop ){
		while( SDL_PollEvent(&event) ) 
			switch(event.type){
			case SDL_MOUSEBUTTONDOWN:
				printf("Mouse Pressed Down\n");
				break;
			case SDL_KEYDOWN:
				printf("Key Pressed Down\n");
				break;
			case SDL_QUIT:
				printf("Quitting\n");
				loop = 0;		/* Exit Loop */
				break;
			}
	}

	//Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}