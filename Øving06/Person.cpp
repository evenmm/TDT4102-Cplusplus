#include "Person.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Person::Person(string name, string email, Car *car) {
	this->name = name;
	this->email = email;
	this->car = car;
}

Person::Person(string name, string email) : Person(name, email, nullptr) {}

void Person::setName(string name) {
	this->name = name;
}

void Person::setEmail(string email) {
	this->email = email;
}

string Person::getName() const {
	return name;
}

string Person::getEmail() const {
	return email;
}

Car Person::getCar() const {
	return (*car);
}

bool Person::hasAvailableSeats() const {
	return (car != nullptr && car->hasFreeSeats());
}

ostream& operator<<(ostream& os, const Person& p) {	os << "Navn: " << p.getName() << "\nemail: " << p.getEmail();	return os;}
bool operator<(const Person &p1, const Person &p2) {	return p1.getName() < p2.getName();}bool operator==(const Person &p1, const Person &p2) {	return p1.getName() == p2.getName();}
