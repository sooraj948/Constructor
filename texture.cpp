#include "texture.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename,SDL_Renderer* renderer)
{
	SDL_Texture* block;
	SDL_Surface* tmpsurface = IMG_Load(filename);
	block = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	return block;
 }