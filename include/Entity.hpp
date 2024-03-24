#ifndef ENTITY_HPP
#define ENTITY_HPP
//#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(int x, int y, SDL_Texture* p_tex);
	int getX();
	int getY();
	void setXY(int a, int b);
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	void setCurrentFrame(int a, int b);
	void printhi();
private:
	int x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
#endif