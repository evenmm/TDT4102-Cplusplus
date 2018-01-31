#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Car::Car() { //Denne funker ikke!
	cout << "Skriv inn antall ledige seter:";
	cin >> freeSeats;
}

Car::Car(int freeSeats) {
	this->freeSeats = freeSeats;
}

bool Car::hasFreeSeats() const {
	return (freeSeats != 0);
}

void Car::reserveFreeSeat() {
	freeSeats--;
}

