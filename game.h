#ifndef GAME_H
#define GAME_H

#include "organism.h"

class Game {
	private:
		Organism** board;
		int turn;
	public:
		Game(Organism** b);
		Organism** getBoard();
		int step();
		void deleteNode(int x, int y);
		void addNode(int x, int y, Organism* o);
		void moveNode(int x, int y, Organism* o);
		Organism* getNode(int x, int y);
		void printGame();
};
#endif
