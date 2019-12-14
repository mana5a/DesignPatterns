#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define POPULATION_SIZE 50

#define NUM_CITY 5

typedef vector<int> chromosome;

vector <int> prototype= {1,2,3,4};

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

//graph n*n
class Genome
{
    private:
    vector<vector<int>(NUM_CITY)> dist_mat(NUM_CITY);
    vector<vector<int>> population;
    
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
            this.population.push_back(v1);
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
    display_population()
    {
        cout<<"Population\n";
        for (int i = 0; i < this.population.size(); i++)
        {
            for (int j = 0; j < this.population[i].size(); j++)
            {
                cout << this.population[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    display_dist_mat()
    {
        cout<<"Distance Matrix\n";
        for (int i = 0; i < this.dist_mat.size(); i++)
        {
            for (int j = 0; j < this.dist_mat[i].size(); j++)
            {
                cout << this.dist_mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

};


int main()
{
    Genome gene;
    gene.display_population();
    gene.display_dist_mat();
}


