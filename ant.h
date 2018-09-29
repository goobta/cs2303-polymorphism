#ifndef ANT_H
#define ANT_H

#include "organism.h"
#include "game.h"

class Ant: public Organism {
	private:
		int timeSteps;
		int x;
		int y;
		Game* game;
 		void breed();
		void move();
	public:
		Ant(int x, int y, Game* game);
		void step();
		bool isPrey();
		int getX();
		int getY();
	//	~Ant();
};

#endif
