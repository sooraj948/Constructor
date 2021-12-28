#pragma once
#include "game.h"
#include "texture.h"
#include "gameobject.h"
#include "block.h"
#include "background.h"
#include "rope.h"
#include "Heart.h"
#include "gameover.h"
#include <vector>
//#pragma pack(1)
Heart* heart1,*heart2,*heart3;
Gameover* gameover1;
Block* block1;
Rope* rope;
SDL_Texture* block;
Background* bg;
SDL_Rect srcR, destR;
vector <Block*> landed_blocks;
Block* block2;
//int count = 0;
Game::Game()
{
	landed = false;
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

	//block = TextureManager::LoadTexture("images/block_paint.png",renderer);
	//bg = TextureManager::LoadTexture("images/background.png", renderer);
	bg = new Background("images/background.png", renderer, 0, 0);
	block2 = new Block("images/block.png", renderer, 430, 400);
	block2->setrest();
	landed_blocks.push_back(block2);
	block1 = new Block("images/block-rope.png", renderer, 410, 0);
	rope = new Rope("images/hook.png", renderer, 500, 0);
	heart1 = new Heart("images/heart.png", renderer, 900, 20);
	heart2 = new Heart("images/heart.png", renderer, 930, 20);
	heart3 = new Heart("images/heart.png", renderer, 870, 20);
	gameover1 = new Gameover("images/gameover.png", renderer, 0, 0);
	/*block2 = new Block("images/block-rope.png", renderer, 410, 0);*/
	landed = false;
	return success;
}

void Game::handleevents()
{
	//bool quit = false;


	//Event handler

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		isrunning = false;
	}
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_SPACE) fall = true;
	}


}


void Game::render()
{
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, block,NULL,&destR);
	if (gameover == 0)
	{
		gameover1->render();
		SDL_RenderPresent(renderer);
		return;

	}
	bg->render();
	if (lives == 0)
	{

		heart1->render();
		heart2->render();
		heart3->render();
	}
	else if (lives == 1)
	{

		heart1->render();
		heart2->render();
	}
	else if (lives == 2)
	{
		heart1->render();
	}
	block1->render();

	rope->render();
	/*for (Block* i : landed_blocks)
	{
		i->render();
	}*/
	//block2->render();
	for (Block* b : landed_blocks)
	{
		b->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	if (gameover == 0)
	{
		gameover1->update();
		return;
	}
	bg->update();
	float y = block1->update(fall, landed_blocks[landed_blocks.size() - 1]->getdestrect());
	//float y = block1->update(fall, block2->destrect);
	//for (Block* i : landed_blocks)
	//{
	//	i->update(false,i->getdestrect());//this i am not so sure abt
	//}

	block2->update(false, block1->destrect);
	rope->update(y);

	if (y == -1)
	{
		int a = 0,b=0;
		for (int i = 0; i < landed_blocks.size(); i++)
		{
			a += landed_blocks[i]->getdestrect().x;
		}
		int Block2 = landed_blocks[landed_blocks.size() - 1]->getdestrect().x;//check this
		/*int Block2 =0;
		if (landed_blocks.size() - 2>=0) Block2 = landed_blocks[landed_blocks.size() - 2]->getdestrect().x;
		*/if (abs(block1->getdestrect().x - Block2) > 45)
		{
			cout <<"block collapse" << endl;
			lives++;
			if (lives >= 3)
			{
				b = 1;
				cout << lives << " gamover e";
				gameover = 0;
			}
		}
		else {
			landed_blocks.push_back(block1);
			a += block1->getdestrect().x;
			a = a / landed_blocks.size();
			if (abs(a - landed_blocks[0]->getdestrect().x) > 45)
			{
				b = 1;
				cout << "building fall" << endl;
				gameover = 0;
			}
		}

		
		if (b == 0) {
			block1 = new Block("images/block-rope.png", renderer, 410, 0);
			rope = new Rope("images/hook.png", renderer, 500, 0);
			fall = false;
		}
		/*landed = false;*/
	}
	if (y == -2)
	{
		int b = 0;
		lives++;
		if (lives > 3)
		{
			b = 1;
			cout << "game over t" << endl;
			gameover = 0;
		}
		if (b == 0) {
			block1 = new Block("images/block-rope.png", renderer, 410, 0);
			rope = new Rope("images/hook.png", renderer, 500, 0);
			fall = false;
		}
	}
	cout << lives << endl;
	if (lives == 0)
	{
		
		heart1->update();
		heart2->update();
		heart3->update();
	}
	else if (lives == 1)
	{
	
		heart1->update();
		heart2->update();
	}
	else if (lives == 2)
	{
		heart1->update();
	}
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

