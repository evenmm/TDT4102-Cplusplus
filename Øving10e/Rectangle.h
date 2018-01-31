#pragma once
#include <iostream>
#include "Image.h"
#include "Shape.h"
#include "Line.h"
using std::cout;
using std::endl;

class Rectangle : public Shape {
public:
	Rectangle(int startX, int startY, int endX, int endY, Color setColor);
	virtual void draw(Image &drawBoard) const;
private:
	int startX, startY, endX, endY;
};