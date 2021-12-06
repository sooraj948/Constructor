#pragma once
#include "gameobject.h"


class Block : public GameObject
{
private:
	int dire = 0;//for direction
	int time_after_press = 0;

public:
	Block(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	int update(bool fall);
	//void render();
};