#include <iostream>
#include "Image.h"
#include "Matrix.h"
using namespace std;

int main(){
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
}
