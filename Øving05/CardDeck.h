#pragma once
#include "card.h"
#include "cardClass.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Kan instansere en spesiell CardDeck fargestokk = CardDeck;
class CardDeck {
private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int pos1, int pos2);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};

int randomPosition(int position, int lowerLimit, int upperLimit);
//Hvor god kodeskikk er det å legge utility her når den relaterer til klassen?
