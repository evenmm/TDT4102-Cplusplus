#include <iostream>
#include "tests.h"
#include "utilities.h"
#include<cmath>
using namespace std;

int checkCharactersAndPosition(char firstString[], char secondString[], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (firstString[i] == secondString[i]) {
			counter++;
		}
	}
	return counter;
}

int checkCharacters(char code[], char guess[], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		int coded = 0;
		int guessed = 0;
		char countingGrade = 'A' + i;
		coded += countOccurencesOfCharacter(code, length, countingGrade);
		guessed += countOccurencesOfCharacter(guess, length, countingGrade);
		if (guessed < coded) { counter += guessed; }
		else { counter += coded; }
	}
	return counter;
}

void playMastermind() {
	const int SIZE = 4;
	const int LETTERS = 5;
	char code[SIZE+1] = {};
	char guess[SIZE+1] = {};
	randomizeCString(code, SIZE, 'A', 'A' + LETTERS - 1);
	//cout << code << endl; //Her printes koden
	int correctCharactersAndPositions = 0;
	int chances = 15;
	cout << "Du skal gjette en kode på 4 bokstaver, og har 4 forsøk. Let's go!" << endl;
	while ((correctCharactersAndPositions < SIZE) && (chances > 0)) {
		cout << "Du har igjen " << chances << " sjanser av 15." << endl;
		readInputToCString(guess, SIZE, 'A', 'A' + LETTERS - 1);
		int correctCharacters = checkCharacters(code, guess, SIZE);
		cout << "\nAntall riktige bokstaver: " << correctCharacters << endl;
		correctCharactersAndPositions = checkCharactersAndPosition(code, guess, SIZE);
		cout << "Antall riktige bokstaver på rett sted: \n" << correctCharactersAndPositions << endl;
		chances--;
	}
	if (correctCharactersAndPositions == SIZE) {
		cout << "GRATULERER! Du er den virkelige mastermind!" << endl;
	}
	else {
		cout << "Du tapte. Sux to be you." << endl;
	}
	//cout << guess << endl;
	//for (int i = 0; i < 5; i++) {
	//	cout << guess[i];
	//	cout << endl;
	//}
}