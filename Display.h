#pragma once
#include "gameobject.h"
#include "SDL_ttf.h"
#include "texture.h"

class Display : public GameObject
{
private:

public:
	Display(const char* texturesheet, SDL_Renderer* ren, int x, int y,int w);
	float update();
	//void render();
	void render();
	SDL_Rect getdestrect();


};
