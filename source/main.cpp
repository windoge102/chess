#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Entityptr1.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
namespace global  {	int x1;	int y1; }
int main(int argc, char* args[]) { if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "STD_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_JPG)))
		std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
	RenderWindow window("GAME v1.0", 512, 512);
	SDL_Texture* start = window.loadTexture("media/IMAGES/start.png");
	SDL_Texture* choose = window.loadTexture("media/IMAGES/choose.png");
	SDL_Texture* black = window.loadTexture("media/IMAGES/black.png");
	SDL_Texture* white = window.loadTexture("media/IMAGES/white.png");
	SDL_Texture* red = window.loadTexture("media/IMAGES/red.png");
	SDL_Texture* blackpawn = window.loadTexture("media/IMAGES/blackpawn1.png");
	SDL_Texture* whitepawn = window.loadTexture("media/IMAGES/whitepawn1.png");
	SDL_Texture* greenpawn = window.loadTexture("media/IMAGES/greenpawn1.png");
	SDL_Texture* blackrook = window.loadTexture("media/IMAGES/brook1.png");
	SDL_Texture* whiterook = window.loadTexture("media/IMAGES/wrook1.png");
	SDL_Texture* dot = window.loadTexture("media/IMAGES/dot2.png");
	SDL_Texture* blacknight = window.loadTexture("media/IMAGES/bknight1.png");
	SDL_Texture* whiteknight = window.loadTexture("media/IMAGES/wknight1.png");
	SDL_Texture* blackbishop = window.loadTexture("media/IMAGES/bbishop1.png");
	SDL_Texture* whitebishop = window.loadTexture("media/IMAGES/wbishop1.png");
	SDL_Texture* blackking = window.loadTexture("media/IMAGES/bking1.png");
	SDL_Texture* whiteking = window.loadTexture("media/IMAGES/wking1.png");
	SDL_Texture* blackqueen = window.loadTexture("media/IMAGES/bqueen1.png");
	SDL_Texture* whitequeen = window.loadTexture("media/IMAGES/wqueen1.png");
	Entity Start = Entity(0, 0, start); Start.setCurrentFrame(512, 512);
	Entity Choose = Entity(0, 0, choose); Choose.setCurrentFrame(512, 512);
	std::vector<Entity> squares = {}; std::vector<Pawn> whitepawns = {};
	std::vector<int> bPiecePositions = {}; std::vector<Piece*> allpieces = {};
	std::vector<Entity> blackpawns = {}; std::vector<Piece*> blackpieces = {};
	std::vector<Piece*> whitepieces = {}; std::vector<int> wPiecePositions = {};

	//Initializing Board / White
	int b = 0; whitepieces.push_back(new Knight(64, 448, whiteknight));
	whitepieces.push_back(new Bishop(128, 448, whitebishop)); Piece* glPP;
	wPiecePositions.push_back(64); wPiecePositions.push_back(448);
	wPiecePositions.push_back(128); wPiecePositions.push_back(448);
	whitepieces.push_back(new King(256, 448, whiteking)); wPiecePositions.push_back(256);
	wPiecePositions.push_back(448);
	whitepieces.push_back(new Queen(192, 448, whitequeen)); wPiecePositions.push_back(192);
	wPiecePositions.push_back(448);
	whitepieces.push_back(new Knight(384, 448, whiteknight)); wPiecePositions.push_back(384);
	wPiecePositions.push_back(448);
	whitepieces.push_back(new Bishop(320, 448, whitebishop)); wPiecePositions.push_back(320);
	wPiecePositions.push_back(448);
	whitepieces.push_back(new Rook(0, 448, whiterook)); wPiecePositions.push_back(0);
	wPiecePositions.push_back(448);
	whitepieces.push_back(new Rook(448, 448, whiterook)); wPiecePositions.push_back(448);
	wPiecePositions.push_back(448);

	//Initializing Board / Black
	blackpieces.push_back(new Knight(64, 0, blacknight)); bPiecePositions.push_back(64); 
	bPiecePositions.push_back(0);
	blackpieces.push_back(new Bishop(128, 0, blackbishop)); bPiecePositions.push_back(128); 
	bPiecePositions.push_back(0);
	blackpieces.push_back(new King(256, 0, blackking)); bPiecePositions.push_back(256);
	bPiecePositions.push_back(0);
	blackpieces.push_back(new Queen(192, 0, blackqueen)); bPiecePositions.push_back(192);
	bPiecePositions.push_back(0);
	blackpieces.push_back(new Knight(384, 0, blacknight)); bPiecePositions.push_back(384);
	bPiecePositions.push_back(0);
	blackpieces.push_back(new Bishop(320, 0, blackbishop)); bPiecePositions.push_back(320);
	bPiecePositions.push_back(0);
	blackpieces.push_back(new Rook(0, 0, blackrook)); bPiecePositions.push_back(0);
	bPiecePositions.push_back(448);
	blackpieces.push_back(new Rook(448, 0, blackrook)); bPiecePositions.push_back(448);
	bPiecePositions.push_back(0);

	//Initializing allPieces vector
	allpieces.push_back(new Knight(64, 448, whiteknight));
	allpieces.push_back(new Bishop(128, 448, whitebishop));
	allpieces.push_back(new King(256, 448, whiteking));
	allpieces.push_back(new Queen(192, 448, whitequeen));
	allpieces.push_back(new Knight(384, 448, whiteknight));
	allpieces.push_back(new Bishop(320, 448, whitebishop));
	allpieces.push_back(new Rook(0, 448, whiterook));
	allpieces.push_back(new Rook(448, 448, whiterook));

	allpieces.push_back(new Knight(64, 0, blacknight));
	allpieces.push_back(new Bishop(128, 0, blackbishop));
	allpieces.push_back(new King(256, 0, blackking));
	allpieces.push_back(new Queen(192, 0, blackqueen));
	allpieces.push_back(new Knight(384, 0, blacknight));
	allpieces.push_back(new Bishop(320, 0, blackbishop));
	allpieces.push_back(new Rook(0, 0, blackrook));
	allpieces.push_back(new Rook(448, 0, blackrook));

	for (int ib = 0; ib < 8; ib++) { int a = 0;
		for (int ia = 0; ia < 8; ia++) { int c = ib + ia;
			if (c % 2 == 0) { squares.push_back(Entity(a, b, white)); }
			else { squares.push_back(Entity(a, b, black)); } a += 64; } b += 64; } int a = 0;
	for (int i = 0; i < 8; i++) {whitepawns.push_back(Pawn(a, 384, whitepawn));
		Pawn* ex = new Pawn(a, 384, whitepawn); whitepieces.push_back(ex); allpieces.push_back(ex);
		Pawn* ey = new Pawn(a, 64, blackpawn); blackpieces.push_back(ey); allpieces.push_back(ey);
		blackpawns.push_back(Entity(a, 384, blackpawn)); wPiecePositions.push_back(a); wPiecePositions.push_back(384); bPiecePositions.push_back(a); bPiecePositions.push_back(64); a += 64; }
	
	for (unsigned int i = 0; i < blackpieces.size(); i++) {
		blackpieces[i]->setColor(false);
	}

	bool gameRunning = true; bool press = false; bool layer = true; bool startButton = false;
	SDL_Event event; int mousex1, mousey1; int x2 = 0; int screen = 0; int WB = 0;
	while (gameRunning) { window.clear(); switch (screen) {
		case 0: window.render(Start);
			while (SDL_PollEvent(&event)) {
				int mousex, mousey; SDL_GetMouseState(&mousex, &mousey);
				if (mousey > 256) {startButton = true;} if (mousey < 256) {startButton = false;}
				switch(event.type) {
				case SDL_QUIT: gameRunning = false; break;
				case SDL_MOUSEBUTTONDOWN: if (mousey > 256) {screen = 1; break;} } }
			if (startButton == true) {
				for (int i = 4; i < 8; i++) { window.render(whitepawns[i]); }
				for (int i = 0; i < 4; i++) { window.render(blackpawns[i]); } } break;
		case 1: window.render(Choose); while (SDL_PollEvent(&event)) {
				int mousex, mousey; SDL_GetMouseState(&mousex, &mousey);
				if (mousey > 256) {
					if (mousex > 256) {WB = 1;} // is white
					else if (mousex < 256) {WB = 2;} // is black
				} else {WB = 0;}
				switch(event.type) {
				case SDL_QUIT: gameRunning = false; break;
				case SDL_MOUSEBUTTONDOWN:
					if (WB == 1) {screen = 2; std::cout << "screen == 2" << std::endl; break;}
					else if (WB == 2) {screen = 3; std::cout << "screen == 3" << std::endl; break;} } }
			if (WB == 1) {for (Pawn& e : whitepawns) {window.render(e);}}
			else if (WB == 2) {for (Entity& e : blackpawns) {window.render(e);}} break;
		case 2: for (Entity& e : squares) {window.render(e);} for(Piece*e:blackpieces){window.render2(e);}
			for (Piece* e : whitepieces) {window.render2(e);} while (SDL_PollEvent(&event)) {
				switch (event.type) { case SDL_QUIT: gameRunning = false; break;
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT) {
						int mousex, mousey; SDL_GetMouseState(&mousex, &mousey);
						mousex1=mousex;mousey1=mousey;}
					for (unsigned int i = 0; i < wPiecePositions.size(); i++) {
						std::cout << wPiecePositions.at(i) << " "; }
						std:: cout << endl;
					std::cout << wPiecePositions.size() << press << std::endl; break;} }
			if (press == true) { layer = false; // a piece is selected
			for (unsigned int i = 0; i < glPP->possibleMoves.size(); i+=2) {
				Entity* dot1 = new Entity(glPP->possibleMoves[i], glPP->possibleMoves[i+1], dot); 
				window.render2(dot1); delete dot1; }
			for (unsigned int i = 0; i < glPP->possibleMoves.size(); i+= 2) {
					if ((mousex1>=glPP->possibleMoves[i]) and (mousex1<glPP->possibleMoves[i]+64) and (mousey1>=glPP->possibleMoves[i+1]) and (mousey1<glPP->possibleMoves[i+1]+64))
						{ int a1=glPP->possibleMoves[i]; int b1=glPP->possibleMoves[i+1];
					for (unsigned int i = 0; i < bPiecePositions.size(); i+=2) {
				if (glPP->getX() == bPiecePositions.at(i) && glPP->getY() == bPiecePositions.at(i+1)) {
					for (Piece* e:blackpieces) {
						if (bPiecePositions.at(i) == e->getX() && bPiecePositions.at(i+1) == e->getY()) {
							delete e;
						}
					}
									bPiecePositions.erase(bPiecePositions.begin()+i+1);
					bPiecePositions.erase(bPiecePositions.begin()+i);	
				}
					}

						for (unsigned int i = 0; i < wPiecePositions.size(); i+=2) {
					if (glPP->getX() == wPiecePositions.at(i) && glPP->getY() == wPiecePositions.at(i+1)) {
								wPiecePositions.erase(wPiecePositions.begin()+i+1);
								wPiecePositions.erase(wPiecePositions.begin()+i); break;} } press = false;
						glPP->setXY(a1, b1); glPP->setSelectF(); wPiecePositions.push_back(a1); wPiecePositions.push_back(b1);
						glPP = nullptr; screen = 3; break; }
						else { press = false; } } }
			if (press == false) { // FUNCTION LOOK HERE !!!!!!!!!!!!!
			for (Piece* e: whitepieces) { global::x1 = e->getX(); global::y1 = e->getY();
				if ((global::x1 <= mousex1) and (mousex1 < global::x1 + 64) and (global::y1 <= mousey1) and (mousey1 < global::y1 + 64)) { glPP = e; press = true;
						e->setSelectT(wPiecePositions); layer = false; break; }
						else {layer = true; press = false;} } }
			if (layer == true) {
					for (Entity& e: squares) {
						global::x1 = e.getX(); global::y1 = e.getY();
						if ((global::x1 <= mousex1) and (mousex1 < (global::x1 + 64))) {
							if ((global::y1 <= mousey1) and (mousey1 < (global::y1 + 64))) {
								Entity d(global::x1, global::y1, red); window.render(d); } } } }
			break;
		case 3: for (Entity& e : squares) {window.render(e);} for(Piece*e:blackpieces) {window.render2(e);}
			for(Piece*e:whitepieces){window.render2(e);} while (SDL_PollEvent(&event)) {
				switch (event.type) { case SDL_QUIT: gameRunning = false; break;
				case SDL_MOUSEBUTTONDOWN:
						if (event.button.button == SDL_BUTTON_LEFT) {
						int mousex, mousey; SDL_GetMouseState(&mousex, &mousey);
						mousex1=mousex;mousey1=mousey;} break; } }
			if (press == true) { layer = false; // a piece is selected
			for (unsigned int i = 0; i < glPP->possibleMoves.size(); i+=2) {
				Entity* dot1 = new Entity(glPP->possibleMoves[i], glPP->possibleMoves[i+1], dot); 
				window.render2(dot1); delete dot1; }
			for (unsigned int i = 0; i < glPP->possibleMoves.size(); i+= 2) {
					if ((mousex1>=glPP->possibleMoves[i]) and (mousex1<glPP->possibleMoves[i]+64) and (mousey1>=glPP->possibleMoves[i+1]) and (mousey1<glPP->possibleMoves[i+1]+64))
						{ int a1=glPP->possibleMoves[i]; int b1=glPP->possibleMoves[i+1];
						for (unsigned int i = 0; i < wPiecePositions.size(); i+=2) {
					if (glPP->getX() == wPiecePositions.at(i) && glPP->getY() == wPiecePositions.at(i+1)) {
								bPiecePositions.erase(bPiecePositions.begin()+i+1);
								bPiecePositions.erase(bPiecePositions.begin()+i); break;}
						} press = false;
						glPP->setXY(a1, b1); glPP->setSelectF(); bPiecePositions.push_back(a1); bPiecePositions.push_back(b1);
						glPP = nullptr; screen = 2; break; }
						else { press = false; } } }
			if (press == false) {
			for (Piece* e: blackpieces) { global::x1 = e->getX(); global::y1 = e->getY();
				if ((global::x1 <= mousex1) and (mousex1 < global::x1 + 64) and (global::y1 <= mousey1) and (mousey1 < global::y1 + 64)) { glPP = e; press = true;
						e->setSelectT(wPiecePositions); layer = false; break; }
						else {layer = true; press = false;} } }
			if (layer == true) {
					for (Entity& e: squares) {
						global::x1 = e.getX(); global::y1 = e.getY();
						if ((global::x1 <= mousex1) and (mousex1 < (global::x1 + 64))) {
							if ((global::y1 <= mousey1) and (mousey1 < (global::y1 + 64))) {
								Entity d(global::x1, global::y1, red); window.render(d); } } } }
			break;
		}
		window.display();
	} window.cleanUp(); SDL_Quit(); return 0;
}