
#pragma once
#include "gameobject.h"


class Background2 : public GameObject
{
private:
	int a = 0;


public:
	Background2(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update(int d);


};
