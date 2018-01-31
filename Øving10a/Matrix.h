#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Matrisen er nullindeksert, men under konstruksjon er brukes fysisk størrelse
class Matrix {
public:
	Matrix();
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows); //explicit fordi den ikke skal konvertere ting til matriser
	Matrix(const Matrix & rhs);
	~Matrix();
	double get(int row, int col) const;
	void set(int row, int col, double value);
	int getHeight() const;
	int getWidth() const;
	bool isValid() const;
	Matrix &operator =(Matrix rhs) { //Viktig! Bruker call-by-value for å opprette en kopi
			swap(matrix, rhs.matrix);
			swap(height, rhs. height);
			swap(width, rhs. width);
		return *this; //Returnerer en Matrix. this er en peker til en matrise!!!
	}
	Matrix& operator +=(const Matrix& rhs);
	//Matrix& operator *=(const Matrix& rhs);
	//Matrix& operator *(const Matrix& rhs) const;
private:
	double **matrix;
	int height;
	int width;
};
ostream& operator<<(ostream& os, Matrix& m);
Matrix operator +(const Matrix& lhs, const Matrix& rhs);
