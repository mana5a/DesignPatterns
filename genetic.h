#include<bits/stdc++.h>
#include "helper.h"
using namespace std;

#define POPULATION_SIZE 10

#define NUM_CITY 10

#define CHR_SIZE 11

enum MutationType
{
    Swap, Inversion,Scramble
};

typedef vector<int> chromosome;

class Strategy_Mutation
{
  int a_;
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

class Genome
{
    private:
    vector<vector<int>> dist_mat;
    vector<pair<chromosome, float>> population;
    Strategy_Mutation *strategy_mutation_;

    public:
    Genome();
    void init_population();
    
    // chromosome mutation(chromosome chr);
    void set_mutation_strategy(int);
    void selection();
    float fitness(chromosome chr);

    void display_population();
    void display_chromosome(chromosome chr,float fit);
    void display_dist_mat();

    void run_GA();
};