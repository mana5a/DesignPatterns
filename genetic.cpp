#include "genetic.h"

vector <int> prototype= {1,2,3};

float Genome::fitness(chromosome chr)
{
    float distance=0;
    for(int i=0;i<CHR_SIZE-1;++i)
    {
        distance+=dist_mat[chr[i]][chr[i+1]];
    }
    return distance;
}

void Genome::init_population()
{
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        vector <int> v=prototype;
        chromosome v1;
        v1.push_back(0);
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
Genome::Genome()
{
    dist_mat={{ 0, 10, 15, 20 }, 
            { 10, 0, 35, 25 }, 
            { 15, 35, 0, 30 }, 
            { 20, 25, 30, 0 } };

    // {{0 ,42 ,30 ,11 ,16 ,48 ,23 ,25 ,28 ,34},
        // {42 ,0 ,20 ,30 ,42 ,40 ,47 ,21 ,28 ,21},
        // {30 ,20 ,0 ,34 ,32 ,34 ,39 ,46 ,49 ,12},
        // {11 ,30 ,34 ,0 ,37 ,39 ,30 ,36 ,34 ,43},
        // {16 ,42 ,32 ,37 ,0 ,30 ,24 ,48 ,34 ,19},
        // {48 ,40 ,34 ,39 ,30 ,0 ,50 ,15 ,10 ,43},
        // {23 ,47 ,39 ,30 ,24 ,50 ,0 ,36 ,39 ,13},
        // {25 ,21 ,46 ,36 ,48 ,15 ,36 ,0 ,38 ,50},
        // {28 ,28 ,49 ,34 ,34 ,10 ,39 ,38 ,0 ,28},
        // {34 ,21 ,12 ,43 ,19 ,43 ,13 ,50 ,28 ,0}}
    init_population();
}
void Genome::display_population()
{
    for (int i = 0; i <POPULATION_SIZE; ++i)
    {
        for (int j = 0; j < population[i].first.size(); ++j)
        {
            cout << population[i].first[j]<<" ";
        }
        cout<<population[i].second<<"\n";
        cout<<"\n";
    }
}

void Genome::display_chromosome(chromosome chr,float fit)
{
    for (int j = 0; j < CHR_SIZE; ++j)
    {
        cout << chr[j]<<" ";
    }
    cout<<"\tFitness:"<<fit<<"\n";
}

void Genome::display_dist_mat()
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

void Genome::run_GA()
{
    cout<<"Initial Population\n";
    display_population();
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        mutation(population[i].first);
        population[i].second=fitness(population[i].first);
    }
    cout<<"After Mutation\n";
    display_population();
    selection();
    cout<<"After Selection\n";
    display_population();
}


chromosome Genome::mutation(chromosome chr)
{
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    int temp=chr[l];
    chr[l]=chr[r];
    chr[r]=temp;
    return chr;
}

void Genome::selection()
{
    int sum=0;
    vector <pair<vector<int>,float>> ump;
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        int val=fitness(population[i].first);
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
    population=ump;
    
}


int main()
{
    Genome gene;
    gene.run_GA();
}