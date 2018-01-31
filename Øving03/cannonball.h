#pragma once
#include <iostream>
using namespace std;

double acclY();

double velY(double initVelocityY,double time);

double posX(double initPositionX, double initVelocityX, double time);

double posY(double initPositionY, double initVelocityY, double time);

void printTime(double time);

double flightTime(double initVelocityY);
