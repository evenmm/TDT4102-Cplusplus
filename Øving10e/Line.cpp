#include "Image.h"
#include "Shape.h"
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

Line::Line(int startX, int startY, int endX, int endY, Color setColor) : Shape(setColor) {
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;
}

void Line::draw(Image &drawBoard) const {
	if ((endY - startY) / (endX - startX)) {
		for (int y = startY; y < endX + 1; y++) {
			int tempX = ((endX - startX)*(y - startY)) / (endY - startY) + startX;
			drawBoard.setPixelColor(tempX, y, this->getColor());
		}
	}
	else {
		for (int x = startX; x < endX + 1; x++) {
			int tempY = ((endY - startY)*(x - startX)) / (endX - startX) + startY;
			drawBoard.setPixelColor(x, tempY, this->getColor());
		}
	}
}