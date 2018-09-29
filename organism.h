#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
	private:
		long int id;
	protected:
		void generateId();
	public:
		virtual void step();
		virtual bool isPrey();
		long int getId();
		virtual int getX();
		virtual int getY();
};

#endif
