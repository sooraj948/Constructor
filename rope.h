#pragma once
#include "gameobject.h"


class Rope : public GameObject
{
private:
	int dire = 0;//for direction
	int time_after_press = 0;

public:
	Rope(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update(float ypos);
	void render();
};
