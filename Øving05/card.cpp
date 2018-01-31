#pragma once
#include <iostream>
#include "card.h"
#include <string>
using namespace std;

string suitToString(Suit mySuit) {
	switch (mySuit) {
	case CLUBS:
		return "Clubs";
	case DIAMONDS:
		return "Diamonds";
	case HEARTS:
		return "Hearts";
	case SPADES:
		return "Spades";
	default:
		return "Fuckups";
	}
}

string rankToString(Rank myRank) {
	switch (myRank) {
	case TWO:
		return "Two";
	case THREE:
		return "Three";
	case FOUR:
		return "Four";
	case FIVE:
		return "Five";
	case SIX:
		return "Six";
	case SEVEN:
		return "Seven";
	case EIGHT:
		return "Eight";
	case NINE:
		return "Nine";
	case TEN:
		return "Ten";
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	case ACE:
		return "Ace";
	default:
		return "Fuckup";
	}
}

string toString(CardStruct myCard) {
	return rankToString(myCard.r) + string(" of ") + suitToString(myCard.s);
}

string toStringShort(CardStruct myCard) {
	return suitToString(myCard.s).substr(0,1) + to_string((int)myCard.r);
}