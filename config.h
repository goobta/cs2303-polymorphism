#ifndef CONFIG_H
#define CONFIG_H

class Config {
	private:
		int gridSize;
		int initDoodleBugs;
		int initAnts;
		int timeSteps;
		int seed;
		bool pause;
	public:
		int getGridSize();
		int getInitDoodleBugs();
		int getInitAnts();
		int getTimeSteps();
		int getSeed();
		bool getPause();

		void setGridSize(int gridSize);
		void setInitDoodleBugs(int doodleBugs);
		void setInitAnts(int ants);
		void setTimeSteps(int timeSteps);
		void setSeed(int seed);
		void setPause(bool pause);
};

#endif
