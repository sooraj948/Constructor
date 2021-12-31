#include "background.h"
#include <iostream>
using namespace std;
Background::Background(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

void Background::update()
{
	
	srcrect.h = 0;
	srcrect.w = 0;
	srcrect.x = 0;
	srcrect.y = 0;
	destrect.x = xpos;
	destrect.y = ypos;
	if (ypos == 600)
	{
		ypos = -600;
	}

	
	/*destrect.h = srcrect.h;
	destrect.w =  srcrect.w;*/
	destrect.h = 600;
	destrect.w = 1000;
	

	//return ypos;

}
void Background::godown(int y)
{
	ypos += y;

	cout << ypos << endl;
}
