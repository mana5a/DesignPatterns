#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define POPULATION_SIZE 50

#define NUM_CITY 10

typedef vector<int> chromosome;

vector <int> prototype= {1,2,3,4,5,6,7,8,9};


//graph n*n

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

void init_population()
{
    vector <vector <int>> population;
    for(int i=0;i<POPULATION_SIZE;i++)
    {
        vector <int> v=prototype;
        vector <int> v1;
        v1.push_back(0);
        //cout<<"Size"<<v.size();
        for(int j=0;j<NUM_CITY-1;j++)
        {
            int r=random_num(0,v.size());
            v1.push_back(v[r]);
            v.erase(v.begin()+r);
        }
        v1.push_back(0);
        population.push_back(v1);
    }
   for (int i = 0; i < population.size(); i++)
    {
        for (int j = 0; j < population[i].size(); j++)
        {
            cout << population[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    init_population();
}


