#include "Minesweeper.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Minesweeper::Minesweeper(int width, int height, int mines) {
	gameOver = false;
	victory = false;
	tilesToGo = width*height - mines;
	this->width = width;
	this->height = height;
	this->mines = mines;
	board = new Tile*[height]; //board er en ny peker til en tabell av Tile-pekere.
	for (int i = 0; i < height; i++) {
		board[i] = new Tile[width];
		for (int j = 0; j < width; j++) {
			Tile startTile = { 0,0 };
			//cout << static_cast<int>(startTile.mine) << " " << static_cast<int>(startTile.open) << endl;
			board[i][j] = startTile;
		}
	}
	//Implementerer miner
	for (int i = 0; i < mines; i++) {
		int position = rand() % (height*width);
		while (isTileMine(position / height, position % height)) {
			position = rand() % (height*width);
			//cout << "Row: " << row <<  << endl;
		}
		this->board[position / height][position % height].mine = true;
		//this->board[1][0].mine = true;
	}
}

Minesweeper::~Minesweeper() {
	for (int i = 0; i < sizeof(this->board); i++) {
		delete[] board[i]; //Sletter det som finnes der pekeren peker (Et Tile-array)
		board[i] = nullptr; //Og jorder pekeren
	}
	delete[] board; //Sletter peker-arrayet (AHA! Blir automatisk dereferert!)
	board = nullptr; 
}

bool Minesweeper::isGameOver() const {
    return gameOver;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return this->board[row][col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
	return this->board[row][col].mine;
}

void Minesweeper::openTile(int row, int col) {
	if (row == 0 && col == 0) {
		int a = 0;
	}
	this->board[row][col].open = 1; //row, col fra input. 0-indeksert
	if (isTileMine(row,col)) { gameOver = true; return; }
	tilesToGo--;
	if (!tilesToGo) { victory = true; gameOver = true; return; }
	bool noBombs = true;
LOOP: 
	for (int rowIt = -1; rowIt < 2; rowIt++) {
		for (int colIt = -1; colIt < 2; colIt++) { //Sjekker så om gyldig rute. Denne brukes 3 ganger.
			if (((row + rowIt) != -1) && ((row + rowIt) != (height)) && ((col + colIt) != -1) && ((col + colIt) != (width))
				&& ((colIt != 0) || (rowIt != 0)) && isTileMine(row + rowIt, col + colIt)) {
				noBombs = false;
				goto endloop;
			}
		}
	}
endloop:
	if (noBombs) {
		for (int rowIt = -1; rowIt < 2; rowIt++) {
			for (int colIt = -1; colIt < 2; colIt++) {
				if (((row + rowIt) != -1) && ((row + rowIt) != (height)) && ((col + colIt) != -1) && ((col + colIt) != (width))
					&& ((colIt != 0) || (rowIt != 0)) && (! isTileOpen(row+rowIt,col+colIt))) {
					openTile(row + rowIt, col + colIt);
				}
			}
		}
	}
}

int Minesweeper::numAdjacentMines(int row, int col) const {
	int counter = 0;
	for (int rowIt = -1; rowIt < 2; rowIt++) {
		for (int colIt = -1; colIt < 2; colIt++) { //Sjekker så om gyldig rute. Denne brukes 3 ganger.
			if (((row + rowIt) != -1) && ((row + rowIt) != (height)) && ((col + colIt) != -1) && ((col + colIt) != (width))
				&& ((colIt != 0) || (rowIt != 0)) && isTileMine(row + rowIt, col + colIt)) {
				counter++;			//Kan det hende at denne^ oppretter en Tile med mine her hvis den ikke finnes?
			}
		}
	}
	return counter;
}
