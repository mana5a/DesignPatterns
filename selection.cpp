#include<bits/stdc++.h>
#include<vector>

#define POPULATION_SIZE 10
#define k 3

using namespace std;

typedef vector<int> chromosome; 
//typedef vector<pair<vector<int>,float>> population;

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 


chromosome roulette_wheel_selection()
{
    int sum=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        sum+=fitness(population[i].first);
    }
    int rand=random_num(0,sum);
    int current=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        current+=fitness(population[i].first);
        if(current>rand)
        {
            return population[i].first;
        }
    }
}


chromosome tournament_selection()
{
    //vector <int> k;
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

