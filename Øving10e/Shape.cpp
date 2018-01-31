#include "Shape.h"
#include "Image.h"

Shape::Shape(Color setColor) : myColor(setColor) {}

const Color Shape::getColor() const {
	return myColor;
}

