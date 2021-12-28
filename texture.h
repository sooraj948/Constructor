#pragma once
#include "game.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename,SDL_Renderer* ren);
	static SDL_Texture* LoadText(const char* text, SDL_Renderer* ren);
private:

};
