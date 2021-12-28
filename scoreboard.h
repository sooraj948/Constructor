#pragma once
#include "gameobject.h"
#include "SDL_ttf.h"
#include "texture.h"

class ScoreBoard : public GameObject
{
private:
	
public:
	ScoreBoard(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	float update();
	//void render();
	void render();
	SDL_Rect getdestrect();
	
	
};