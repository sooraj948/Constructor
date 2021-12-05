#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "game.h"
using namespace std;

//https://www.youtube.com/watch?v=RqvpkZ7I1aU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=6

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int framedelay = 500 / FPS;
	Uint32 framestart;
	int frametime;
	Game *game = new Game();
	game->init("My own");
	while (game->running())
	{
		framestart = SDL_GetTicks();
		game->handleevents();
		game->update();
		game->render();
		//cout << game->getcount() << endl;
		frametime = SDL_GetTicks() - framestart;
		if (framedelay > frametime)
		{
			SDL_Delay(framedelay - frametime);
		}

	}
	return 0;
}