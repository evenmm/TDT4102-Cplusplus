#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::swap;
using std::ostream;

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
	Matrix &operator =(Matrix rhs);
	Matrix& operator +=(const Matrix& rhs);
	const Matrix& operator +(const Matrix& rhs) const;
	friend ostream& operator<<(ostream& os, const Matrix& myMatrix);
private:
	double **matrix;
	int height;
	int width;
};
