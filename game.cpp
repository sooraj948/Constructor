#pragma once

#include "game.h"
#include "texture.h"
#include "gameobject.h"
#include "block.h"
#include "background.h"
#include "rope.h"
#include "Heart.h"
#include "gameover.h"
#include "scoreboard.h"
#include "music.h"
#include "fstream"
#include "Display.h"
#include <string>
#include <vector>
//#pragma pack(1)
ScoreBoard* scoreboard;
Heart* heart1, * heart2, * heart3;
Display* dis1, * dis2, * dis3, * dis4;
Gameover* gameover1;
Block* block1;
Rope* rope;
SDL_Texture* block;
Background* bg1, * bg2;
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

		if (TTF_Init() == -1) {
			printf("TTF_Init: %s\n", TTF_GetError());
			exit(2);
		}

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

	bg1 = new Background("images/ha.jpg", renderer, 0, 0);
	bg2 = new Background("images/ha.jpg", renderer, 0, -600);
	block2 = new Block("images/block.png", renderer, 465, 400);
	block2->setrest();
	landed_blocks.push_back(block2);
	block1 = new Block("images/block-rope.png", renderer, 410, 0);
	rope = new Rope("images/hook.png", renderer, 500, 0);
	heart1 = new Heart("images/heart.png", renderer, 900, 20);
	heart2 = new Heart("images/heart.png", renderer, 930, 20);
	heart3 = new Heart("images/heart.png", renderer, 870, 20);
	dis1 = new Display("High score", renderer, 300, 400);
	dis3 = new Display("0", renderer, 200, 400);//highscore
	dis4 = new Display("Score", renderer, 300, 200);
	dis2 = new Display("Scorwe", renderer, 200, 600);//score
	gameover1 = new Gameover("images/gameover.png", renderer, 0, 0);

	scoreboard = new ScoreBoard("0", renderer, 0, 0);
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
		dis1->render();
		dis2->render();
		dis3->render();
		dis4->render();
		SDL_RenderPresent(renderer);
		return;

	}
	bg1->render();
	bg2->render();
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

	//block2->render();
	for (Block* b : landed_blocks)
	{
		b->render();
	}
	scoreboard->render();
	SDL_RenderPresent(renderer);
}

void Game::update()
{
	int v;
	if (landed_blocks.size() > 10)
	{
		v = 2;
	}
	else
	{
		v = 1;
	}
	if (gameover == 0)
	{
		gameover1->update();
		dis1->update();
		dis2->update();
		dis3->update();
		dis4->update();
		gameover1->update();

		return;
	}
	bg1->update();
	bg2->update();
	float y = block1->update(fall, landed_blocks[landed_blocks.size() - 1]->getdestrect(), v);
	//float y = block1->update(fall, block2->destrect);
	//for (Block* i : landed_blocks)
	//{
	//	i->update(false,i->getdestrect());//this i am not so sure abt
	//}

	//block2->update(false, block1->destrect);
	rope->update(y, v);
	scoreboard->update();
	for (int i = 0; i < landed_blocks.size(); i++)
	{

		landed_blocks[i]->update(false, block1->destrect, v);

	}
	if (y == -1)
	{
		int a = 0, b = 0;
		for (int i = 0; i < landed_blocks.size(); i++)
		{
			a += landed_blocks[i]->getdestrect().x;

		}
		int Block2 = landed_blocks[landed_blocks.size() - 1]->getdestrect().x;//check this
		/*int Block2 =0;
		if (landed_blocks.size() - 2>=0) Block2 = landed_blocks[landed_blocks.size() - 2]->getdestrect().x;
		*/if (abs(block1->getdestrect().x - Block2) > 45)
		{
			cout << "block collapse" << endl;//check if the block fell on the side of the previous block and thus could not stay on
			lives++;
			mu(0);
			if (lives >= 3)
			{
				b = 1;
				cout << lives << " gamover e";
				gameover = 0;
				std::ifstream input("HighScore.txt");
				int high_score;
				input >> high_score;
				cout << high_score;
				dis3 = new Display(to_string(high_score).c_str(), renderer, 400, 100);
				dis2 = new Display(to_string(landed_blocks.size()-1).c_str(), renderer, 100, 300);//score
				std::ofstream output("HighScore.txt");
				if (landed_blocks.size() > high_score)
				{
					output << landed_blocks.size();
				}
				cout << landed_blocks.size() << endl;
				mu(3);
			}
		}
		else {
			if ((abs(block1->getdestrect().x - Block2) <= 10))
			{
				mu(2);
			}
			else {
				mu(1);
			}
			landed_blocks.push_back(block1);
			cout << "bg1 " << endl;
			bg1->godown(50);
			cout << "bg2 " << endl;
			bg2->godown(50);
			for (Block* b : landed_blocks)
			{
				b->godown(65);
			}

			a += block1->getdestrect().x;
			a = a / landed_blocks.size();
			if (abs(a - landed_blocks[0]->getdestrect().x) > 45)
			{
				b = 1;
				cout << "building fall" << endl;
				gameover = 0;
				std::ifstream input("HighScore.txt");
				int high_score;
				input >> high_score;
				std::ofstream output("HighScore.txt");
				if (landed_blocks.size() > high_score)
				{
					output << landed_blocks.size();
				}
				cout << landed_blocks.size() << endl;
				mu(3);
			}
		}


		if (b == 0) {
			block1 = new Block("images/block-rope.png", renderer, 410, 0);
			rope = new Rope("images/hook.png", renderer, 500, 0);
			cout << "score " << to_string(landed_blocks.size() - 1).c_str() << endl;
			scoreboard = new ScoreBoard(to_string(landed_blocks.size() - 1).c_str(), renderer, 0, 0);
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
			std::ifstream input("HighScore.txt");
			int high_score;
			input >> high_score;
			std::ofstream output("HighScore.txt");
			if (landed_blocks.size() > high_score)
			{
				output << landed_blocks.size();
			}
			cout << landed_blocks.size() << endl;
			mu(3);
		}
		if (b == 0) {
			block1 = new Block("images/block-rope.png", renderer, 410, 0);
			rope = new Rope("images/hook.png", renderer, 500, 0);
			scoreboard = new ScoreBoard(to_string(landed_blocks.size() - 1).c_str(), renderer, 0, 0);
			fall = false;
		}
	}
	//cout << lives << endl;
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
