#ifndef PIECE_HPP
#define PIECE_HPP
//#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Entity.hpp"
using namespace std;
class Piece : public Entity {
private:
	//bool select; // is the piece selected?
	bool color;
public:
	std::vector<int> possibleMoves; // even index = x coordinate, odd = y coordinate
	Piece(int, int, SDL_Texture*);
	virtual void setSelectT(vector<int> &) = 0; //change the bool value of select;
	virtual void setSelectF() = 0;
	void setColor(bool a);
	bool getColor();
	virtual void setPossibleMoves(vector<int> &) = 0; //change values based on piece position
	virtual bool checkFreeSquare(vector<int> &, int, int) = 0; //iterate through iterative list to find piece position
};
#endif