#include "genetic.h"

chromosome RouletteWheel_Selection::selection(vector<pair<chromosome,float>> &population)
{
    int sum=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        sum+=Genome().fitness(population[i].first);
    }
    int rand=random_num(0,sum);
    int current=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        current+=Genome().fitness(population[i].first);
        if(current>rand)
        {
            return population[i].first;
        }
    }
}


chromosome Tournament_Selection::selection(vector<pair<chromosome,float>> &population)
{
    vector <pair<vector<int>,float>> vec;

    for(int i=0;i<k;++i)
    {
        int r=random_num(0,POPULATION_SIZE);
        vec.push_back(population[r]);
    }
    float min=vec[0].second;
    chromosome c;
    for(int i=0;i<k;++i)
    {
        if(vec[i].second<min)
        {
            c=vec[i].first;
        }
    }
    return c;
}

