#pragma once
#include "gameobject.h"


class Background : public GameObject
{
private:
	int a=0;
	

public:
	Background(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update();
	void godown(int y);

};
