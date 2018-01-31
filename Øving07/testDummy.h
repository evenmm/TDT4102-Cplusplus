#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
using namespace std;

class Dummy {
public:
	int *num;
	Dummy() {
		num = new int(0);
	}
	Dummy(const Dummy &old);
	~Dummy() {
		delete num;
	}
	Dummy &operator =(Dummy rhs) { //Tar inn rhs som en call-by-value SOM OPPRETTES AV KOPIKONSTRUTØØØØØR! VILT!
		std::swap(num, rhs.num);
		return *this; //Returnerer en Dummy
	}
};