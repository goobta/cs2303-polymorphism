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

	Organism* board[config.getGridSize()][config.getGridSize()] = {};

	int counter = 0;
	for(int i = 0; i < config.getGridSize(); i++) {
		for(int j = 0; j < config.getGridSize(); j++) {
			bool db = false;

			for(int k = 0; k < config.getInitDoodleBugs(); k++) {
				if(dbPos[k] == counter) {
					board[i][j] = new DoodleBug();
					db = true;
				}
			}

			for(int k = 0; k < config.getInitAnts(); k++) {
				if(antPos[k] == counter) {
					if(!db) {
						board[i][j] = new Ant(i, j);
						continue;
					} else {
						antPos[k]++;
					}
				}
			}

			if(!db) {
				board[i][j] = NULL;
			}

			counter++;
		}
	}

	return new Game(*board, config);
}

Game::Game(Organism** b, Config &conf) {
	board = b;
	config = conf;
	turn = 0;
}

void Game::printGame() {
	for(int i = 0; i < config.getGridSize(); i++) {
		for(int j = 0; j < config.getGridSize(); j++) {
			if(&board[i][j] == NULL) {
				std::cout << " ";
			} else if(board[i][j].isPrey()) {
				std::cout << "o";
			} else {
				std::cout << "x";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
