#pragma once
#include "Image.h"
#include "Shape.h"

class Line : public Shape {
public:
	Line(int startX, int startY, int endX, int endY, Color setColor);
	virtual void draw(Image &drawBoard) const;
private:
	int startX, startY, endX, endY;
};
