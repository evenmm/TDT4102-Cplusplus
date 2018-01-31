#include "SimpleSet.h"
#include "Person.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <forward_list>
#include <list>
using namespace std;
void replace(vector<string>& theVector, string old, string replacement);
void testing();
void setTest();
void simpleSetTester() {
	SimpleSet<int> numbers;
	for (int i = 0; i < 101; i++) {
		numbers.insert(i);
	}
	for (int j = 2; j< 51; j++) {
		for (int i = 2 * j; i < 101; i += j) {
			numbers.remove(i);
		}
	}
	cout << numbers << endl;
	numbers.~SimpleSet();
}

template<class T>
void shuffle(T a[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int j = rand() % (size - i);
		swap(a[i], a[i + j]);
	}
}

template<class T>
T maximum(T& a, T& b) { //Calling by reference
	if (a > b) { return a; }
	return b;
}

void insertOrdered(forward_list<Person>& l, const Person& p) {	auto pit = l.before_begin(), it = l.begin();	while (it != l.end() && *it < p) {		pit = it++;	}	l.insert_after(pit, p);}

void insertOrdered(list<Person> &l, const Person& p) {
	auto it = l.begin();	while (it != l.end() && *it < p) {		it++;	}	l.insert(it, p);
}
void test3() {
	list<Person> manntall;
	Person alpha("alpha", "beta");
	Person gamma("gamma", "zeta");
	Person epsilon("epsilon", "epsilon");
	insertOrdered(manntall, alpha);
	insertOrdered(manntall, gamma);
	insertOrdered(manntall, epsilon);
	for (auto it = manntall.begin(); it != manntall.end(); it++) {
		cout << *it << endl;
	}
}
int main() {
	int i = 1;
	do {
		i++;
	} while (i < 1);
	cout << i << endl;
	return 0;
}
	
void replace(vector<string>& theVector, string old, string replacement) {
	for (auto it = theVector.begin(); it != theVector.end(); it++) {
		if (*it == old) {
			it = theVector.erase(it);
			it = theVector.insert(it, replacement);
		}
	}
	for (auto it = theVector.begin(); it != theVector.end(); it++) {
		cout << *it << endl;
	}
}
void setTest() {
	set<int> numberSet;
	for (int i = 0; i < 101; i++) {
		numberSet.insert(i);
	}
	for (int j = 2; j< 51; j++) {
		for (int i = 2 * j; i < 101; i += j) {
			numberSet.erase(i);
		}
	}
	for (auto it = numberSet.begin(); it != numberSet.end(); it++) {
		cout << *it << endl;
	}
}
void testing() {
	string contonto[] = { "Jack Daniels", "Whiskey", "Goon", "Hææææmert" };
	vector<string> myVector;
	myVector.push_back(contonto[0]);
	myVector.push_back(contonto[1]);
	myVector.push_back(contonto[2]);
	myVector.push_back(contonto[3]);
	replace(myVector, "Whiskey", "Juan Carlosss");
	for (auto it = myVector.begin(); it != myVector.end(); it++) {
		cout << *it << endl;
	}
	for (auto it = myVector.rbegin(); it != myVector.rend(); it++) {
		cout << *it << endl;
	}
}
