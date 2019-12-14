#include<bits/stdc++.h>

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