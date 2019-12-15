# Design Patterns Project 2019
## Checkpointing and Strategy design pattern for Genetic Algorithm:
Strategy and Memento pattern have been used in tandem to enhance the working and implementation of the Genetic Algorithm. For the sake of this demonstration, the problem solved by the Genetic Algorithm is the Travelling Salesman Problem. <br>
Memento pattern has been applied to save the state of the population at each iteration. The undo option has been implemented as well. <br>
Strategy Pattern has been implemented to allow the user to pick the way the Genetic operations mutation and selection are being implemented.


To run: 

1. make

2. ./run_ga

To clear executables and object files

1. make clean