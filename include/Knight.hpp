#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Piece.hpp"
//#include "Entity.hpp"
//template <class T>
class Knight : public Piece {
private:
	bool select;
	bool move; // move == true if pawn has moved already, else move == false
public:
	Knight(int, int, SDL_Texture*);
	void setSelectT(vector<int> &);
	void setSelectF();
	void setPossibleMoves(vector<int> &);
	bool checkFreeSquare(vector<int> &, int, int); //iterate through iterative list to find piece position
};
#endif