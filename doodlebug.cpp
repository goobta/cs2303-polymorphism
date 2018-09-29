#include <algorithm>
#include <random>

#include "doodlebug.h"

/**
 * @brief Constructor for doodlebug
 *
 * @param startX starting X pos of db
 * @param startY starting Y pos of db
 * @param g pointer to game
 */
DoodleBug::DoodleBug(int startX, int startY, Game* g) {
	// Intialize all instance vars
	x = startX;
	y = startY;
	timeSteps = 0;
	hungerSteps = 0;
	game = g;

	// Generate a random ID for the bug
	generateId();
}

/**
 * @brief If the instance is a prey
 *
 * @return false
 */
bool DoodleBug::isPrey() {
	return false;
}

/**
 * @brief Getter for x pos
 *
 * @return x pos
 */
int DoodleBug::getX() {
	return x;
}

/**
 * @brief Getter for Y pos
 *
 * @return  y pos
 */
int DoodleBug::getY() {
	return y;
}

/**
 * @brief do a turn for the instance
 */
void DoodleBug::step() {
	// Do actions as reuqired by project
	move();
	starve();
	breed();
	
	// Increment time vars
	timeSteps++;
	hungerSteps++;
}

/**
 * @brief Breed the doodlebgu
 */
void DoodleBug::breed() {
	// Short circuit if time isn't appropiate
	if(timeSteps < 8) return;

	// Determine all possible locations for child
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		// Ensure that desired pos is empty
		if(game->isEmpty(x_coord, y_coord)) {
			// Add pointer to game
			game->addNode(x_coord, y_coord, new DoodleBug(x_coord, y_coord, game));
			// Increment count
			game->incrementDoodleBugs();

			// Reset time var
			timeSteps = -1;
			return;
		}
	}
}

/**
 * @brief Check if the db is finna starve
 */
void DoodleBug::starve() {
	// Short circuit if time isn't appropiate
	if(hungerSteps < 3) return;
	
	// Decrement count
	game->decrementDoodleBugs();

	// Delete db
	game->deleteNode(x, y);
}

/**
 * @brief Move the doodlebug
 */
void DoodleBug::move() {
	// All possible moves
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	// Randomize moves
  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	// Check if there are any ants
	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		// if there is an ant
		if(game->preyAt(x_coord, y_coord)) {
			// Delte ant and move db
			game->decrementAnts();
			game->deleteNode(x_coord, y_coord);
			game->moveNode(x, y, x_coord, y_coord, this);
			// update intance vars
			x = x_coord;
			y = y_coord;
			
			hungerSteps = -1;
			
			return;
		}
	}
	
	// If there aren't any ants
	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		// if the spot is empty
		if(game->isEmpty(x_coord, y_coord)) {
			// Move the db
			game->moveNode(x, y, x_coord, y_coord, this);
			
			// update instance vars
			x = x_coord;
			y = y_coord;

			return;
		}
	}
}
