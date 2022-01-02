#include "game.h"
#include <iostream>
#include <vector>
#include "block.h"
#include "Display.h"
using namespace std;
Display::Display(const char* text, SDL_Renderer* ren, int x, int y) :
	GameObject(text, ren, x, y)
{
	destrect = { 0 };
	srcrect = { 0 };
	renderer = ren;
	objtex = TextureManager::LoadText(text, ren);
	xpos = x; ypos = y;
	destrect.x = xpos;
	destrect.y = ypos;

}
SDL_Rect Display::getdestrect()
{
	return destrect;
}

float Display::update()
{
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;


	destrect.h = 90;
	destrect.w = 90;
	destrect.x = xpos;
	destrect.y = ypos;
	return 0;

}

void Display::render()
{

	SDL_RenderCopy(renderer, objtex, NULL, &destrect);
}