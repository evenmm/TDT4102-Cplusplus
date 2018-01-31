#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "Vector.h"
#include<cmath>
using namespace std;

int main(){
	Matrix eightrix(3,3);
	Vector schmector(3);
	for (int i = 0; i < schmector.getHeight(); i++) {
		schmector.Vector::set(i, 3.0);
		for (int j = 0; i < schmector.getHeight(); j++) {
			eightrix.Matrix::set(i, j, 8.0);
		}
	}
//	Matrix prodmatrix = eightrix * schmector;
//	cout << prodmatrix << endl;
	return 0;
}
