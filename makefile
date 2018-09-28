CFLAGS=-g -Wall

all: PA5

clean:
	rm -f *.o PA5
	rm -rf PA5.d*
	rm -rf html latex

PA5: PA5.o config.o
	g++ $(CFLAGS) PA5.o config.o -o PA5

PA5.o: PA5.cpp config.h
	g++ $(CFLAGS) -c PA5.cpp

config.o: config.cpp config.h
	g++ $(CFLAGS) -c config.cpp

docs:
	doxygen
