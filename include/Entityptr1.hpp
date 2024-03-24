#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entityptr1
{
public:
	Entityptr1(int x, int y, int y1, SDL_Texture* p_tex);
	~ Entityptr1();
	void updatey();
	int getX();
	int getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	int x, y, y1;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};