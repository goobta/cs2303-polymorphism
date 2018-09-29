#include <unordered_set>
#include <iostream>
#include "game.h"
#include "config.h"
#include "ant.h"
#include "doodlebug.h"
#include "organism.h"

/**
 * @brief intialize the game
 *
 * @param config reference to global config object
 *
 * @return pointer to the game object
 */
Game* initGame(Config &config) {
	// Calculate the area of the grid
	int gridArea = config.getGridSize() * config.getGridSize();

	// Randomly determine all ant pos
	int antPos[config.getInitAnts()] = {};
	for(int i = 0; i < config.getInitAnts(); i++) {
		antPos[i] = rand() % gridArea;
	}

	// Randomly deteremien all db pos
	int dbPos[config.getInitDoodleBugs()] = {};
	for(int i = 0; i < config.getInitDoodleBugs(); i++) {
		dbPos[i] = rand() % gridArea;
	}

	// Initialize a new board
	Organism*** board = new Organism**[config.getGridSize()];
	// Intialize the game
	Game* game = new Game(board, config);

	// Create a global counter
	int counter = 0;
	for(int i = 0; i < config.getGridSize(); i++) {
		// Create row
		board[i] = new Organism*[config.getGridSize()];
		
		for(int j = 0; j < config.getGridSize(); j++) {
			// Intilize the pointer
			board[i][j] = NULL;

			// If the current pos is for a db, populate it
			bool db = false;
			for(int k = 0; k < config.getInitDoodleBugs(); k++) {
				if(dbPos[k] == counter) {
					board[i][j] = new DoodleBug(j, i, game);
					db = true;
				}
			}

			// If the current pos is for an an, populate it
			for(int k = 0; k < config.getInitAnts(); k++) {
				if(antPos[k] == counter) {
					// if there is already a doodlbug there, then insert an ant on the
					// next square
					if(!db) {
						board[i][j] = new Ant(j, i, game);
					} else {
						antPos[k]++;
					}
				}
			}

			// Increment counter
			counter++;
		}
	}

	// Return game
	return game;
}

/**
 * @brief Constructor for Game
 *
 * @param b board of organisms
 * @param conf reference to config object
 */
Game::Game(Organism*** b, Config &conf) {
	// initlize local vars
	board = b;
	config = conf;
	turn = 0;

	// initialize counter vars
	totalAnts = config.getInitAnts();
	activeAnts = totalAnts;
	totalDoodlebugs = config.getInitDoodleBugs();
	activeDoodlebugs = totalDoodlebugs;
}

/**
 * @brief Print the current state of the board
 */
void Game::printGame() {
	for(int i = 0; i < config.getGridSize(); i++) {
		for(int j = 0; j < config.getGridSize(); j++) {
			// If the pointer is null, then print a space
			if(board[i][j] == NULL) {
				std::cout << " ";
				// print a o for an ant
			} else if(board[i][j]->isPrey()) {
				std::cout << "o";
				// print an x for a db
			} else {
				std::cout << "x";
			}
		}

		// add spacing
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

/**
 * @brief Perform a turn 
 *
 * @return 1 if there is nothing left, 0 otherwise
 */
int Game::step() {
	std::unordered_set<long int> processedIds;

	// For each element, call the step function
	for(int i = 0; i < config.getGridSize(); i++) {
		for(int j = 0; j < config.getGridSize(); j++) {
			if(board[i][j] != NULL && !processedIds.count(board[i][j]->getId())) {
				processedIds.insert(board[i][j]->getId());
				board[i][j]->step();
			}
		}
	}
	
	// Increment turn var
	turn++;
	return totalDoodlebugs + totalAnts == 0;
}

/**
 * @brief Helper function to determine position is empty
 *
 * @param x desired x pos to check
 * @param y desired y pos to check
 *
 * @return true if empty, false otherwise
 */
bool Game::isEmpty(int x, int y) {
	// Make sure the input is within bounds
	if(x < 0 || x >= config.getGridSize() || y < 0 || y >= config.getGridSize()) {
		return 0;
	}

	return board[y][x] == NULL;
}

/**
 * @brief add a new node to the board
 *
 * @param x x pos of the node
 * @param y y pos of the node
 * @param o pointer to Organism obj
 */
void Game::addNode(int x, int y, Organism* o) {
	board[y][x] = o;
}

/**
 * @brief Move the location of a node
 *
 * @param xOld old x pos of node
 * @param yOld old y pos of node
 * @param xNew new x pos of node
 * @param yNew new y pos of node
 * @param o pointer to Organism object
 */
void Game::moveNode(int xOld, int yOld, int xNew, int yNew, Organism* o) {
	board[yNew][xNew] = o;
	board[yOld][xOld] = NULL;
}

/**
 * @brief Increment the number of ants
 */
void Game::incrementAnts() {
	totalAnts++;
	activeAnts++;

	if(activeAnts > config.getGridSize() * config.getGridSize()) {
		activeAnts = config.getGridSize() * config.getGridSize();
	}
}

/**
 * @brief Decrement the number of active ants
 */
void Game::decrementAnts() {
	activeAnts--;
}

/**
 * @brief Increment the number of doodlebugs
 */
void Game::incrementDoodleBugs() {
	totalDoodlebugs++;
	activeDoodlebugs++;
}

/**
 * @brief decrement the number of active doodlebugs
 */
void Game::decrementDoodleBugs() {
	activeDoodlebugs--;
}

/**
 * @brief Delete a node on the board
 *
 * @param x x pos of node
 * @param y y pos of node
 */
void Game::deleteNode(int x, int y) {
	delete board[y][x];
	board[y][x] = NULL;
}

/**
 * @brief Determine if there is an ant at a certain pos
 *
 * @param x x pos of node
 * @param y y pos of node
 *
 * @return true if ant, false otherwise
 */
bool Game::preyAt(int x, int y) {
	// Determine if pos is in bounds
	if(x < 0 || x >= config.getGridSize() || y < 0 || y >= config.getGridSize()) {
		return false;
	}

	return board[y][x] != NULL && board[y][x]->isPrey();
}

/**
 * @brief Getter for the number of turns
 *
 * @return  number of turns that have elsped
 */
int Game::getTurn() {
	return turn;
}
