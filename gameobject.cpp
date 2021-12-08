#include "gameobject.h"
#include "texture.h"
#include <math.h>

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren,int x,int y)
{
	destrect = { 0 };
	srcrect = { 0 };
	renderer = ren;
	objtex = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x; ypos = y;
}

void GameObject::update()
{
	/*xpos = 0; ypos = 0;*/
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = ypos;
	
	/*destrect.h = 2 * srcrect.h;
	destrect.w = 2 * srcrect.w;*/
	/*destrect.h = 200;
	destrect.w = 200;
	xpos++;
	ypos = pow((xpos*xpos - 5*5),0.5);*/
}

void GameObject::render()
{
	
	SDL_RenderCopy(renderer, objtex, NULL , &destrect);
}