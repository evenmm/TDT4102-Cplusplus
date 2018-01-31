#pragma once
#include <iostream>
#include "cannonball.h"
#include "utilities.h"
#include <math.h> 
#define PI 3.14159265359
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

// Ber brukeren om to tall, en vinkel (i grader), og en fart.
// Disse verdiene skal lagres i minnet som pekerne
// theta og absVelocity peker paa.
void getUserInput(double *theta, double *absVelocity) {
	cout << "Skriv inn vinkel i grader: ";
	cin >> *theta;
	cout << "Skriv inn fart: ";
	cin >> *absVelocity;
}

// Konverterter fra grader til radianer
double degToRad(double deg) {
	return deg / 180 * PI;
}

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
	return (absVelocity * cos(degToRad(theta)));
}
double getVelocityY(double theta, double absVelocity) {
	return (absVelocity * sin(degToRad(theta)));
}

// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
// gitt vinkelen theta. Disse komponentene lagres i minnet.
void getVelocityVector(double theta, double absVelocity, 	double *velocityX, double *velocityY) {	*velocityX = getVelocityX(theta, absVelocity);	*velocityY = getVelocityY(theta, absVelocity);}double getDistanceTraveled(double velocityX, double velocityY) {	return flightTime(velocityY)*velocityX;}double targetPractice(double distanceToTarget, double velocityX, double velocityY) {	return abs(distanceToTarget - getDistanceTraveled(velocityX, velocityY));}void playTargetPractice() {	cout << "Visst fanden skal det skytes med skarpt! Du har 10 forsøk på å treffe blinken\n"
		<< "Blinken befinner seg et sted mellom 100 og 1000 meter unna deg. Du har 10 forsøk." << endl;
	int targetPosition = randomWithLimits(100, 1000); //Implementerer blink
	bool success = 0;								  //Initierer alle verdier
	int deviationFromTargetCentre = 0;
	double theta = 0;
	double absVelocity = 0;
	double velocityX = 0;
	double velocityY = 0;
	for (int i = 0; i < 10; i++) {
		cout << "Forsøk " << i + 1 << endl;
		getUserInput(&theta, &absVelocity); //Bruker velger vinkel og fart
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY); //Dekomponerer farten
		deviationFromTargetCentre = (unsigned int)targetPractice(targetPosition, velocityX, velocityY);
		if (deviationFromTargetCentre < 5) {
			success = 1;
			break;
		}
		cout << "Du bommet. (Du var " 
			<< deviationFromTargetCentre << " meter unna sentrum av målet.)" << endl;
	}
	if (success) {
		cout << "Du traff! (Du var " 
			<< deviationFromTargetCentre << " meter unna sentrum av målet)." << endl;
	}
	else {
		cout << "Ooops, du klarte det ikke. Fienden traff deg i stedet. Lykke til i neste liv." << endl;
	}}