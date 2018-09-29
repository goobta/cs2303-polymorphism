#include <iostream>
#include <cstdlib>
#include "organism.h"

bool Organism::isPrey() {
	return false;
}

void Organism::generateId() {
	id = rand();
}

long int Organism::getId() {
	return id;
}

int Organism::getX() {
	return -1;
}

int Organism::getY() {
	return -1;
}

void Organism::step() {
	std::cout << "ID: " << getId() << std::endl;
}

Organism::~Organism() {}
