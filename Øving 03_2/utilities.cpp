#pragma once
#include <iostream>
#include "utilities.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int randomWithLimits(int lowerLimit, int upperLimit) {
	return (lowerLimit + (rand() % (upperLimit - lowerLimit +1)));
}
