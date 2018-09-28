#include "config.h"

int Config::getGridSize() {
	return gridSize;
}

int Config::getInitDoodleBugs() {
	return initDoodleBugs;
}

int Config::getInitAnts() {
	return initAnts;
}

int Config::getTimeSteps() {
	return timeSteps;
}

int Config::getSeed() {
	return seed;
}

bool Config::getPause() {
	return pause;
}

void Config::setGridSize(int gs) {
	gridSize = gs;
}

void Config::setInitDoodleBugs(int db) {
	initDoodleBugs = db;
}

void Config::setInitAnts(int ants) {
	initAnts = ants;
}

void Config::setTimeSteps(int ts) {
	timeSteps = ts;
}

void Config::setSeed(int s) {
	seed = s;
}

void Config::setPause(bool p) {
	pause = p;
}
