#include "ant.h"

Ant::Ant(int startX, int startY) {
	x = startX;
	y = startY;
	timeSteps = 0;
	
	generateId();
}

bool Ant::isPrey() {
	return true;
}

int Ant::getX() {
	return x;
}

int Ant::getY() {
	return y;
}
