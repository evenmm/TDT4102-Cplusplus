#pragma once
#include "Image.h"

class Shape {
public:
	Shape(Color setColor);
	const Color getColor() const;
	virtual void draw(Image &drawBoard) const = 0;
	//Pure virtual function må redefineres i arvede klasser for å brukes fordi 
	//superklassen ikke har nok egenskaper til at et kall gir mening.
	//Abstrakte klasser kan ikke instanseres eller gjøre noe som krever et objekt.
private:
	Color myColor;
};
