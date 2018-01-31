#pragma once
#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Person {
private:
	string name;
	string email;
	Car *car; //Vil ha inn en peker "car1" som peker til en Car
public:
	Person(string name, string email, Car *car);
	Person(string name, string email);
	string getName() const;
	string getEmail() const;
	Car getCar() const;
	void setName(string name);
	void setEmail(string email);
	bool hasAvailableSeats() const;
};
ostream& operator<<(ostream& os, const Person& p);
bool operator<(const Person &p1, const Person &p2);bool operator==(const Person &p1, const Person &p2);

