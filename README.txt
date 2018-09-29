# CS2303 - Polymorphism

## Summary
This is a simulation between doodlebugs (predators) and ants (prey). Doodlebugs
can move, kill, breed, and starve, and ants can move and breed. Doodlebugs are
represented by an `x` and ants are represented by an `o`.

## Execution Directions
First do a `make` to compile the program. 

To run the program, run `./PA5 gridSize #doodlebugs #ants #time_steps seed pause`,
where:

1. gridSize — an integer representing the number of cells along one dimension 
   of the grid (defaulting to 20)
2. #doodlebugs — an integer indicating the number of doodlebugs (default 5)
3. #ants — an integer indicating the number of ants (default 100)
4. #time_steps — the number of time steps to play (default 1000)
5. seed — an integer indicating the seed for the random number generator, with
   a zero meaning to use the current time as the seed (default seed value is 1)
6. pause — an indication as to whether to pause. Blank or zero means do not 
   pause. A non-negative value n means pause and print the grid after each nthstep.
   Wait for one character input before continuing.

## Principle Classes and Methods
This program is split into 5 main classes, which will be described below:

### Config
This is a simple class that stores the configuration for the whole program.

### Game
This is a class which manages the game. It stores the board, all instance
variables, and is in charge of calling the `step` function in all of the
Organisms. The `step` function is the real meat of this program, in that is
makes all of the Organisms move and interact

### Organism
An interface for any animal type to play on this game

### Ant
A prey in this game. Can't kill, and breeds after 3 turns

### Doodlebug
The predator in this game. Can kill, breeds after 8 turns, and starves after 3
