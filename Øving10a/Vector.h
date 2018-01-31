#pragma once
#include "Matrix.h"
#include <iostream>
#include<cmath>
using namespace std;

class Matrix;

class Vector : public Matrix
{
public:
	Vector();
	explicit Vector(int nRows);
	Vector(const Matrix & other); 
	//Vector(const double other[]); //equivalent to Vector(const int *other)
	void set(int row, double value); //Blir ikke dette som overlagring? At begge finnes?	/*double get(int row) const;*/
	double dot(const Vector &rhs) const;
	double lengthSquared() const;
	double length() const;
private:
};
