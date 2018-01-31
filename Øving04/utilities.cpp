#pragma once
#include <iostream>
#include "utilities.h"
#include <cstdlib>
#include <ctype.h>
using namespace std;


int randomWithLimits(int lowerLimit, int upperLimit) {
	return (lowerLimit + (rand() % (upperLimit - lowerLimit + 1)));
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

void swapNumbers(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int myArray[], int length) {
	for (int i = 1; i < length; i++) {
		cout << myArray[i] << endl;
	}
	cout << endl;
}

void randomizeArray(int myArray[], int length) {
	for (int i=0; i < length; i++) {
		myArray[i] = randomWithLimits(0, 100);
	}
}

void sortArray(int myArray[], int length) {
	for (int i = 0; i < length; i++) {
		int j = i;
		while ((j > 0) && (myArray[j] < myArray[j - 1])) {
			swapNumbers(&myArray[j], &myArray[j - 1]);
			j--;
		}
	}
}

int medianOfArray(int myArray[], int length) {
	if (length % 2) {
		return (myArray[((int)length / 2)]);
	}
	return (myArray[(int)length / 2] + myArray[((int)length / 2) - 1]) / 2;
}

void randomizeCString(char myCString[], int numberOfGrades, int LowerLimit, int upperLimit) {
	for (int i = 0; i < numberOfGrades; i++) { //Denne må kalled med numberOfGrades lik 40, ikke 41
		myCString[i] = randomWithLimits(LowerLimit, upperLimit);
	}
	myCString[numberOfGrades] = '\0';
}

void readInputToCString(char myCString[], int quantity, int lowerLimit, int upperLimit) {
	for (int i = 0; i < quantity; i++) {
		char inputChar = 'G';
		while ((toupper(inputChar) < lowerLimit) || (toupper(inputChar) > upperLimit)) {
			cout << "Skriv inn karakter nr " << i+1 << " mellom A og E: " << endl;
			cin >> inputChar; //cin har flere bokstaver som venter i kø.
		}
		myCString[i] = toupper(inputChar);
	}
	myCString[quantity] = '\0';
}

int countOccurencesOfCharacter(char cString[], int length, char sign) {
	int counter = 0;
	for (int j = 0; j < length; j++) {
		if (cString[j] == sign) {
			counter++;
		}
	}
	return (counter);
}

/*cout << j << endl;
cout << cString[j] << endl;
*/
//cout << counter << endl;
