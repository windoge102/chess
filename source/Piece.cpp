//#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include "Entity.hpp"
#include "Piece.hpp"

Piece::Piece(int x, int y, SDL_Texture* p_tex) : Entity(x, y, p_tex) {
	//select = false;
	color = true; //possibleMoves = {};// true will be white, false will be black
}
/*void Piece::setSelect() {
	if (select == false) {select = true; }
	else {select = false; }
}*/

void Piece::setColor(bool a) {
	color = a;
}

bool Piece::getColor() {
	return color;
}