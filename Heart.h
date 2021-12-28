
#pragma once
#include "gameobject.h"


class Heart : public GameObject
{
private:


public:
	Heart(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update();

};
