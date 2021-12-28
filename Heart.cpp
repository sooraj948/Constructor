#include "Heart.h"
#include <iostream>
using namespace std;
Heart::Heart(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

void Heart::update()
{
	//xpos = 0; ypos = 0;
	srcrect.h = 0;
	srcrect.w = 0;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = ypos;

	/*destrect.h = srcrect.h;
	destrect.w =  srcrect.w;*/
	destrect.h = 30;
	destrect.w = 30;


	//return ypos;

}