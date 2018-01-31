#include <iostream>
#include "Image.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Canvas.h"
using std::cout;
using std::endl;

void Canvas::addShape(const Shape* newShape) {
	myShapes.push_back(newShape);
}

void Canvas::rasterizeTo(Image& drawBoard) const {
	for (unsigned int i = 0; i < this->myShapes.size(); i++) {
		this->myShapes[i]->draw(drawBoard);
	}
}

Canvas::Canvas() {
	myShapes = {};
}