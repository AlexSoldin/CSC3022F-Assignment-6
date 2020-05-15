# README for CSC3022F Assignment 6

## main.cpp
This is the main driver class of this assignment. This class creates an object of the State.cpp class pertaining to each state. Additionally, objects from the Transition.cpp class are used to store all possible transitions from each state. The Value Iteration algorithm is used to find the optimal value for each state specified by the grid.

## Makefile
The Makefile compiles and links all necessary files into the main executable. 

The input is of the form: ./main  

Some examples have been commented out in the Makfile. The main commands include:
* make - compiles files
* make run - runs executable according to specific instruction
* make clean - removes executables