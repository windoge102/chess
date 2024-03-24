#ifndef ROOK_HPP
#define ROOK_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Piece.hpp"
//#include "Entity.hpp"
//template <class T>
class Rook : public Piece {
private:
	bool select;
	bool move; // move == true if pawn has moved already, else move == false
public:
	Rook(int, int, SDL_Texture*);
	void setSelectT(vector<int> &);
	void setSelectF();
	void setPossibleMoves(vector<int> &);
	bool checkFreeSquare(vector<int> &, int, int); //iterate through iterative list to find piece position
};
#endif