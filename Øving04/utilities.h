#pragma once
#include <iostream>
#include <ctype.h>

int randomWithLimits(int lowerLimit, int upperLimit);

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimes2(int *startValue, int increment, int numTimes);

void swapNumbers(int *a, int *b);

void printArray(int myArray[], int length);

void randomizeArray(int myArray[], int length);

void sortArray(int myArray[], int length);

int medianOfArray(int myArray[], int length);

void randomizeCString(char grades[], int quantity, int LowerLimit, int upperLimit);

void readInputToCString(char grades[], int quantity, int LowerLimit, int upperLimit);

int countOccurencesOfCharacter(char cString[], int length, char sign);
