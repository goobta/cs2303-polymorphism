#include "config.h"

/**
 * @brief Getter for grid size
 *
 * @return gridsize
 */
int Config::getGridSize() {
	return gridSize;
}

/**
 * @brief Getter for intial number of doodle bugs
 *
 * @return inital number of doodlebugs
 */
int Config::getInitDoodleBugs() {
	return initDoodleBugs;
}

/**
 * @brief Getter for initial number of ants
 *
 * @return intial number of ants
 */
int Config::getInitAnts() {
	return initAnts;
}

/**
 * @brief Getter for desired timesteps
 *
 * @return user inputted value for timesteps
 */
int Config::getTimeSteps() {
	return timeSteps;
}

/**
 * @brief Getter for seed
 *
 * @return user inpuuted value for seed
 */
int Config::getSeed() {
	return seed;
}

/**
 * @brief getter for pause
 *
 * @return if the user wants the program to pause
 */
bool Config::getPause() {
	return pause;
}

/**
 * @brief setter for grid size
 *
 * @param gs new gridsize
 */
void Config::setGridSize(int gs) {
	gridSize = gs;
}

/**
 * @brief setter for initial number of doodle bugs
 *
 * @param db new # of doodlebugs
 */
void Config::setInitDoodleBugs(int db) {
	initDoodleBugs = db;
}

/**
 * @brief setter for initial number of ants
 *
 * @param ants new # of ants
 */
void Config::setInitAnts(int ants) {
	initAnts = ants;
}

/**
 * @brief setter for timesteps
 *
 * @param ts new # of timesteps
 */
void Config::setTimeSteps(int ts) {
	timeSteps = ts;
}

/**
 * @brief Setter for seed
 *
 * @param s new seed
 */
void Config::setSeed(int s) {
	seed = s;
}

/**
 * @brief Setter for pause functionality
 *
 * @param p true if want to pause, false otherwise
 */
void Config::setPause(bool p) {
	pause = p;
}
