
#pragma once
#include "gameobject.h"


class Gameover : public GameObject
{
private:


public:
	Gameover(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update();

};

