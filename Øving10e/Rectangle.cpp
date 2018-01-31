#include <iostream>
#include "Image.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
using std::cout;
using std::endl;

Rectangle::Rectangle(int startX, int startY, int endX, int endY, Color setColor) 
	: Shape(setColor) {
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;
}

void Rectangle::draw(Image &drawBoard) const {
	for (int x = startX; x < endX + 1; x++) {
		drawBoard.setPixelColor(x, endY, this->getColor());
		drawBoard.setPixelColor(x, startY, this->getColor());
	}
	for (int y = startY; y < endY + 1; y++) {
		drawBoard.setPixelColor(startX, y, this->getColor());
		drawBoard.setPixelColor(endX, y, this->getColor());
	}
}