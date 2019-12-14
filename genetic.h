#include<bits/stdc++.h>
#include "helper.h"
using namespace std;

#define POPULATION_SIZE 10

#define NUM_CITY 4

#define CHR_SIZE 5

typedef vector<int> chromosome;

class Genome
{
    private:
    vector<vector<int>> dist_mat;
    vector<pair<chromosome, float>> population;
    
    public:
    Genome();
    void init_population();
    
    chromosome mutation(chromosome chr);
    void selection();
    float fitness(chromosome chr);

    void display_population();
    void display_chromosome(chromosome chr,float fit);
    void display_dist_mat();

    void run_GA();
};

class Strategy_Mutation
{
  public:
    Strategy_Mutation();
  private:
    virtual chromosome justify(chromosome chr) = 0;
};

class Swap_Mutation: public Strategy_Mutation
{
  public:
    Swap_Mutation();
  private:
     chromosome justify(chromosome chr);
};

class Inversion_Mutation: public Strategy_Mutation
{
  public:
    Inversion_Mutation();
  private:
     chromosome justify(chromosome chr);
};

class Scramble_Mutation: public Strategy_Mutation
{
  public:
    Scramble_Mutation();
  private:
     chromosome justify(chromosome chr);
};