#pragma once
#include "Image.h"

class Shape {
public:
	Shape(Color setColor);
	const Color getColor() const;
	virtual void draw(Image &drawBoard) const = 0;
	//Pure virtual function m� redefineres i arvede klasser for � brukes fordi 
	//superklassen ikke har nok egenskaper til at et kall gir mening.
	//Abstrakte klasser kan ikke instanseres eller gj�re noe som krever et objekt.
private:
	Color myColor;
};
