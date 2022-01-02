#include "rope.h"
#include "game.h"
#include <iostream>
using namespace std;

//SDL_Event Game::e;
//bool Game::fall;

Rope::Rope(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

void Rope::update(float y,int v)
{
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;
	//cout << y << " ";
	y = ang;
	double x = y * 3.14159 / 180;
	destrect.x = xpos - 45 * cos(x);
	destrect.y = abs(45 * sin(x));
	//cout << ang << "a ";
	destrect.h = 20;
	destrect.w = 75;
	if (dire == 0)
	{
		ang+=v;
	}
	else {
		ang-=v;
	}
	if (ang > 180)
	{
		dire = 1;
	}
	else if (ang < 0)
	{
		dire = 0;
	}
	
	/*
		if (dire == 0)
		{
			xpos++;
		}
		else {
			xpos--;
		}
		if (xpos > 590)
		{
			dire = 1;
		}
		if (xpos < 410)
		{
			dire = 0;
		}

		int an = abs(xpos - 500);
		double x = an * 3.14159 / 180;
		ypos = 90 * cos(x);
		xpos = 410;*/
}


void Rope::render()
{
	SDL_RenderCopyEx(renderer, objtex, NULL, &destrect, -1 * ang, NULL, SDL_FLIP_NONE);
}
