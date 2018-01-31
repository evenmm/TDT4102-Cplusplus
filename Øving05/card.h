#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

enum Rank {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

string suitToString(Suit mySuit);

string rankToString(Rank myRank);

struct CardStruct {
	Rank r;
	Suit s;
};

string toString(CardStruct myCard);

string toStringShort(CardStruct myCard);