#include "game.h"
#include "texture.h"
#include "gameobject.h"

GameObject* player;
SDL_Texture* block;
SDL_Rect srcR, destR;
//int count = 0;
Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title)
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;

			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(window);
			}
		}
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	/*SDL_Surface* tmpsurface = IMG_Load("images/block_paint.png");
	block = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);*/
	//block = TextureManager::LoadTexture("images/block_paint.png",renderer);
	player = new GameObject("images/block-rope.png", renderer,69,69);
	return success;
}

void Game::handleevents()
{
	//bool quit = false;
	

	//Event handler
	SDL_Event e;
	SDL_PollEvent(&e) ;
		if (e.type == SDL_QUIT)
		{
			isrunning = false;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym) fall = true;
		}
	

}


void Game::render()
{
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, block,NULL,&destR);
	player->render();
	SDL_RenderPresent(renderer);
}

void Game:: update()
{
	player->update();
	/*static int flag = 0;
	if (count > 500)
	{
		flag = 1;
	}
	if (count == 0) flag = 0;
		
	if (!flag) count++;
	else count--;
	destR.h = 300;
	destR.w = 300;

	destR.x = count;*/
	//destR.y = count;
	//cout << count;
}
