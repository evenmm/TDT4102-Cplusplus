#include <iostream>
#include <string>
#include "Image.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Canvas.h"
using std::cout;
using std::endl;
using std::string;
void testFunc();

int main(){
	Color red(255, 0, 0);
	Color blue(0, 0, 255);
	Image firstImage(1366, 768);
	firstImage.fill(Color(255, 255, 255));
	firstImage.setPixelColor(683, 384, red);
	Line firstLine(0, 0, 100, 101, red);
	firstLine.draw(firstImage);
	Rectangle firstRect(300, 300, 700, 400, blue);
	firstRect.draw(firstImage);
	saveImage(firstImage, "line");

	Image secondImage(1000, 600);
	Canvas vanGogh;
	vanGogh.addShape(&firstLine);
	vanGogh.addShape(&firstRect);
	vanGogh.rasterizeTo(secondImage);
	saveImage(secondImage, "vanGogh");
	return 0;
}

void testFunc() {

}