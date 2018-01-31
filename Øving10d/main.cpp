#include <iostream>
#include "Image.h"
//#include "Matrix.h" //?
#include "Vector.h"
using std::cout;
using std::endl;
void testFunc();

int main(){
	Matrix eightrix(3, 3);
	Vector schmector(3);
	for (int i = 0; i < schmector.getHeight(); i++) {
		schmector.set(i, 3.0);
		for (int j = 0; i < schmector.getHeight(); j++) {
			eightrix.set(i, j, 8.0);
		}
	}
	//Matrix prodmatrix = eightrix * schmector;
	//cout << prodmatrix << endl;

	//testFunc();
	return 0;
}

void testFunc() {
	Matrix A(2, 2);
	A.set(0, 0, 1);
	A.set(0, 1, 2);
	A.set(1, 0, 3);
	A.set(1, 1, 4);
	cout << "A: \n" << A << endl;
	Matrix B(2, 2);
	B.set(0, 0, 4);
	B.set(0, 1, 3);
	B.set(1, 0, 2);
	B.set(1, 1, 1);
	cout << "B: \n" << B << endl;
	Matrix C(2, 2);
	C.set(0, 0, 1);
	C.set(0, 1, 3);
	C.set(1, 0, 1.5);
	C.set(1, 1, 2);
	cout << "C: \n" << C << endl;
	cout << "B + C: \n" << B + C << endl;
	A += B + C; //<==>A += (B + C).
	cout << "A += B + C \nNye A: \n" << A << endl;
	Vector schmector(3);
	schmector.set(0, 100);
	schmector.set(1, 1000);
	schmector.set(2, 2000);
	for (int i = 0; i < schmector.getHeight(); i++) {
		schmector.set(i, 1);
	}
	Vector complector(schmector);
	cout << complector << "Length: " << complector.length() << endl;
}