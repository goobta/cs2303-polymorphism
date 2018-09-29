#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"

class DoodleBug: public Organism {
	private:
		int timeSteps;
		int hungerSteps;
		int x;
		int y;
	//	void breed();
	//	void move();
	//	void starve();
	public:
		DoodleBug(int x, int y);
	//	void step();
		bool isPrey();
		int getX();
		int getY();
	//	~DoodleBug();
};

#endif
