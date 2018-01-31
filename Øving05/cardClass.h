#pragma once
#include "card.h"
#include <iostream>
#include <string>
using namespace std;

class Card {
private:
	Suit s;
	Rank r;
	bool invalid;
public:
	Card();
	Card(Suit s, Rank r);
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	string toString();
	string toStringShort();
};