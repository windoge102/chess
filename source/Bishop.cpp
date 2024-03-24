#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Bishop.hpp"
//#include "RenderWindow.hpp"

Bishop::Bishop(int x, int y, SDL_Texture* p_tex) : Piece(x, y, p_tex) {
	select = false; move = false;
}
void Bishop::setSelectT(vector<int> &c) {
	//if (select == true) {select = false; possibleMoves.clear(); }
	if (select == false) {select = true; setPossibleMoves(c); }
}
void Bishop::setSelectF() {
	if (select == true) {select = false; possibleMoves.clear(); }
}
void Bishop::setPossibleMoves(vector<int> &c) {
	int a, b; a = this->getX(); b = this->getY(); possibleMoves.clear();
	if (move == false) { bool available = true;


		for (int i = 0; i < 8; i++) {
			/*for (unsigned int i = 0; i < c.size(); i += 2) {
				if ((a-64)==c[i] && (b-64)==c[i+1]) {
					available = false;
				}
			}
			if (available == false) {break;}
			possibleMoves.push_back(a-=64); possibleMoves.push_back(b-=64);
			*/

			if (checkFreeSquare(c, a - 64, b - 64) == false) {break;}
			possibleMoves.push_back(a-=64); possibleMoves.push_back(b-=64);
		}


		available = true; a = this->getX(); b = this->getY();
		for (int i = 0; i < 8; i++) {
			/*for (unsigned int i = 0; i < c.size(); i += 2) {
				if ((a+64)==c[i] && (b+64)==c[i+1]) {
					available = false;
				}
			}
			if (available == false) {break;}
			possibleMoves.push_back(a+=64); possibleMoves.push_back(b+=64);*/
			if (checkFreeSquare(c, a + 64, b + 64) == false) {break;}
			possibleMoves.push_back(a+=64); possibleMoves.push_back(b+=64);
		}


		available = true; a = this->getX(); b = this->getY();
		for (int i = 0; i < 8; i++) {
			/*for (unsigned int i = 0; i < c.size(); i += 2) {
				if ((a-64)==c[i] && (b+64)==c[i+1]) {
					available = false;
				}
			}
			if (available == false) {break;}
			possibleMoves.push_back(a-=64); possibleMoves.push_back(b+=64);

			*/
			if (checkFreeSquare(c, a - 64, b + 64) == false) {break;}
			possibleMoves.push_back(a-=64); possibleMoves.push_back(b+=64);
		}


		available = true; a = this->getX(); b = this->getY();
		for (int i = 0; i < 8; i++) {
			/*for (unsigned int i = 0; i < c.size(); i += 2) {
				if ((a+64)==c[i] && (b-64)==c[i+1]) {
					available = false;
				}
			}
			if (available == false) {break;}
			possibleMoves.push_back(a+=64); possibleMoves.push_back(b-=64);*/
			if (checkFreeSquare(c, a + 64, b - 64) == false) {break;}
			possibleMoves.push_back(a+=64); possibleMoves.push_back(b-=64);
		}
		available = true; a = this->getX(); b = this->getY();
	}
}

//iterate through iterative list to find piece position
bool Bishop::checkFreeSquare(vector<int> &c, int targetX, int targetY) {
	bool avail = true;
	for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((targetX)==c[i] && (targetY)==c[i+1]) {avail = false;}
		}
	return avail;
} 