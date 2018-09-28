#include "ant.h"

Ant::Ant(int startX, int startY) {
	x = startX;
	y = startY;
}

bool Ant::isPrey() {
	return true;
}
