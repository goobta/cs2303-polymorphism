#include "doodlebug.h"

DoodleBug::DoodleBug(int startX, int startY) {
	x = startX;
	y = startY;
	timeSteps = 0;
	hungerSteps = 0;

	generateId();
}

bool DoodleBug::isPrey() {
	return false;
}

int DoodleBug::getX() {
	return x;
}

int DoodleBug::getY() {
	return y;
}
