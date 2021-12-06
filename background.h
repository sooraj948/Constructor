#pragma once
#include "gameobject.h"


class Background : public GameObject
{
private:
	

public:
	Background(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update();

};
