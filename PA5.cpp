#include <iostream>
#include <random>
#include "config.h"
#include "game.h"

int getUserInput(int argc, char **argv, Config &conf) {
	if (argc < 7) {
		conf.setGridSize(20);
		conf.setInitDoodleBugs(5);
		conf.setInitAnts(100);
		conf.setTimeSteps(1000);
		conf.setSeed(1);
		conf.setPause(false);
	} else if (argc == 6) {
		conf.setGridSize(atoi(argv[1]));
		conf.setInitDoodleBugs(atoi(argv[2]));
		conf.setInitAnts(atoi(argv[3]));
		conf.setTimeSteps(atoi(argv[4]));
		conf.setSeed(atoi(argv[5]));
		conf.setPause(false);
	} else if (argc == 7) {
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

int main(int argc, char **argv) {
	Config *config = new Config();

	if(!getUserInput(argc, argv, *config)) {
		std::cout << "Error parsing user input.\n" <<
			"Please use the syntax ./PA5 gridsize #doodlebugs #ants time seed pause"
			<< std::endl;
	}

	srand(config->getSeed());
	Game* g = initGame(*config);

	for(int i = 0; i < config->getTimeSteps(); i++) {
		g->printGame();
		g->step();

		if(config->getPause()) {
			std::cout << "Press any key to see the next generation" << std::endl;
			getchar();
		}
	}

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
