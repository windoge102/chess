#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include "Entityptr1.hpp"
#include "Piece.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);

	int getRefreshRate();

	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void render1(Piece& p_entity);
	void render2(Entity* p_entity);
	void render3(Piece* p_entity);
	void renderptr1(Entityptr1& p_entity);
	void display();
	void change(Entity& p_entity);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};