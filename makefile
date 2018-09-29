CFLAGS=-g -Wall

all: PA5

clean:
	rm -f *.o PA5
	rm -rf PA5.d*
	rm -rf html latex

PA5: PA5.o game.o ant.o doodlebug.o config.o organism.o
	g++ $(CFLAGS) PA5.o config.o game.o ant.o doodlebug.o organism.o -o PA5

PA5.o: PA5.cpp config.h game.h 
	g++ $(CFLAGS) -c PA5.cpp

ant.o: ant.cpp ant.h organism.h
	g++ $(CFLAGS) -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.h organism.h
	g++ $(CFLAGS) -c doodlebug.cpp

organism.o: organism.cpp organism.h
	g++ $(CFLAGS) -c organism.cpp

game.o: game.cpp config.h ant.h doodlebug.h
	g++ $(CFLAGS) -c game.cpp

config.o: config.cpp config.h
	g++ $(CFLAGS) -c config.cpp

docs:
	doxygen
