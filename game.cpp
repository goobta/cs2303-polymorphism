#include <iostream>
#include "game.h"
#include "config.h"
#include "ant.h"
#include "doodlebug.h"
#include "organism.h"

Game* initGame(Config &config) {
	int gridArea = config.getGridSize() * config.getGridSize();

	int antPos[config.getInitAnts()] = {};
	for(int i = 0; i < config.getInitAnts(); i++) {
		antPos[i] = rand() % gridArea;
	}


	int dbPos[config.getInitDoodleBugs()] = {};
	for(int i = 0; i < config.getInitDoodleBugs(); i++) {
		dbPos[i] = rand() % gridArea;
	}

	Organism*** board = new Organism**[config.getGridSize()];

	int counter = 0;
	for(int i = 0; i < config.getGridSize(); i++) {
		board[i] = new Organism*[config.getGridSize()];
		
		for(int j = 0; j < config.getGridSize(); j++) {
			board[i][j] = NULL;

			bool db = false;
			for(int k = 0; k < config.getInitDoodleBugs(); k++) {
				if(dbPos[k] == counter) {
					board[i][j] = new DoodleBug(i, j);
					db = true;
				}
			}

			for(int k = 0; k < config.getInitAnts(); k++) {
				if(antPos[k] == counter) {
					if(!db) {
						board[i][j] = new Ant(i, j);
					} else {
						antPos[k]++;
					}
				}
			}

			counter++;
		}
	}

	return new Game(board, config);
}

Game::Game(Organism*** b, Config &conf) {
	board = b;
	config = conf;
	turn = 0;
}

void Game::printGame() {
	for(int i = 0; i < config.getGridSize(); i++) {
		for(int j = 0; j < config.getGridSize(); j++) {
			if(board[i][j] == NULL) {
				std::cout << " ";
			} else if(board[i][j]->isPrey()) {
				std::cout << "o";
			} else {
				std::cout << "x";
			}
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}
