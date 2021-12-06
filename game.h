#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "SDL_image.h"
using namespace std;
class Game
{
public:
	Game();
	~Game();
	void handleevents();
	void update();
	void render();
	bool running() { return isrunning; }
	bool init(const char * title);
	int getcount() { return count; }
	static SDL_Event e;
	//bool static fall;

private:
	bool isrunning=true,fall=false;
	SDL_Window* window;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Renderer* renderer;
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 640;
	int count = 0;
};