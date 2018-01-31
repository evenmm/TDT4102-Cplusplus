#include "CardDeck.h"
#include "cardClass.h"
#include "card.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

CardDeck::CardDeck() {
	currentCardIndex = 0;
	cards.clear();
	for (int suitInt = CLUBS; suitInt <= SPADES; suitInt++) { //SPM: Kommer vi gjennom hele?
		for (int rankInt = TWO; rankInt <= ACE; rankInt++) {
			Card newCard = Card((Suit)suitInt, (Rank)rankInt); //int --> enum
			cards.push_back(newCard);
		}
	}
}

void CardDeck::swap(int pos1, int pos2) {
	Card temp = cards[pos1];
	cards[pos1] = cards[pos2];
	cards[pos2] = temp;
}

void CardDeck::print() {
	for (int i = 0; i != cards.size(); i++) {
		cout << cards[i].toString() << endl;
	}
}

void CardDeck::printShort() {
	for (int i = 0; i != cards.size(); i++) {
		cout << cards[i].toStringShort() << endl;
	}
}

int randomPosition(int position, int lowerLimit, int upperLimit) {
	int temp = position;
	while (temp == position) {
		temp = lowerLimit + (rand() % (upperLimit - lowerLimit + 1));
	}
	return temp;
}

void CardDeck::shuffle() {
	//this->cards trengs ikke, swap() trikser med referanse
	for (int i = 0; i != cards.size(); i++) {
		swap(i, randomPosition(i, 0, 51)); //Tar med limits
	}
}

Card CardDeck::drawCard() {
	return cards[currentCardIndex++]; //Postfix increment: return x, deretter settes x til (x++)
}
