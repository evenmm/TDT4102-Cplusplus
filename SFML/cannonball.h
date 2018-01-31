#pragma once
#include <iostream>
#include <math.h> 
using namespace std;

double acclY();

double velY(double initVelocityY,double time);

double posX(double initPositionX, double initVelocityX, double time);

double posY(double initPositionY, double initVelocityY, double time);

void printTime(double time);

double flightTime(double initVelocityY);

// Ber brukeren om to tall, en vinkel (i grader), og en fart.
// Disse verdiene skal lagres i minnet som pekerne
// theta og absVelocity peker paa.
void getUserInput(double *theta, double *absVelocity);

// Konverterter fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
// gitt vinkelen theta. Disse komponentene lagres i minnet.
void getVelocityVector(double theta, double absVelocity,
	double *velocityX, double *velocityY);double getDistanceTraveled(double velocityX, double velocityY);double targetPractice(double distanceToTarget,
	double velocityX,
	double velocityY);void playTargetPractice();