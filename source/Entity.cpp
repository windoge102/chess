#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Entity::Entity(int p_x, int p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 64;
	currentFrame.h = 64;
}
int Entity::getX() { return x; }
int Entity::getY() { return y; }
void Entity::setXY(int a, int b) { x = a; y = b; }
//void Entity::setXY(int a, int b) { currentFrame.x = a; currentFrame.y = b; }
SDL_Texture* Entity::getTex() { return tex; }
SDL_Rect Entity::getCurrentFrame() { return currentFrame; }
void Entity::setCurrentFrame(int a, int b) { currentFrame.w = a; currentFrame.h = b; }
//void Entity::printhi() { std::cout << "hi" << std::endl; }
