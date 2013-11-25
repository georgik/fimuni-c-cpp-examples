// sdl2-sample.cpp : SDL2 example - initialize and quit
//

#include <tchar.h>
#include "SDL.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);	
	SDL_Quit();
	return 0;
}

