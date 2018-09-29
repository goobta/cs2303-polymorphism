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
		int step();

		Organism*** getBoard();

		void deleteNode(int x, int y);
		void addNode(int x, int y, Organism* o);
		void moveNode(int xOld, int yOld, int xNew, int yNew, Organism* o);
		Organism* getNode(int x, int y);
		bool isEmpty(int x, int y);

		void printGame();
};

Game* initGame(Config &config);
#endif
