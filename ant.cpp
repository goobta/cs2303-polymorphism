#include <algorithm>
#include <random>
#include <iostream>
#include "ant.h"

/**
 * @brief Constructor for Ant
 *
 * @param startX x pos of where ant is
 * @param startY y pos of were ant is
 * @param g pointer to the game
 */
Ant::Ant(int startX, int startY, Game* g) {
	// Set variables
	x = startX;
	y = startY;
	game = g;
	timeSteps = 0;
	
	// Generate a random ID for the ant
	generateId();
}

/**
 * @brief Informs the program that the ant is a prey
 *
 * @return true
 */
bool Ant::isPrey() {
	return true;
}

/**
 * @brief Getter for x
 *
 * @return x pos
 */
int Ant::getX() {
	return x;
}

/**
 * @brief Getter of y
 *
 * @return y pos
 */
int Ant::getY() {
	return y;
}

/**
 * @brief Do one turn for the ant
 */
void Ant::step() {
	// Do actions as per project requirements
	move();
	breed();

	// Increment timestep
	timeSteps++;
}

/**
 * @brief Move the ant as per project requirements
 */
void Ant::move() {
	// List all possible ways  for the ant to move
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	// Shuffle the position
  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		// Determine the new pos of the ant
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		// Ensure that the new position is free to move into
		if(game->isEmpty(x_coord, y_coord)) {
			// Move ant
			game->moveNode(x, y, x_coord, y_coord, this);
			// Update instance variables
			x = x_coord;
			y = y_coord;
			
			// Short circuit the program
			return;
		}
	}
}

/**
 * @brief Breed the ant
 */
void Ant::breed() {
	// Short circuit on timesteps
	if(timeSteps < 3) return;

	// Determine all possible positions for child
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	// Shuffle locatinos for child
  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		// Determine possible pos for child
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		// Ensure that new slot is empty
		if(game->isEmpty(x_coord, y_coord)) {
			// Add ant
			game->addNode(x_coord, y_coord, new Ant(x_coord, y_coord, game));
			// Increment counter
			game->incrementAnts();

			// Reset timesteps for instance
			timeSteps = -1;
			return;
		}
	}
}
