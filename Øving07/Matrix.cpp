#include "Matrix.h"
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
using namespace std;
Matrix::Matrix() {
	matrix = nullptr;
	height = 0;
	width = 0;
}
Matrix::Matrix(int nRows, int nColumns) {	height = nRows;	width = nColumns;	matrix = new double*[nRows];
	for (int i = 0; i < nRows; i++) {
		matrix[i] = new double[nColumns];
		for (int j = 0; j < nColumns; j++) {
			matrix[i][j] = 0;
		}
	}}
Matrix::Matrix(int nRows) : Matrix(nRows, nRows) {
	for (int i = 0; i < nRows; i++) {
		matrix[i][i] = 1;
	}
}
Matrix::Matrix(const Matrix & rhs) { //Kopikonstruktør
	if (! rhs.isValid()) {		cout << "Noe unvalid!" << endl;		matrix = nullptr;
		height = 0;
		width = 0;
	}	else {		height = rhs.getHeight();		width = rhs.getWidth();		matrix = new double*[height];
		for (int i = 0; i < height; i++) {
			matrix[i] = new double[width];
			for (int j = 0; j < width; j++) {
				matrix[i][j] = rhs.get(i, j); //Dette er tilordning av double, deep.
			}
		}
	}
}
Matrix::~Matrix() {
	for (int i = 0; i < height; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
}
double Matrix::get(int row, int col) const{
	return matrix[row][col];
}
void Matrix::set(int row, int col, double value) {
	matrix[row][col] = value;
}
int Matrix::getHeight() const {
	return height;
}
int Matrix::getWidth() const {
	return width;
}
bool Matrix::isValid() const {
	return (matrix != nullptr);
}
ostream& operator<<(ostream& os, Matrix& m) {
	if (!(m.isValid())) {
		os << "Invalid Matrix" << endl;
		return os;
	}
	for (int i = 0; i < m.getHeight(); i++) {
		for (int j = 0; j < m.getWidth(); j++) {
			os << m.get(i, j) << " ";
		}
		os << endl;
	}
	return os;
}
Matrix& Matrix::operator +=(const Matrix& rhs) { //Copy and swap
	if ((this->height == rhs.height) && (this->width == rhs.width)) {
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				this->matrix[i][j] += rhs.matrix[i][j];
			}
		}
		return *this;
	}
	else {
		return Matrix();
	}
}
//Vil egentlig ha denne også ha denne som medlemsfunksjon
Matrix operator +(const Matrix& lhs, const Matrix& rhs) {
	Matrix newMatrix(lhs); //Kopikonstruktør lager en midlertidig en
	newMatrix += rhs; //fikser feilhåndtering selv
	return newMatrix;
}
