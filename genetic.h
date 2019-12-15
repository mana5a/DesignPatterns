#include <bits/stdc++.h>
using namespace std;

#define K 3

#define SELECTION_TYPES 2

#define MUTATION TYPES 3

#define POPULATION_SIZE 10

#define NUM_CITY 10

#define CHR_SIZE 11

#define GENERATIONS 100

#define CROSSOVER_RATE 0.6

#define MUTATION_RATE 0.4

enum MutationType
{
	Swap,
	Inversion,
	Scramble
};

enum SelectionType
{
	RouletteWheel,
	Tournament
};

typedef vector<int> chromosome;

typedef vector<pair<vector<int>, float>> chr_set;

class Strategy_Mutation
{
public:
	virtual ~Strategy_Mutation() = 0;
	virtual chromosome mutation(chromosome chr) = 0;
};

class Swap_Mutation : public Strategy_Mutation
{
public:
	chromosome mutation(chromosome chr);
};

class Inversion_Mutation : public Strategy_Mutation
{
public:
	chromosome mutation(chromosome chr);
};

class Scramble_Mutation : public Strategy_Mutation
{
public:
	chromosome mutation(chromosome chr);
};

class Strategy_Selection
{
public:
	virtual ~Strategy_Selection() = 0;
	virtual chromosome selection(chr_set) = 0;
};

class Tournament_Selection : public Strategy_Selection
{
public:
	chromosome selection(chr_set);
};

class RouletteWheel_Selection : public Strategy_Selection
{
public:
	chromosome selection(chr_set);
};

class Memento
{
	private:
		int generation;
		chr_set population_state;
		MutationType mutation_type_state;
		SelectionType selection_type_state;
		friend class Genome;
	public:
		Memento(int generation, chr_set population, MutationType mutation, SelectionType selection);
};

class Genome
{
private:
	vector<vector<int>> dist_mat;
	chr_set population;
	int generation;
	Strategy_Mutation *strategy_mutation_;
	Strategy_Selection *strategy_selection_;
	MutationType mutation_type_;
	SelectionType selection_type_;

public:
	Genome();
	void init_population();

	void set_mutation_strategy(int);
	void set_selection_strategy(int);
	float fitness(chromosome chr);

	chr_set crossover(chromosome p1, chromosome p2);

	void display_population();
	void display_chromosome(chromosome chr, float fit);
	void display_dist_mat();
	void operations_set();

	Memento createMemento();
	void reinstateMemento();
  	void saveState();
  	vector <Memento > states;

	void run_GA();
};