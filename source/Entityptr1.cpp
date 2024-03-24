#include "Entityptr1.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Entityptr1::Entityptr1(int p_x, int p_y, int p_y1, SDL_Texture* p_tex)
:x(p_x), y(p_y), y1(p_y1), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 64;
	currentFrame.h = 64;
}

Entityptr1::~ Entityptr1()
{}

void Entityptr1::updatey()
{
	y += y1;
	//std::cout << y1 << ", " << y << std::endl;
}

int Entityptr1::getX()
{
	return x;
}

int Entityptr1::getY()
{
	return y;
}

SDL_Texture* Entityptr1::getTex()
{
	return tex;
}

SDL_Rect Entityptr1::getCurrentFrame()
{
	return currentFrame;
}