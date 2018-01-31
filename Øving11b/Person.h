#pragma once
#include <iostream>
#include <string>

#include "SimpleSet.h"
using namespace std;
class Person {
public:
	Person();
	Person(string first, string last);
	void setFirstName(string first);
	void setLastName(string last);
	string getLastName() const; 
	string getFirstName() const;
	friend ostream& operator <<(ostream& os, const Person& rhs);
	const bool operator <(const Person& rhs) const;
private:
	string firstname;
	string lastname;
};

ostream& operator <<(ostream& os, const Person& rhs) {
	os << rhs.firstname << " " << rhs.lastname << endl;
	return os;
}
