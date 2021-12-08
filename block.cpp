#include "block.h"
#include "game.h"
#include <iostream>
using namespace std;

SDL_Event Game::e;
//bool Game::fall;

Block::Block(const char* texturesheet, SDL_Renderer* ren, int x, int y) :
	GameObject(texturesheet, ren, x, y)
{
	;
}

SDL_Rect Block::getdestrect() 
{
	return destrect;
}


float Block::update(bool fall,SDL_Rect a)
{
	
	srcrect.h = 16;
	srcrect.w = 16;
	srcrect.x = 0;
	srcrect.y = 0;
	

	destrect.h = 90;
	destrect.w = 90;
	float ha=0;
	
	if (!rest || !checkCollision(a,destrect))
	{
		destrect.x = xpos;
		destrect.y = ypos;

		if (!fall)
		{
			if (dire == 0)
			{
				xpos++;
			}
			else {
				xpos--;
			}
			if (xpos > 590)
			{
				dire = 1;
			}
			if (xpos < 410)
			{
				dire = 0;
			}

			int an = abs(xpos - 500);
			double x = an * 3.14159 / 180;
			ypos = 90 * cos(x);
			ha = 90 * cos(x);


		}
		else
		{

			ypos = ypos + 0.1 * time_after_press;
			time_after_press++;
		}
		float ang;
		if (dire == 0)
		{
			if (xpos < 500)
			{
				ang = ha;
			}
			else {
				ang = 180 - ha;
			}
		}
		else
		{
			if (xpos > 500)
			{
				ang = 180 - ha;
			}
			else {
				ang = ha;
			}
		}
		//cout << ang << " ";
		return ang;
	}
	else
	{
		rest = true;
		fall = false;
		destrect.x = xpos;

	}
	
}

//void Block ::render()
//{
//	SDL_RenderCopyEx(renderer, objtex, NULL, &destrect, ypos, NULL, SDL_FLIP_NONE);
//}

bool Block:: checkCollision(SDL_Rect a,SDL_Rect b)
//https://www.lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
	////The sides of the rectangles
	//int leftA, leftB;
	//int rightA, rightB;
	//int topA, topB;
	//int bottomA, bottomB;

	////Calculate the sides of rect A

	//leftA = a.x;
	//rightA = a.x + a.w;
	//topA = a.y;
	//
	//bottomA = a.y + a.h;
	///*leftA = destrect.x;
	//rightA = destrect.x + destrect.w;
	//topA = destrect.y;
	//
	//bottomA = destrect.y + destrect.h;*/

	//////Calculate the sides of rect B
	//////SDL_Rect b = destrect;
	//leftB = destrect.x;
	//cout << "left a is " << leftA << " " << endl;
	//cout << "left b is " << leftB << " " << endl;
	//rightB = destrect.x + destrect.w;
	//topB = destrect.y;
	//cout << "top a is " << topA << " " << endl;
	//cout << "top b is " << topB << " " << endl;
	//bottomB = destrect.y + destrect.h;
	///*leftB = a.x;
	//cout << "left a is " << leftA << " " << endl;
	//cout << "left b is " << leftB << " " << endl;
	//rightB = a.x + a.w;
	//topB = a.y;
	//cout << "top a is " << topA << " " << endl;
	//cout << "top b is " << topB << " " << endl;
	//bottomB = a.y + a.h;*/

	////If any of the sides from A are outside of B
	//if (bottomA <= topB)
	//{
	//	return false;
	//}

	//if (topA >= bottomB)
	//{
	//	return false;
	//}

	//if (rightA <= leftB)
	//{
	//	return false;
	//}

	//if (leftA >= rightB)
	//{
	//	return false;
	//}
	//if (bottomB <= 400) return true;
	////If none of the sides from A are outside B
	//return true;
//}