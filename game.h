#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "organism.h"

class Game {
	private:
		Organism*** board;
		Config config;	
		int turn;
		int totalAnts;
		int activeAnts;
		int totalDoodlebugs;
		int activeDoodlebugs;
	public:
		Game(Organism*** b, Config &conf);
		Organism*** getBoard();
		int step();
		void deleteNode(int x, int y);
		void addNode(int x, int y, Organism* o);
		void moveNode(int x, int y, Organism* o);
		Organism* getNode(int x, int y);
		void printGame();
};

Game* initGame(Config &config);
#endif
