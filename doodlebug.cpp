#include <algorithm>
#include <random>

#include "doodlebug.h"

DoodleBug::DoodleBug(int startX, int startY, Game* g) {
	x = startX;
	y = startY;
	timeSteps = 0;
	hungerSteps = 0;
	game = g;

	generateId();
}

bool DoodleBug::isPrey() {
	return false;
}

int DoodleBug::getX() {
	return x;
}

int DoodleBug::getY() {
	return y;
}

void DoodleBug::step() {
	move();
	starve();
	breed();
	
	timeSteps++;
	hungerSteps++;
}

void DoodleBug::breed() {
	if(timeSteps < 8) return;

	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		if(game->isEmpty(x_coord, y_coord)) {
			game->addNode(x_coord, y_coord, new DoodleBug(x_coord, y_coord, game));
			game->incrementDoodleBugs();

			timeSteps = -1;
			return;
		}
	}
}

void DoodleBug::starve() {
	if(hungerSteps < 3) return;
	
	game->decrementDoodleBugs();
	game->deleteNode(x, y);
}

void DoodleBug::move() {
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		if(game->preyAt(x_coord, y_coord)) {
			game->decrementAnts();
			game->deleteNode(x_coord, y_coord);
			game->moveNode(x, y, x_coord, y_coord, this);
			x = x_coord;
			y = y_coord;
			
			hungerSteps = -1;
			
			return;
		}
	}
	
	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		if(game->isEmpty(x_coord, y_coord)) {
			game->moveNode(x, y, x_coord, y_coord, this);
			x = x_coord;
			y = y_coord;

			return;
		}
	}
}
