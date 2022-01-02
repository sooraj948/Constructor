#pragma once
#include "gameobject.h"


class Rope : public GameObject#pragma once
#include "gameobject.h"


class Rope : public GameObject
{
private:
	int dire = 0;//for direction
	int time_after_press = 0;
protected:
	int ang = 0;

public:
	Rope(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update(float ypos,int v);
	void render();
};
/*
{
private:
	int dire = 0;//for direction
	int time_after_press = 0;
protected:
	int ang = 0;

public:
	Rope(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void update(float ypos);
	void render();
};
*/
