#pragma once
#include <iostream>
#include "cannonball.h"
using namespace std;

double acclY() {
	return -9.81;
}

double velY(double initVelocityY, double time) {
	return (initVelocityY + time*acclY());
}

double posX(double initPositionX, double initVelocityX, double time) {
	return (initPositionX + initVelocityX*time);
}

double posY(double initPositionY, double initVelocityY, double time) {
	return (initPositionY + initVelocityY*time + time*time/2*acclY());
}

void printTime(double time) {
	int time2 = static_cast<int>(time);
	int timemultiplum = time2 - (time2 % 3600);
	time2 -= timemultiplum; //Trekker fra alle hele timer;
	int minuttmultiplum = time2 - (time2 % 60);
	time2 -= minuttmultiplum; //Trekker fra alle hele minutter;
	cout << (timemultiplum / 3600) << " timer, "
		<< (minuttmultiplum / 60) << " minutter og "
		<< (time2) << " sekunder." << endl;
}

double flightTime(double initVelocityY) {
	return ((-2 * initVelocityY) / acclY());
}

void main() {
}
