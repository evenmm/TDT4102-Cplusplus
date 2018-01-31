#pragma once
#include <iostream>
#include "Image.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Canvas {
public:
	Canvas();
	void addShape(const Shape* newShape);
	void rasterizeTo(Image& drawBoard) const;
private:
	vector<const Shape*> myShapes;
};
