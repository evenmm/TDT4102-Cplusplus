#include "cardClass.h"
#include "card.h"
#include <iostream>
#include <string>
using namespace std;

void Card::initialize(Suit s, Rank r) {
	this->s = s; //this peker på det som finnes i Card
	this->r = r;
	this->invalid = false;
}

Suit Card::getSuit() {
	return this->s;
}

Rank Card::getRank() {
	return this->r;
}

string Card::toString() {
	if (this->invalid) { return "Ugyldig kort"; }
	return rankToString(this->r) + " of " + suitToString(this->s);
}

string Card::toStringShort() {
	if (this->invalid) { return "Ugyldig kort"; }
	return suitToString(this->s).substr(0, 1) + to_string((int)(this->r));
}

Card::Card() {
	invalid = true;
}

Card::Card(Suit s, Rank r) {
	this->s = s;
	this->r = r;
	invalid = false;
}
