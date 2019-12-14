run_ga: genetic.o helper.o
	g++ -o run_ga genetic.o helper.o
genetic.o: genetic.cpp
	g++ -c genetic.cpp
helper.o: helper.cpp
	g++ -c helper.cpp