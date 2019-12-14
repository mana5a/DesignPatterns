#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define POPULATION_SIZE 50

#define NUM_CITY 4

typedef vector<int> chromosome;

vector <int> prototype= {1,2,3};

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

class Genome
{
    private:
    vector<vector<int>> dist_mat;
    vector<chromosome> population;
    
    public:
    void init_population()
    {
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
    }
    Genome()
    {
        init_population();
        dist_mat={{ 0, 10, 15, 20 }, 
                { 10, 0, 35, 25 }, 
                { 15, 35, 0, 30 }, 
                { 20, 25, 30, 0 } };
    }
    void display_population()
    {
        cout<<"Population\n";
        cout<<"Size:"<<population.size()<<"\n";
        for (int i = 0; i < population.size(); i++)
        {
            for (int j = 0; j < population[i].size(); j++)
            {
                cout << population[i][j]<<" ";
            }
            // cout<<"Distance: "<<fitness(population[i]);
            cout<<"Mutation:";
            display_chromosome(mutation(population[i]));
            cout<<"\n";
        }
    }

    void display_chromosome(chromosome chr)
    {
        for (int j = 0; j < chr.size(); j++)
        {
            cout << chr[j]<<" ";
        }
    }
    void display_dist_mat()
    {
        cout<<"Distance Matrix\n";
        for (int i = 0; i < dist_mat.size(); i++)
        {
            for (int j = 0; j < dist_mat[i].size(); j++)
            {
                cout << dist_mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    float fitness(chromosome chr)
    {
        int distance=0;
        for(int i=0;i<chr.size()-1;i++)
        {
            distance+=dist_mat[chr[i]][chr[i+1]];
        }
        return 1/distance;
    }

    chromosome mutation(chromosome chr)
    {
        int r=random_num(1,chr.size()-1);
        int l=random_num(1,chr.size()-1);
        int temp=chr[l];
        chr[l]=chr[r];
        chr[r]=temp;
        return chr;
    }

    

};


int main()
{
    Genome gene;
    gene.display_population();
    gene.display_dist_mat();
}