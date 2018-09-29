#include <algorithm>
#include <random>
#include <iostream>
#include "ant.h"

Ant::Ant(int startX, int startY, Game* g) {
	x = startX;
	y = startY;
	game = g;
	timeSteps = 0;
	
	generateId();
}

bool Ant::isPrey() {
	return true;
}

int Ant::getX() {
	return x;
}

int Ant::getY() {
	return y;
}

void Ant::step() {
	move();
	breed();
	timeSteps++;
}

void Ant::move() {
	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

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

void Ant::breed() {
	if(timeSteps < 3) return;

	int moves[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  std::random_device rd;
  std::mt19937 g(rd());

	std::shuffle(std::begin(moves), std::end(moves), g);

	for(int i = 0; i < 4; i++) {
		int x_coord = x + moves[i][0];
		int y_coord = y + moves[i][1];

		if(game->isEmpty(x_coord, y_coord)) {
			game->addNode(x_coord, y_coord, new Ant(x_coord, y_coord, game));
			game->incrementAnts();

			timeSteps = 0;
			return;
		}
	}
}
