#include "Blackjack.h"
#include "CardDeck.h"
#include "cardClass.h"
#include "card.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//Uten peker:
//bool Blackjack::isAce(Card myCard) {
//	return(myCard.getRank() == 14);
//}

bool Blackjack::isAce(Card *myCard) { //Tar inn en pointer selv om *myCard er verdien. Heri  fins forvirring
	return((*myCard).getRank() == ACE);
}

int Blackjack::getCardValue(Card *myCard) {
	if (isAce(myCard)) {
		return -1;
	}
	int rankNotValue = (int)(*myCard).getRank();
	if (rankNotValue > 9) {
		return 10;
	}
	//Card card1;
	//(&card1)->getRank()
	return rankNotValue;
}

int Blackjack::getPlayerCardValue(Card *myCard) {
	if ((getCardValue(myCard)) != -1) {
		return getCardValue(myCard); //Er det mer effektivt å lagre en dummy eller å kjøre to ganger?
	}
	string reply = "11";
	//cout << "Vil du at esset skal være 1 eller 11?" << endl;
	//string reply = "";
	//cin >> reply;
	//while ((atoi(reply.c_str()) != 1) && (atoi(reply.c_str()) != 11)) {
	//	cout << "Skriv inn enten 1 eller 11." << endl;
	//	cin >> reply;
	//}
	return atoi(reply.c_str());
}

int Blackjack::getDealerCardValue(Card *myCard, int handValue) {
	int cardValue = getCardValue(myCard);
	if (cardValue != -1) { return cardValue; }
	if (handValue > 10) { return 1; }
	return 11;
}

bool Blackjack::askPlayerDrawCard() {
	cout << "Vil du trekke et kort? j/n" << endl;
	string reply = "";
	cin >> reply;
	while ((reply != "j") && (reply != "n")) {
		cout << "Skriv inn enten j eller n." << endl;
		cin >> reply;
	}
	if (reply == "j") { return true; }
	return false;
}

void Blackjack::drawInitialCards(int *aces) {
	//Spilleren trekker to
	for (int i = 0; i < 2; i++) {
		Card myCard = deck.drawCard(); 
		cout << "Du trakk " << myCard.toString() << endl;
		playerHand += getPlayerCardValue(&myCard);
		if (isAce(&myCard)) { *aces++; }
		playerCardsDrawn++;
	}
	//Dealeren trekker to
	for (int i = 0; i < 2; i++) {
		Card myCard = deck.drawCard();
		dealerHand += getDealerCardValue(&myCard,dealerHand);
		if (i==1) { cout << "Dealerens første kort er " << myCard.toString() << endl; }
		dealerCardsDrawn++;
	}
}

void Blackjack::askPlayAgain(bool *again) {
	cout << "Vil du Spille på nytt? j/n" << endl;
	string reply = "";
	cin >> reply;
	while ((reply != "j") && (reply != "n")) {
		cout << "Skriv inn enten j eller n." << endl;
		cin >> reply;
	}
	if (reply == "n") { *again = false; }
}

//Denne brukes med blackjack-elementet jackBlack
void Blackjack::playGame() {
	bool again = true;
	while (again) {
		cout << "\n------BLACKJACK------" << endl;
		deck = CardDeck();
		deck.shuffle();
		dealerHand = 0;
		playerHand = 0;
		dealerCardsDrawn = 0;
		playerCardsDrawn = 0;
		int aces = 0;
		drawInitialCards(&aces);
		cout << "Verdien av din hand: " << playerHand << endl;
		cout << "TEST: Verdien av dealeren sin hand: " << dealerHand << endl;
		if (playerHand == 21) {
			if (dealerHand == 21) { cout << "Uavgjort! Begge hadde blackjack!" << endl; }
			else { cout << "Du vant! Du hadde blackjack!" << endl; }
			askPlayAgain(&again);
			continue;
		}
		while (true) {
			if (askPlayerDrawCard()) { //Spør om spiller vil trekke. Hvis ikke, hvis dealer>17, sjekker.
				Card myCard = deck.drawCard(); //myCard
				cout << "Du trakk " << myCard.toString() << endl;
				playerHand += getPlayerCardValue(&myCard);
				if (isAce(&myCard)) { aces++; }
				cout << "Verdien av din hand: " << playerHand << endl;
				playerCardsDrawn++;
				if (playerHand > 21) {
					while (aces > 0) {
						playerHand -= 10;
						aces--;
					}
				}
				if (playerHand > 21) {
						cout << "Du tapte! Verdien på handa var over 21" << endl;
						cout << "Verdien av din hand: " << playerHand << endl;
						cout << "Verdien av dealeren sin hand: " << dealerHand << endl;
						askPlayAgain(&again);
						break;
				}
			}
			else if (dealerHand >= 17) { //Slår inn hvis spiller ikke trekker kort og dealer > 17
				cout << "Ingen trakk. Vi sjekker..." << endl;
				if (playerHand > dealerHand) {
					cout << "Du vant!" << endl;
					cout << "Verdien av din hand: " << playerHand << endl;
					cout << "Verdien av dealeren sin hand: " << dealerHand << endl;
					askPlayAgain(&again);
					break;
				}
				if (playerHand == dealerHand) {
					cout << "Uavgjort!" << endl;
					cout << "Verdien av din hand: " << playerHand << endl;
					cout << "Verdien av dealeren sin hand: " << dealerHand << endl;
					askPlayAgain(&again);
					break;
				}
				else {
					cout << "Du tapte!" << endl;
					cout << "Verdien av din hand: " << playerHand << endl;
					cout << "Verdien av dealeren sin hand: " << dealerHand << endl;
					askPlayAgain(&again);
					break;
				}
			} 
			if (dealerHand < 17) {
				Card myCard = deck.drawCard();
				dealerHand += getDealerCardValue(&myCard, dealerHand);
				dealerCardsDrawn++;
				if (dealerHand > 21) {
					cout << "Du vant! Verdien på handa til dealeren var over 21" << endl;
					cout << "Verdien av din hand: " << playerHand << endl;
					cout << "Verdien av dealeren sin hand: " << dealerHand << endl;
					askPlayAgain(&again);
					break;
				}
			}
			cout << "TEST: Verdien av din hand: " << playerHand << endl;
			cout << "TEST: Verdien av dealeren sin hand: " << dealerHand << endl;

		}
	}
}
