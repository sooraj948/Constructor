#include "texture.h"
#include "SDL_ttf.h"
#include "iostream"
using namespace std;

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* renderer)
{
	TTF_Font* gFont = NULL;
	SDL_Texture* block;
	SDL_Surface* tmpsurface = IMG_Load(filename);
	block = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	return block;
};

SDL_Texture* TextureManager::LoadText(const char* text, SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont("Sans.ttf", 50);
	cout << text << endl;
	// this is the color in rgb format,
	// maxing out all would give you the color white,
	// and it will be your text's color
	SDL_Color Col = { 255, 0, 0 };

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, Col);
	SDL_Texture* board;
	board = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return board;
};
