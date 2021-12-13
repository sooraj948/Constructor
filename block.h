#pragma once
#include "gameobject.h"
//#pragma once

class Block : public GameObject
{
private:
	int dire = 0;//for direction
	int time_after_press = 0;
	bool rest = false;
	//bool landed = false;
	vector <Block*> landed_blocks;
public:
	Block(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	float update(bool fall,SDL_Rect a);
	//void render();
	bool checkCollision(SDL_Rect a,SDL_Rect b);
	SDL_Rect getdestrect(); 
	void setrest() { rest = true; }
	void godown(int y);
};

