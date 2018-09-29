#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"
#include "game.h"

class DoodleBug: public Organism {
	private:
		int timeSteps;
		int hungerSteps;
		int x;
		int y;
		Game* game;

		void breed();
		void move();
		void starve();
	public:
		DoodleBug(int x, int y, Game* g);
		void step();
		bool isPrey();
		int getX();
		int getY();
};

#endif
