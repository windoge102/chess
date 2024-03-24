#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "King.hpp"
//#include "RenderWindow.hpp"

King::King(int x, int y, SDL_Texture* p_tex) : Piece(x, y, p_tex) {
	select = false; move = false;
}
void King::setSelectT(std::vector<int> &c) {
	//if (select == true) {select = false; possibleMoves.clear(); }
	if (select == false) {select = true; setPossibleMoves(c); }
}
void King::setSelectF() {
	if (select == true) {select = false; possibleMoves.clear(); }
}
void King::setPossibleMoves(std::vector<int> &c) {
	int a, b; a = this->getX(); b = this->getY(); possibleMoves.clear(); bool available = true;
	if (move == false) {
		//Up one
		/*for (unsigned int i = 0; i < c.size(); i+=2) {
			if (a==c[i] && (b-64)==c[i+1]) {
				available = false;
			}
		}
		if (available == true) {
			possibleMoves.push_back(a); possibleMoves.push_back(b - 64);
		}*/
		if (checkFreeSquare(c, a, b - 64) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b - 64);}

		//Down
		/*available = true;
		for (unsigned int i = 0; i < c.size(); i+=2) {
			if (a==c[i] && (b+64)==c[i+1]) {
				available = false;
			}
		}
		if (available == true) {
			possibleMoves.push_back(a); possibleMoves.push_back(b + 64);
		}*/
		if (checkFreeSquare(c, a, b + 64) == true) {possibleMoves.push_back(a); possibleMoves.push_back(b + 64);}


		//Left
		/*available = true;
		for (unsigned int i = 0; i < c.size(); i+=2) {
			if ((a-64)==c[i] && (b)==c[i+1]) {
				available = false;
			}
		}
		if (available == true) {
			possibleMoves.push_back(a - 64); possibleMoves.push_back(b);
		}*/
		if (checkFreeSquare(c, a - 64, b) == true) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b);}

		//Right
		/*available = true;
		for (unsigned int i = 0; i < c.size(); i+=2) {
			if ((a+64)==c[i] && (b)==c[i+1]) {
				available = false;
			}
		}
		if (available == true) {
			possibleMoves.push_back(a + 64); possibleMoves.push_back(b);
		}*/
		if (checkFreeSquare(c, a + 64, b) == true) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b);}

		//Diagonals
		if (checkFreeSquare(c, a + 64, b + 64) == true) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b + 64);}
		if (checkFreeSquare(c, a - 64, b + 64) == true) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b + 64);}
		if (checkFreeSquare(c, a + 64, b - 64) == true) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b - 64);}
		if (checkFreeSquare(c, a - 64, b - 64) == true) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b - 64);}

	}
}

//iterate through iterative list to find piece position
bool King::checkFreeSquare(vector<int> &c, int targetX, int targetY) {
	bool avail = true;
	for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((targetX)==c[i] && (targetY)==c[i+1]) {avail = false;}
		}
	return avail;
} 