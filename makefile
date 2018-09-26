CFLAGS=-g -Wall

all: PA5

clean:
	rm -f *.o PA5
	rm -rf html latex

PA5:
	gcc $(CFLAGS) example.c -o PA5

docs:
	doxygen