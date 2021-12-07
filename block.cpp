#include "block.h"
#include "game.h"
#include <iostream>
using namespace std;

SDL_Event Game::e;
//bool Game::fall;

Block::Block(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

float Block::update(bool fall)
{

	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = ypos;


	destrect.h = 90;
	destrect.w = 90;
	float ha=0;
	if (!fall)
	{
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
	    ha = 90 * cos(x);


	}
	else
	{
		
		ypos=ypos+0.1*time_after_press;
		time_after_press++;
	}
	float ang;
	if (dire == 0)
	{
		if (xpos < 500)
		{
			ang = ha;
		}
		else {
			ang = 180 - ha;
		}
	}
	else
	{
		if (xpos > 500)
		{
			ang = 180 - ha;
		}
		else {
			ang = ha;
		}
	}
	//cout << ang << " ";
	return ang;

}

//void Block ::render()
//{
//	SDL_RenderCopyEx(renderer, objtex, NULL, &destrect, ypos, NULL, SDL_FLIP_NONE);
//}
