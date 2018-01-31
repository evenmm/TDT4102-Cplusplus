#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car
{
private:
	int freeSeats;
public:
	Car(); //Denne funker ikke!
	Car(int freeSeats);
	bool hasFreeSeats() const;
	void reserveFreeSeat();
};
