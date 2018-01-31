#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

Vector::Vector() : Matrix() {}Vector::Vector(int nRows) : Matrix(nRows, 1) {}Vector::Vector(const Matrix & other) {	*this = Matrix();	if (other.getWidth() == 1) {		*this = Matrix::operator=(other);	}}//Vector::Vector(const double other[]) : Vector(sizeof(other)) { //Liste inn som peker//	for (int i = 0; i < sizeof(other); i++) {//		this->set(i, other[i]); //	}//}void Vector::set(int row, double value) {	Matrix::set(row, 0, value);}//double Vector::get(int row) const {
//	return (this->Matrix::get(row, 0));
//}
double Vector::dot(const Vector &rhs) const {	if (!(this->isValid() && rhs.isValid() && (this->getHeight() == rhs.getHeight()) 		&& this->getWidth() == 1 && rhs.getWidth() == 1)) {		return nan("");	}	int accumulator = 0;	for (int i = 0; i < this->getHeight(); i++) {		accumulator += (this->get(i, 0) * rhs.get(i, 0));	}	return accumulator;}double Vector::lengthSquared() const {	return this->dot(*this);}double Vector::length() const {	return sqrt(this->lengthSquared());}