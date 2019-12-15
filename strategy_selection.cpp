#include "helper.h"

chromosome RouletteWheel_Selection::selection(vector<pair<chromosome,float>> population)
{
    int sum=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        sum+=population[i].second;
    }
    float rand=random_num(0,sum);
    float current=0;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        current+=population[i].second;
        if(int(current)>=int(rand)) return population[i].first;
        // if(AlmostEqualRelative(current,rand))
        // {
        //     return population[i].first;
        // }
    }
    //chromosome c={0,1,3,2,7,9,6,4,5,8,0};
    //return c;
}


chromosome Tournament_Selection::selection(vector<pair<chromosome,float>> population)
{
    vector <pair<vector<int>,float>> vec;

    for(int i=0;i<K;++i)
    {
        int r=random_num(0,POPULATION_SIZE);
        vec.push_back(make_pair(population[r].first,population[r].second));
    }
    float min=vec[0].second;
    chromosome c;
    for(int i=0;i<K;++i)
    {
        if(AlmostEqualRelative(min,vec[i].second))
        {
            c=vec[i].first;
        }

    }
    return c;
}

