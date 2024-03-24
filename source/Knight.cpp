#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Knight.hpp"
//#include "RenderWindow.hpp"

Knight::Knight(int x, int y, SDL_Texture* p_tex) : Piece(x, y, p_tex) {
	select = false; move = false;
}
void Knight::setSelectT(vector<int> &c) {
	//if (select == true) {select = false; possibleMoves.clear(); }
	if (select == false) {select = true; setPossibleMoves(c); }
}
void Knight::setSelectF() {
	if (select == true) {select = false; possibleMoves.clear(); }
}
void Knight::setPossibleMoves(vector<int> &c) {
	int a, b; a = this->getX(); b = this->getY(); possibleMoves.clear();
	if (move == false) { bool available = true;

		//for (unsigned int i = 0; i < c.size(); i += 2) {
		//	if ((a-64)==c[i] && (b-128)==c[i+1]) {available = false;}
		//}

		//if (available == true)
		//	{possibleMoves.push_back(a - 64); possibleMoves.push_back(b - 128);}
		//else {available = true;}
		if (checkFreeSquare(c, a - 64, b - 128) == true) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b - 128);}

		//for (unsigned int i = 0; i < c.size(); i += 2) {
		//	if ((a-64)==c[i] && (b+128)==c[i+1]) {available = false;}
		//}
		//if (available == true)
		//	{possibleMoves.push_back(a - 64); possibleMoves.push_back(b + 128);}
		//else {available = true;}
		if (checkFreeSquare(c, a - 64, b + 128) == true) {possibleMoves.push_back(a - 64); possibleMoves.push_back(b + 128);}


		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a+64)==c[i] && (b-128)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a + 64); possibleMoves.push_back(b - 128);}
		else {available = true;}*/
		if (checkFreeSquare(c, a + 64, b - 128) == true) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b - 128);}

		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a+64)==c[i] && (b+128)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a + 64); possibleMoves.push_back(b + 128);}
		else {available = true;}*/
		if (checkFreeSquare(c, a + 64, b + 128) == true) {possibleMoves.push_back(a + 64); possibleMoves.push_back(b + 128);}	


		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a-128)==c[i] && (b-64)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a - 128); possibleMoves.push_back(b - 64);}
		else {available = true;}*/
		if (checkFreeSquare(c, a - 128, b - 64) == true) {possibleMoves.push_back(a - 128); possibleMoves.push_back(b - 64);}


		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a-128)==c[i] && (b+64)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a - 128); possibleMoves.push_back(b + 64);}
		else {available = true;}*/
		if (checkFreeSquare(c, a - 128, b + 64) == true) {possibleMoves.push_back(a - 128); possibleMoves.push_back(b + 64);}


		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a+128)==c[i] && (b-64)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a + 128); possibleMoves.push_back(b - 64);}
		else {available = true;}*/
		if (checkFreeSquare(c, a + 128, b - 64) == true) {possibleMoves.push_back(a + 128); possibleMoves.push_back(b - 64);}


		/*for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((a+128)==c[i] && (b+64)==c[i+1]) {available = false;}
		}
		if (available == true)
			{possibleMoves.push_back(a + 128); possibleMoves.push_back(b + 64);}
		else {available = true;}*/
		if (checkFreeSquare(c, a + 128, b + 64) == true) {possibleMoves.push_back(a + 128); possibleMoves.push_back(b + 64);}
	}
}

//iterate through iterative list to find piece position
bool Knight::checkFreeSquare(vector<int> &c, int targetX, int targetY) {
	bool avail = true;
	for (unsigned int i = 0; i < c.size(); i += 2) {
			if ((targetX)==c[i] && (targetY)==c[i+1]) {avail = false;}
		}
	return avail;
} 