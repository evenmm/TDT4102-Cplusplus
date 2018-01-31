#pragma once
#include "card.h"
#include "cardClass.h"
#include "CardDeck.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Blackjack
{
private:
	CardDeck deck;
	int playerHand;
	int dealerHand;
	int playerCardsDrawn;
	int dealerCardsDrawn;
public:
//	bool isAce(Card myCard); //myCard er et Card
	bool isAce(Card *myCard); //myCard er en peker, (*myCard) er et Card
	int getCardValue(Card *myCard);
	int getPlayerCardValue(Card *myCard);
	int getDealerCardValue(Card *myCard, int handValue);
	bool askPlayerDrawCard();
	void drawInitialCards(int *aces);
	void playGame();
	void askPlayAgain(bool *again);
};
