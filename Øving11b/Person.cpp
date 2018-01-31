#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() : firstname(""), lastname("") {}

Person::Person(string first, string last) : firstname(first), lastname(last) {}

void Person::setFirstName(string first) {
	firstname = first;
}
void Person::setLastName(string last) {
	lastname = last;
}
string Person::getLastName() const {
	return lastname;
}
string Person::getFirstName() const {
	return firstname;
}

const bool Person::operator <(const Person& rhs) const {
	if ((this->lastname < rhs.lastname) || (this->firstname < rhs.firstname)) { return true; }
	return false;
}
