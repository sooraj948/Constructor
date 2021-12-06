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

int Block::update(bool fall)
{
	//xpos = 0; ypos = 0;
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = ypos;

	/*destrect.h = srcrect.h;
	destrect.w =  srcrect.w;*/
	destrect.h = 100;
	destrect.w = 100;
	/*xpos = xpos + 1;
	ypos = pow(((xpos-500)(xpos-500)),0.5);*/
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
		}/*
		if (xpos <= 500)
		{
			ypos = pow(((xpos - 410) * (xpos - 410)), 0.5);
		}
		else {
			ypos = pow(((590 - xpos) * (590 - xpos)), 0.5);
		}*/
		int an = xpos - 410;
		double x = an * 3.14159 / 180;
		ypos = 90 * sin(x);


	}
	else
	{
		
		ypos=ypos+0.1*time_after_press;
		time_after_press++;
	}
	
	return ypos;

}

//void Block ::render()
//{
//	SDL_RenderCopyEx(renderer, objtex, NULL, &destrect, ypos, NULL, SDL_FLIP_NONE);
//}