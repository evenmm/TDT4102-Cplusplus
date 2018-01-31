#pragma once
#include <iostream>
using namespace std;

struct Tile {
	bool open;
	bool mine;
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
	Tile **board;
	bool gameOver;
	int width;
	int height;
	int mines; //Brukes ikke
public:
	int tilesToGo;
	bool victory;
	Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const; //Fine fordi de er const
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

