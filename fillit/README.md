# Fillit

The project allowed us to get acquainted with a recurring problem in programming:
the search for the optimal solution among a huge set of opportunities in an acceptable time frame.
In this case, we needed to find a way to assemble this tetrimino set into the smallest possible area.

This implementation uses an exhaustive search through recursion.
The algorithm translates all digits into bits and works with shifts in the bitmask,
which makes it one of the fastest implementations of this project on our campus.

The [`fillit.en.pdf`](/fillit/fillit.en.pdf) file contains the technical documentation of the project.

## Input data

Tetrimino - figures from a classical tetris, consisting of 4 blocks.

**input_file** must contain from 1 to 26 tetriminos, which must comply with the following rules:
- exactly 4 lines of 4 characters
- all tetrimino should be separated by a new line
- characters can be either block ("**#**") or empty ("**.**")
- blocks cannot be separate

Сorrect data example:

![preview](https://i.ibb.co/QDVJP96/fillit-file.png)

Be careful if your data does not match at least one of the items in the list, the program will display an **“error”** and exit.

## Output data

A properly composed **input_file** will display the smallest possible square to accommodate all tetriminos labeled "A" to "Z"
in the order in which they were read from your input_file:

![preview](https://i.ibb.co/JQMRzQv/res-fillit.png)

## How to use on MACos
 
 1. open a terminal and go to the **Realization** folder
 2. run the **Makefile** using the command `make`
 3. run the command `./fillit input_file`
