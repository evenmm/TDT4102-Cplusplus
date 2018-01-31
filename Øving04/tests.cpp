#include <iostream>
#include "tests.h"
#include "utilities.h"
#include<cmath>
using namespace std;

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}

void testCallByPointer() {	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations;
	incrementByValueNumTimes2(&v0, increment, iterations);	cout << " result: " << v0 << std::endl;}void testTablesSorting() {
	int percentages[20] = {};
	randomizeArray(percentages,20); //Kaller funksjonen med pekere
	cout << "Tilfeldig fylt tabell: \n" << endl;
	for (int i = 0; i < 20; i++) {
		cout << percentages[i];
		cout << endl;
	}
	swapNumbers(&percentages[0], &percentages[1]);
	cout << "Byttet to første: \n" << endl;
	for (int i = 0; i < 20; i++) {
		cout << percentages[i];
		cout << endl;
	}
	cout << "Median før sort: " << medianOfArray(percentages, 20) << endl;
	sortArray(percentages, 20);
	cout << "Sortert tabell: \n" << endl;
	for (int i = 0; i < 20; i++) {
		cout << percentages[i];
		cout << endl;
	} 
	cout << "Median etter sort: " << medianOfArray(percentages, 20) << endl;
}

void testCStrings() {
	char grades[41] = {};
//	randomizeCString(grades, 40, 'A', 'E');
	readInputToCString(grades, 40, 'A', 'E');
	cout << grades << endl;
	int gradeCount[5] = {};
	int averageGrade = 0;
	for (int i = 0; i < 5; i++) {
		char countingGrade = 'A' + i;
		gradeCount[i] = countOccurencesOfCharacter(grades, 40, countingGrade);
//		averageGrade += grades[i];
	}
	//averageGrade = (averageGrade / 40);
	//cout << "Average grade : " << averageGrade << (char)averageGrade << endl;
	averageGrade = 0;
	for (int i = 0; i < 5; i++) {
		averageGrade += gradeCount[i] * (i + 1);
	}
	averageGrade = (averageGrade / 40);
	cout << "Average grade : " << round(averageGrade) << ", "
		<< (char)('A' - 1 + round(averageGrade)) << endl;
}
//
//void testCStrings() {
//	char grades[41] = {};
//	randomizeCString(grades, (sizeof(grades) - 1), 'A', 'E');
//	cout << grades << endl;
//	int gradeCount[5] = {};
//	int averageGrade = 0;
//	for (int i = 0; i < sizeof(gradeCount); i++) {
//		char countingGrade = 'A' + i;
//		gradeCount[i] = countOccurencesOfCharacter(grades, sizeof(grades), countingGrade);
//		averageGrade += grades[i];
//	}
//	averageGrade = (averageGrade / sizeof(grades));
//	cout << "Average grade : " << (char)averageGrade << endl;
//	averageGrade = 0;
//	for (int i = 0; i < sizeof(gradeCount); i++) {
//		averageGrade += gradeCount[i] * (i + 1);
//	}
//	averageGrade = (averageGrade / (sizeof(grades) - 1));
//	cout << "Average grade : " << averageGrade << endl;
//}
