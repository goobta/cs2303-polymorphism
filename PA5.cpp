#include <iostream>
#include <random>
#include "config.h"
#include "game.h"

/**
 * @brief Helper function to handle the user input
 *
 * @param argc len of CLI args
 * @param argv CLI args
 * @param conf reference to Config object
 *
 * @return 1 if successfull, 0 otherwise
 */
int getUserInput(int argc, char **argv, Config &conf) {
	// If the number of args is too small, then load defaults
	if (argc < 7) {
		conf.setGridSize(20);
		conf.setInitDoodleBugs(5);
		conf.setInitAnts(100);
		conf.setTimeSteps(1000);
		conf.setSeed(1);
		conf.setPause(false);
	} 
	// If there are only 6 args, that means that pause is to be defaulted
	else if (argc == 6) {
		conf.setGridSize(atoi(argv[1]));
		conf.setInitDoodleBugs(atoi(argv[2]));
		conf.setInitAnts(atoi(argv[3]));
		conf.setTimeSteps(atoi(argv[4]));
		conf.setSeed(atoi(argv[5]));
		conf.setPause(false);
	} 
	// Load from CLI
	else if (argc == 7) {
		conf.setGridSize(atoi(argv[1]));
		conf.setInitDoodleBugs(atoi(argv[2]));
		conf.setInitAnts(atoi(argv[3]));
		conf.setTimeSteps(atoi(argv[4]));
		conf.setSeed(atoi(argv[5]));

		if (atoi(argv[6]) == 0) {
			conf.setPause(false);
		} else {
			conf.setPause(true);
		}
	} else {
		return 0;
	}

	return 1;
}

/**
 * @brief main runner for program
 *
 * @param argc CLI args count
 * @param argv CLI counts
 *
 * @return 0 if successful, 1 otherwise
 */
int main(int argc, char **argv) {
	// Initialize config object
	Config *config = new Config();

	// Make sure that the user input is good
	if(!getUserInput(argc, argv, *config)) {
		std::cout << "Error parsing user input.\n" <<
			"Please use the syntax ./PA5 gridsize #doodlebugs #ants time seed pause"
			<< std::endl;
		return 1;
	}

	//set seed
	srand(config->getSeed());
	// Initialize game
	Game* g = initGame(*config);

	// Iterate through timesteps
	for(int i = 0; i < config->getTimeSteps(); i++) {
		// Print the game
		g->printGame();
		// Do the next step
		g->step();

		// Exit early if ants or doodlebugs are gone
		if(g->activeAnts == 0 || g->activeDoodlebugs == 0) break;

		// If pausing is set, then ask for user input
		if(config->getPause()) {
			std::cout << "Press any key to see the next generation" << std::endl;
			getchar();
		}
	}

	// Print out summary, as required
	std::cout << "=== SUMMARY ===" << std::endl;
	std::cout << "Command run: ./PA5" << config->getGridSize() << " "
						<< config->getInitDoodleBugs() << " "
						<< config->getInitAnts() << " "
						<< config->getTimeSteps() << " "
						<< config->getSeed() << " "
						<< config->getPause() << std::endl;

	std::cout << "Number of steps: " << g->getTurn() << std::endl;
	std::cout << "Total number of ants: " << g->totalAnts << std::endl;
	std::cout << "Active number of ants: " << g->activeAnts << std::endl;
	std::cout << "Total number of doodlebugs: " << g->totalDoodlebugs << std::endl;
	std::cout << "Active number of doodlebugs: " << g->activeDoodlebugs << std::endl;

	g->printGame();

	return 0;
}
