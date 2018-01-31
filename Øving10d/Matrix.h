#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::ostream;

class Matrix {
public:
	Matrix();
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows);
	Matrix(const Matrix & rhs);
	~Matrix();
	void swap(Matrix& rhs);
	double get(int row, int col) const;
	void set(int row, int col, double value);
	int getHeight() const;
	int getWidth() const;
	bool isValid() const;
	Matrix &operator =(Matrix rhs);
	Matrix& operator +=(const Matrix& rhs);

	//Når jeg legger til disse to slutter ting å funke, 
	//og de fungerer heller ikke etter at de er kommentert ut
	//Matrix& operator *=(const Matrix& rhs);
	//const Matrix& operator *(const Matrix& rhs) const;

	friend ostream& operator<<(ostream& os, const Matrix& myMatrix);
private:
	double **matrix; //Nullindeksert
	int height;
	int width;
};
Matrix operator +(const Matrix& lhs, const Matrix& rhs);
