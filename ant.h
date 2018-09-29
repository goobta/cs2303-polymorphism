#ifndef ANT_H
#define ANT_H

#include "organism.h"

class Ant: public Organism {
	private:
		int timeSteps;
		int x;
		int y;
// 		void breed();
//		void move();
	public:
		Ant(int x, int y);
	//	void step();
		bool isPrey();
		int getX();
		int getY();
	//	~Ant();
};

#endif
