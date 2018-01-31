#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int max (int a, int b) {
	if (a > b) {
		cout << "A is greater than B" << endl;
		return a;
	}
	else {
		cout << "B is greater than or equal A" << endl;
		return b;
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << endl;
	for (int x = 1; x < n; x++) {
		cout << x << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----" << endl;
	return b;
}

int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += (i * i);
		cout << i * i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc < n) {
		cout << acc << endl;
		acc += num;
		num++;
	}
	cout << endl; //Skriver ingenting
	return 0;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc++;
	}
	return number == 0;
}

bool isPrime(int n) {
	bool primeness = 1;
	for (int j = 2; j < n; j++) {
		if (n%j == 0) {
			primeness = 0;
			return primeness;
		}
	}
	return primeness;
}

int naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n;number++) {
		if (isPrime(number)) {
			cout << number << "is a prime" << endl;
		}
	}
	return 0;
}

int findGreatestDivisor(int n) {
	for (int divisor = n - 1; divisor > 0; divisor--) {
		if (n % divisor == 0) {
			return divisor;
		}
	}
	return 1; //Må jeg ha den??????????????????
}
void testingtestingtesting() {
	cout << "Oppgave a)" << endl;
	cout << max(5, 6) << endl;
	cout << "Oppgave c)" << endl;
	cout << fibonacci(10) << endl;
	cout << "Oppgave d)" << endl;
	cout << squareNumberSum(7) << endl;
	cout << "Oppgave e)" << endl;
	cout << triangleNumbersBelow(7) << endl;
	cout << isTriangleNumber(7) << endl;
	cout << "Oppgave f)" << endl;
	cout << "Sjekker om 31 er primtall" << endl;
	cout << isPrime(31) << endl;
	cout << "Oppgave g)" << endl;
	cout << naivePrimeNumberSearch(31) << endl;
	cout << "Oppgave h)" << endl;
	cout << naivePrimeNumberSearch(31) << endl;
}
class Foo {
private:
	int* p;
	int a;
	int b;
public:
	Foo() : p(nullptr), a(1), b(2) {};
	Foo(int a, int b) {};
	Foo(Foo& f) : Foo(f.a, f.b) {};
	void setP(int &a) { p = &a; };
	virtual void printer() { cout << "foo" << endl; };
};
class Goo : public Foo {
public:
	Goo() : Foo(1, 2) {};
	void printer() { cout << "goo" << endl; };
};
int* one() {
	int* a = new int(2);
	Foo foo1;
	foo1.setP(*a);
	return a;
}
struct Data {
	int a;
	char b;
};
struct Data2 {
	Data d1;
	Data d2;
};
class Board {
private:
	int** board;
public:
	Board();
//	~Board();
};
Board::Board() {
}
struct Placing {
	int x; bool samesame = true;
	int y;
	Placing(int x, int y) : x(x), y(y) {};
};
int main() {
	Placing no1(2, 3);
	no1.x = 2;
	no1.y++;
	Board board;
	Foo f;
	Goo g;
	f.printer();
	g.printer();
	Foo* fptr = &f;
	Goo* gptr = &g;
	Foo* fff = &g;
	fff->printer(); //printer Goo hvis man kan lagre subklasser i superklassepekere. Skal skje
	//Printer foo hvis de blir upcastet av å lagres i pekere. 
	//Goo* ggg = &f; //funker ikke pga subpeker til superklasseobjekt

	/*int b = 2;
	int* p1 = &b;
	int* p2 = &b;
	one();
	int* p3 = new int(2);
	set<pair<string, string>> s;
	map<string, set<string>> edges;
	for (auto it = edges.begin(); it != edges.end(); it++) {
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			s.insert((it->first, (*it2)));
		}
	}*/
	string a("hhehe");
	string b(a);
	cout << b << endl;
	b += tolower(a[3]);
	cout << b << endl;
	cout << tolower(a[3]) << endl;
	cout << isalpha(a[0]) << endl;
	a = " wfwf";
	cout << boolalpha << isalpha(a[0]) << endl;
	typedef string* strinpointarr;
	int aaa = 1;
	int* ppp = nullptr;
	while (ppp) { aaa++; }
	cout << "Første " << aaa << endl;
	ppp = &aaa;
	if (ppp) { aaa++; }
	cout << "Andre " << aaa << endl;
	return 0;
}