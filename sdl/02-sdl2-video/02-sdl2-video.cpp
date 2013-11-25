// 02-sdl2-video.cpp : SDL2 example - initialize video and display image
//

#include <stdio.h>
#include <tchar.h>
#include "SDL.h"

int _tmain(int argc, _TCHAR* argv[]) {	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		printf("Error initializing SDL:  %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		printf("%i\n", SDL_GetError());
		return 1;
	}

	SDL_Renderer *ren = nullptr;
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		printf("%i\n", SDL_GetError());
		return 1;
	}

	SDL_Surface *bmp = nullptr;
	bmp = SDL_LoadBMP("smajlik.bmp");
	if (bmp == nullptr){
		printf("%i\n", SDL_GetError());
		return 1;
	}
	
	SDL_Texture *tex = nullptr;
	tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}

