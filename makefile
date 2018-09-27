CFLAGS=-g -Wall

all: PA5

clean:
	rm -f *.o PA5
	rm -rf html latex

PA5:
	g++ $(CFLAGS) PA5.cpp -o PA5

docs:
	doxygen
