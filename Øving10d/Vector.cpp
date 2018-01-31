#include <cmath>
#include "Vector.h"

Vector::Vector() : Matrix() {}
Vector::Vector(int nRows) : Matrix(nRows, 1) {}
Vector::Vector(const Matrix & other) : Matrix() {
	if (other.isValid() && other.getWidth() == 1) {
		*this = other;
	}
}
void Vector::set(int row, double value) {
	Matrix::set(row, 0, value);
}
double Vector::get(int row) const {
	return Matrix::get(row, 0);
}
double Vector::dot(const Vector &rhs) const {	if (this->isValid() && rhs.isValid() && (this->getHeight() == rhs.getHeight())) {		double summedProd = 0;		for (int i = 0; i < this->getHeight(); i++) {			summedProd += (this->get(i) * rhs.get(i));		}		return summedProd;	}	return nan("");}double Vector::lengthSquared() const {	return dot(*this);}double Vector::length() const {	return sqrt(this->lengthSquared());}