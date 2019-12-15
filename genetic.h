#include<bits/stdc++.h>
using namespace std;

#define k 3

#define SELECTION_TYPES 2

#define MUTATION TYPES 3

#define POPULATION_SIZE 10

#define NUM_CITY 10

#define CHR_SIZE 11

enum MutationType
{
    Swap, Inversion, Scramble
};

enum SelectionType
{
    RouletteWheel, Tournament
};

typedef vector<int> chromosome;

class Strategy_Mutation
{
  public:
  virtual ~Strategy_Mutation()=0;
  virtual chromosome mutation(chromosome chr)=0;
};

class Swap_Mutation: public Strategy_Mutation
{
  public:
    chromosome mutation(chromosome chr);
};

class Inversion_Mutation: public Strategy_Mutation
{
  public:
    chromosome mutation(chromosome chr);
};

class Scramble_Mutation: public Strategy_Mutation
{
  public:
    chromosome mutation(chromosome chr);
};

class Strategy_Selection
{
  public:
  virtual ~Strategy_Selection()=0;
  virtual chromosome selection(vector<pair<chromosome,float>>&)=0;
};

class Tournament_Selection: public Strategy_Selection
{
  public:
    chromosome selection(vector<pair<chromosome,float>>&);
};

class RouletteWheel_Selection: public Strategy_Selection
{
  public:
    chromosome selection(vector<pair<chromosome,float>>&);
};

class Genome
{
    private:
    vector<vector<int>> dist_mat;
    vector<pair<chromosome, float>> population;
    Strategy_Mutation *strategy_mutation_;
    Strategy_Selection *strategy_selection_;
    MutationType mutation_type_;
    SelectionType selection_type_;
    
    public:
    Genome();
    void init_population();
    
    // chromosome mutation(chromosome chr);
    void set_mutation_strategy(int);
    void set_selection_strategy(int);
    // void selection();
    float fitness(chromosome chr);

    void display_population();
    void display_chromosome(chromosome chr,float fit);
    void display_dist_mat();
    void operations_set();

    void run_GA();
};