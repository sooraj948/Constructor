#pragma once
#include "game.h"
class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
	~GameObject();
	void update();
	void render();
private:
	int xpos=0, ypos=0;
	SDL_Texture* objtex;
	SDL_Rect srcrect, destrect;
	SDL_Renderer* renderer;


};