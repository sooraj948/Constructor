#include "background2.h"
#include <iostream>
using namespace std;
Background2::Background2(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

void  Background2::update(int d)
{
	xpos = 0; ypos = 0;
	srcrect.h = 0;
	srcrect.w = 0;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = d-600;
	
	/*destrect.h = srcrect.h;
	destrect.w =  srcrect.w;*/
	destrect.h = 600;
	destrect.w = 1000;




}
