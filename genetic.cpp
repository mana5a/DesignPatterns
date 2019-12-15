#include "helper.h"

vector <int> prototype= {1,2,3,4,5,6,7,8,9};

Strategy_Selection::~Strategy_Selection()
{}

Strategy_Mutation::~Strategy_Mutation()
{}

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
    dist_mat={{0 ,42 ,30 ,11 ,16 ,48 ,23 ,25 ,28 ,34},
        {42 ,0 ,20 ,30 ,42 ,40 ,47 ,21 ,28 ,21},
        {30 ,20 ,0 ,34 ,32 ,34 ,39 ,46 ,49 ,12},
        {11 ,30 ,34 ,0 ,37 ,39 ,30 ,36 ,34 ,43},
        {16 ,42 ,32 ,37 ,0 ,30 ,24 ,48 ,34 ,19},
        {48 ,40 ,34 ,39 ,30 ,0 ,50 ,15 ,10 ,43},
        {23 ,47 ,39 ,30 ,24 ,50 ,0 ,36 ,39 ,13},
        {25 ,21 ,46 ,36 ,48 ,15 ,36 ,0 ,38 ,50},
        {28 ,28 ,49 ,34 ,34 ,10 ,39 ,38 ,0 ,28},
        {34 ,21 ,12 ,43 ,19 ,43 ,13 ,50 ,28 ,0}};
    // {{ 0, 10, 15, 20 }, 
    // { 10, 0, 35, 25 }, 
    // { 15, 35, 0, 30 }, 
    // { 20, 25, 30, 0 } };
    strategy_mutation_ = new Swap_Mutation;
    mutation_type_=Swap;
    strategy_selection_ = new RouletteWheel_Selection;
    selection_type_=RouletteWheel;
    init_population();
}

void Genome::operations_set()
{
    cout<<"Mutation Type: "<<mutation_type_;
    cout<<"\nSelection Type: "<<selection_type_;
    cout<<"\n";
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

void Genome::set_mutation_strategy(int type)
{
    delete strategy_mutation_;
    if (type == Swap)
    {
        strategy_mutation_ = new Swap_Mutation;
        mutation_type_= Swap;
    }
    else if (type == Inversion)
    {
        strategy_mutation_ = new Inversion_Mutation;
        mutation_type_=Inversion;
    }
    else if (type == Scramble)
    {
        strategy_mutation_ = new Scramble_Mutation;
        mutation_type_=Scramble;
    }
}

void Genome::set_selection_strategy(int type)
{
    delete strategy_selection_;
    if (type == RouletteWheel)
    {
        strategy_selection_ = new RouletteWheel_Selection;
        selection_type_=RouletteWheel;
    }
    else if (type == Tournament)
    {
        strategy_selection_ = new Tournament_Selection;
        selection_type_=Tournament;
    }
}

chr_set Genome::crossover(chromosome p1, chromosome p2)
{
    chr_set children;
    chromosome c1,c2;
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    if(r==l) 
    {
      if(r!=CHR_SIZE-2)
        ++r;
      else
        --l;
    }
    for(int i=0;i<r;++i)
    {
        c1.push_back(p1[i]);
        c2.push_back(p2[i]);
    }
    for(int i=l;i>=r;--i)
    {
        c1.push_back(p2[l]);  //4 to 6, start w 6 then 5 then 4
        c2.push_back(p1[l]);
    }
    for(int i=l+1;i<CHR_SIZE-1;++i)
    {
        c1.push_back(p1[i]);
        c2.push_back(p2[i]);
    }
   
    children.push_back(make_pair(c1,fitness(c1)));
    children.push_back(make_pair(c2,fitness(c2)));
    return children;
}

void Genome::run_GA()
{
    cout<<"Initial Population\n";
    display_population();
    float threshold=population[0].second;
    int gen=0;
    for(int i=0;i<GENERATIONS;++i)
    {
        cout<<"Generation #"<<i<<"\n";
        int k=0;
        while(k<int(CROSSOVER_RATE*POPULATION_SIZE))
        {
            int r=random_num(0,POPULATION_SIZE);
            int l=0;
            do
            {
             l=random_num(0,POPULATION_SIZE);   
            } while (l!=r);         
            chr_set chl=crossover(population[r].first,population[l].first);
            // population[r]=chl[0];
            // population[l]=chl[1];
            ++k;
        }
        cout<<"After Crossover\n";
        display_population();

        set_mutation_strategy(Swap);
        int j=0;
        while(j<int(MUTATION_RATE*POPULATION_SIZE))
        {
            int i=random_num(0,POPULATION_SIZE);
            population[i].first=strategy_mutation_->mutation(population[i].first);
            population[i].second=fitness(population[i].first);
            ++j;
        }
        cout<<"After Mutation\n";
        display_population();
        
        set_selection_strategy(Tournament);
        vector<pair<chromosome,float>> new_pop;
        float avg_fitness=0;
        for(int j=0;j<POPULATION_SIZE;++j)
        {
            chromosome c;//=population[i].first;
            c=strategy_selection_->selection(population);
            float fit=fitness(c);
            new_pop.push_back(make_pair(c,fit));
            avg_fitness+=fit;
            if(fit<threshold)
            {
                threshold=fit;
                gen=i;
            }
        }
        avg_fitness/=POPULATION_SIZE;
        population=new_pop;
        cout<<"After Selection\n";
        display_population();
        cout<<"Threshold:"<<threshold<<"\t"<<"Generation:"<<gen<<"\n";
        cout<<"Average Fitness:"<<avg_fitness<<"\n\n\n";

        if(AlmostEqualRelative(threshold,avg_fitness))
        {
            cout<<"Fitness reached\n";
            break;
        }
    }
}


int main()
{
    Genome gene;
    menu(gene);
    gene.run_GA();
}
