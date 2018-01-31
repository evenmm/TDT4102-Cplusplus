#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( int width, int height ) {
	this->width = width;
	this->height = height;
	data = new Pixel[width*height];
	for (int i = 0; i < width*height; i++) {
		data[i] = Pixel(255, 255, 255);
	}
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
}

int Image::getWidth() const { //const betyr at this-objektet ikke kan endres
	return width;
}
int Image::getHeight() const  {
	return height;
}

const Pixel * Image::getScanLine(int line) const  { 
	//Både const og ikke for å kunne bruke safe når mulig og annen når ikke?
	return &data[line*width -1];
}
Pixel * Image::getScanLine(int line) {
	return &data[line*width - 1];
}

Color Image::getPixelColor( int x, int y ) const {
	 return data[y*width + x];
}
void Image::setPixelColor( int x, int y, const Color &color ) {
	data[y*width + x] = color;
}

void Image::fill( const Color &color ) {
	for (int i = 0; i < width*height; i++) {
		data[i] = color;
	}
}
