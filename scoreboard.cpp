#include "game.h"
#include <iostream>
#include <vector>
#include "block.h"
#include "scoreboard.h"
using namespace std;
ScoreBoard::ScoreBoard(const char* text, SDL_Renderer* ren, int x, int y) :
	GameObject(text, ren, x, y)
{
	destrect = { 0 };
	srcrect = { 0 };
	renderer = ren;
	objtex = TextureManager::LoadText(text, ren);
	xpos = x; ypos = y;
	destrect.x = xpos;
	destrect.y = ypos;
	//TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

	//// this is the color in rgb format,
	//// maxing out all would give you the color white,
	//// and it will be your text's color
	//SDL_Color White = { 255, 255, 255 };

	//// as TTF_RenderText_Solid could only be used on
	//// SDL_Surface then you have to create the surface first
	//SDL_Surface* surfaceMessage =
	//	TTF_RenderText_Solid(Sans, "put your text here", White);

	//// now you can convert it into a texture
	//SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//SDL_Rect Message_rect; //create a rect
	//Message_rect.x = 0;  //controls the rect's x coordinate 
	//Message_rect.y = 0; // controls the rect's y coordinte
	//Message_rect.w = 100; // controls the width of the rect
	//Message_rect.h = 100; // controls the height of the rect
}
SDL_Rect ScoreBoard::getdestrect()
{
	return destrect;
}

float ScoreBoard::update() 
{
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;


	destrect.h = 90;
	destrect.w = 90;
	destrect.x = 0;
	destrect.y = 0;
	return 0;

}

void ScoreBoard::render()
{

	SDL_RenderCopy(renderer, objtex, &srcrect, &destrect);
}