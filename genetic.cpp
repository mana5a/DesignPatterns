#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define POPULATION_SIZE 10

#define NUM_CITY 4

typedef vector<int> chromosome;

vector <int> prototype= {1,2,3};

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

bool compare(const pair<vector <int>, int>&i, const pair<vector <int>, int>&j)
{
    return i.second < j.second;
}

class Genome
{
    private:
    vector<vector<int>> dist_mat;
    vector<pair<chromosome, float>> population;
    
    public:

    float fitness(chromosome chr)
    {
        float distance=0;
        for(int i=0;i<chr.size()-1;++i)
        {
            distance+=dist_mat[chr[i]][chr[i+1]];
        }
        return distance;
    }

    void init_population()
    {
        for(int i=0;i<POPULATION_SIZE;++i)
        {
            vector <int> v=prototype;
            chromosome v1;
            v1.push_back(0);
            //cout<<"Size"<<v.size();
            for(int j=0;j<NUM_CITY-1;++j)
            {
                int r=random_num(0,v.size());
                v1.push_back(v[r]);
                v.erase(v.begin()+r);
            }
            v1.push_back(0);
            float fit=fitness(v1);
            population.push_back(make_pair(v1,fit));
        }
    }
    Genome()
    {
        dist_mat={{ 0, 10, 15, 20 }, 
                { 10, 0, 35, 25 }, 
                { 15, 35, 0, 30 }, 
                { 20, 25, 30, 0 } };
        init_population();
    }
    void display_population()
    {
        //cout<<"Population\n";
        //cout<<"Size:"<<population.size()<<"\n";
        for (int i = 0; i <POPULATION_SIZE; ++i)
        {
            for (int j = 0; j < population[i].first.size(); ++j)
            {
                cout << population[i].first[j]<<" ";
            }
            cout<<population[i].second<<"\n";
            // cout<<"Distance: "<<fitness(population[i]);
            // cout<<"Mutation:";
            // display_chromosome(mutation(population[i].first),population[i].second);
            cout<<"\n";
        }
    }

    void display_chromosome(chromosome chr,float fit)
    {
        for (int j = 0; j < chr.size(); ++j)
        {
            cout << chr[j]<<" ";
        }
        cout<<"\tFitness:"<<fit<<"\n";
    }

    void display_dist_mat()
    {
        cout<<"Distance Matrix\n";
        for (int i = 0; i < dist_mat.size(); ++i)
        {
            for (int j = 0; j < dist_mat[i].size(); ++j)
            {
                cout << dist_mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void run_GA()
    {
        cout<<"Initial Population\n";
        display_population();
        for(int i=0;i<POPULATION_SIZE;++i)
        {
            
            //display_chromosome(population[i].first,population[i].second);
            //cout<<"\n";
            mutation(population[i].first);
            population[i].second=fitness(population[i].first);
            
            //display_chromosome(population[i].first,population[i].second);
            //cout<<"\n";
            
        }
        cout<<"After Mutation\n";
        display_population();
        selection();
        cout<<"After Selection\n";
        display_population();
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

    void selection()
    {
        int sum=0;
        vector <pair<vector<int>,float>> ump;
        for(int i=0;i<POPULATION_SIZE;++i)
        {
            int val=fitness(population[i].first);
            //cout<<"val"<<val;
            sum+=val;
        }
        cout<<"sum:"<<sum<<"\n";
        vector <pair<vector<int>,float>> topk;
        for(int i=0;i<POPULATION_SIZE;++i)
        {
            int val=fitness(population[i].first);
            float select_prob=val/sum;

            topk.push_back(make_pair(population[i].first,select_prob));
            sort(topk.begin(),topk.end(),compare);

            

        }
        for(int i=0;i<POPULATION_SIZE;++i)
        {
            ump.push_back(make_pair(topk[i].first,fitness(topk[i].first)));
        }
        // vector <vector<int>> new_pop;
        // for(int i=0;i<population.size();++i)
        // {
        //     new_pop.push_back(ump[i].first);
        //}
        population=ump;
        // cout<<"Selection:\n";
        // for(int i=0;i<population.size();++i)
        // {
        //     display_chromosome(population[i].first, population[i].second);
        //     cout<<"\n";
        // }
        
    }



};


int main()
{
    Genome gene;
    gene.run_GA();
    //gene.display_population();
    //gene.display_dist_mat();
    //gene.selection();
}   