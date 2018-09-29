#include <iostream>
#include <cstdlib>
#include "organism.h"

/**
 * @brief if the Organism is a prey
 *
 * @return false
 */
bool Organism::isPrey() {
	return false;
}

/**
 * @brief Generate a random ID for the Organism
 */
void Organism::generateId() {
	id = rand();
}

/**
 * @brief Getter for the ID
 *
 * @return id of organism
 */
long int Organism::getId() {
	return id;
}

/**
 * @brief Getter for the X pos of the organism
 *
 * @return -1
 */
int Organism::getX() {
	return -1;
}

/**
 * @brief Getter for the y pos of the organism
 *
 * @return  -1
 */
int Organism::getY() {
	return -1;
}

/**
 * @brief Run a turn on the organism. Print outs the ID if the organism isn't
 * extended via a subclass
 */
void Organism::step() {
	std::cout << "ID: " << getId() << std::endl;
}

/**
 * @brief Placeholder for destructor
 */
Organism::~Organism() {}
