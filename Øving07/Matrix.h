#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows);
	Matrix(const Matrix & rhs);
	~Matrix();
	double get(int row, int col) const;
	void set(int row, int col, double value);
	int getHeight() const;
	int getWidth() const;
	bool isValid() const;
	Matrix &operator =(Matrix rhs) {
			swap(matrix, rhs.matrix);
			swap(height, rhs. height);
			swap(width, rhs. width);
		return *this; //Returnerer en Matrix. this er en peker til en matrise!!!
	}
	Matrix& operator +=(const Matrix& rhs);
private:
	double **matrix;
	int height;
	int width;
};
ostream& operator<<(ostream& os, Matrix& m);
Matrix operator +(const Matrix& lhs, const Matrix& rhs);
