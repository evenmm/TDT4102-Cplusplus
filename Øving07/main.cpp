#include "Matrix.h"
#include "testDummy.h"
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
using namespace std;

void dummyTest();
void createFibonacci();
void fillInFibonacciNumbers(int result[], int length);
void printArray(int arr[], int length);

/*Intermezzo: Følgende printes:
a 4
b 4
c 4
a 5
b 3 - ble først 5 i stedet, som fryktet! Kopikonstruktør --> 3
c 5
Faktisk output: 
a 4 4 4 4
b 4 4 4 4
c 4 4 0 4
a 5 5 4 4
b 5 3 3 3
c 5 5 5 5
      ^Her hadde jeg ikke forstått overlagring av &operator =
Kræsjet programmet pga dynamiske variabler som ikke ble destruert?
*/
int main() {
	createFibonacci();
	
	/*cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	dummyTest();
	*/
	
	//Ser destruktøren OK ut?
	Matrix A(2, 2);
	A.set(0,0,1);
	A.set(0,1,2);
	A.set(1,0,3);
	A.set(1,1,4);
	cout << "A: \n" << A << endl;
	Matrix B(2, 2);
	B.set(0,0,4);
	B.set(0,1,3);
	B.set(1,0,2);
	B.set(1,1,1);
	cout << "B: \n" << B << endl;
	Matrix C(2,2);
	C.set(0,0,1);
	C.set(0,1,3);
	C.set(1,0,1.5);
	C.set(1,1,2);
	cout << "C: \n" << C << endl;
	A += B + C; //<==>A += (B + C). 
	cout << "A += B + C \nNye A: \n" << A << endl;

	//Matrix m1 = Matrix();
	//Matrix m2(3, 5);
	//Matrix m3(4);
	//cout << "nr 1" << endl;
	//cout << m1 << endl;
	//cout << "nr 2" << endl;
	//cout << m2 << endl;
	//cout << "nr 3" << endl;
	//cout << m3 << endl;
	//m3.set(0, 0, 3.14);
	//cout << "nr 3" << endl;
	//cout << m3 << endl;
	//cout << "1 " << m1.isValid() << endl;
	//cout << "2 " << m2.isValid() << endl;
	//m1.~Matrix();
	return 0;
}

void fillInFibonacciNumbers(int result[], int length) {
	for (int i = 0; i < length; i++) {
		if (i == 0 || i == 1) { result[i] = i; }
		else {
			result[i] = result[i - 1] + result[i - 2];
		}
	}
}

void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
}

void createFibonacci() {
	int length = 0;
	cout << "Skriv inn antall tall" << endl;
	cin >> length;
	int *fibArray = new int[length] {}; 
	fillInFibonacciNumbers(fibArray,length);
	printArray(fibArray, length);
	delete fibArray; //Hva med delete[]?
	fibArray = nullptr;
}
