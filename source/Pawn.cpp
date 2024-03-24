#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Pawn.hpp"
//#include "RenderWindow.hpp"

Pawn::Pawn(int x, int y, SDL_Texture* p_tex) : Piece(x, y, p_tex) {
	select = false; move = false;
}
void Pawn::setSelectT(std::vector<int> &c) {
	//if (select == true) {select = false; possibleMoves.clear(); }
	if (select == false) {select = true; setPossibleMoves(c); }
}
void Pawn::setSelectF() {
	if (select == true) {select = false; possibleMoves.clear(); }
}
void Pawn::setPossibleMoves(std::vector<int> &c) {
	int a, b; a = this->getX(); b = this->getY(); possibleMoves.clear(); bool available = true;
	if (move == false) {
		if (getColor() == true) {
			cout << getColor();
			/*for (unsigned int i = 0; i < c.size(); i+=2) {
				if (a==c[i] && (b-64)==c[i+1]) {
					available = false;
				}
			}
			if (available == true) {
				possibleMoves.push_back(a); possibleMoves.push_back(b - 64);
				}*/

			if (checkFreeSquare(c, a, b - 64) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b - 64);}


			/*for (unsigned int i = 0; i < c.size(); i+=2) {
				if (a==c[i] && (b-128)==c[i+1]) {
					available = false;
				}
			}
			if (available == true) {
				possibleMoves.push_back(a); possibleMoves.push_back(b - 128);
			}*/
			if (checkFreeSquare(c, a, b - 128) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b - 128);}

			//Pawn Capture
			if (checkFreeSquare(c, a - 64, b - 64) == false) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b - 64);}
			if (checkFreeSquare(c, a + 64, b - 64) == false) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b - 64);}
		}

		else {
			if (checkFreeSquare(c, a, b + 64) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b + 64);}
			if (checkFreeSquare(c, a, b + 128) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b + 128);}

			//Pawn Capture
			if (checkFreeSquare(c, a - 64, b + 64) == false) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b + 64);}
			if (checkFreeSquare(c, a + 64, b + 64) == false) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b + 64);}
		} 
	}
}

//iterate through iterative list to find piece position
bool Pawn::checkFreeSquare(vector<int> &c, int targetX, int targetY) {
	bool avail = true;
	for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((targetX)==c[i] && (targetY)==c[i+1]) {avail = false;}
		}
	return avail;
} 