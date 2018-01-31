#include "Blackjack.h"
#include "card.h"
#include "cardClass.h"
#include "CardDeck.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned int)time(nullptr));
	Blackjack jackBlack;
	jackBlack.playGame();
	return 0;
}









//CardStruct aceofSpades = { ACE,SPADES };
////cout << toString(aceofSpades) << endl;
////cout << toStringShort(aceofSpades) << endl;
//Card card1; //Instanserer, altså lager et objekt
//card1.initialize(HEARTS, TWO);
////cout << suitToString(card1.getSuit()) << endl; //card1.getSuit() gir tallet, gjør om til streng!
//CardDeck suckMyDeck = CardDeck();
//suckMyDeck.shuffle();
//suckMyDeck.print();
//cout << "\n" << suckMyDeck.drawCard().toString() << endl;
