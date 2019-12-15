run_ga: genetic.o helper.o strategy_mutation.o strategy_selection.o
	g++ -o run_ga genetic.o helper.o strategy_mutation.o strategy_selection.o
strategy_mutation.o: strategy_mutation.cpp
	g++ -c strategy_mutation.cpp
strategy_selection.o: strategy_selection.cpp
	g++ -c strategy_selection.cpp
genetic.o: genetic.cpp
	g++ -c genetic.cpp
helper.o: helper.cpp
	g++ -c helper.cpp
clean:
	rm run_ga genetic.o helper.o strategy_mutation.o strategy_selection.o
