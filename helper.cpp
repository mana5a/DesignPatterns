#include "helper.h"

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

std::ostream& operator<<(std::ostream& out, const MutationType value){
    static std::map<MutationType, std::string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Swap);     
        INSERT_ELEMENT(Inversion);     
        INSERT_ELEMENT(Scramble);             
#undef INSERT_ELEMENT
    }   

    return out << strings[value];
}

std::ostream& operator<<(std::ostream& out, const SelectionType value){
    static std::map<SelectionType, std::string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(RouletteWheel);     
        INSERT_ELEMENT(Tournament);                  
#undef INSERT_ELEMENT
    }   

    return out << strings[value];
}

void selection_menu(Genome& gene)
{
    int ch_main;
    // std::system("clear");
    cout<<"Choose Selection\n";
    cout<<"1.Roulette Wheel\n";
    cout<<"2.Tournament\n";
    cout<<"3.Go back\n";
    cin>>ch_main;
    switch(ch_main)
    {
        case 1:
            gene.set_selection_strategy(RouletteWheel);
            gene.operations_set();
            return;
            break;
        case 2:
            gene.set_selection_strategy(Tournament);
            gene.operations_set();
            return;
            break;
        default:
            return;
    }
}

void mutation_menu(Genome& gene)
{
    int ch_main;
    // std::system("clear");
    cout<<"Choose Action\n";
    cout<<"1.Swap\n";
    cout<<"2.Inversion\n";
    cout<<"3.Scramble\n";
    cout<<"4.Go Back\n";
    cin>>ch_main;
    switch(ch_main)
    {
        case 1:
            gene.set_mutation_strategy(Swap);
            gene.operations_set();
            break;
        case 2:
            gene.set_mutation_strategy(Inversion);
            gene.operations_set();
            break;
        case 3:
            gene.set_mutation_strategy(Scramble);
            gene.operations_set();
            break;
        default:
            return;
    }
}

void menu(Genome& gene)
{
    int ch_main;
    // std::system("clear");
    do
    {
        cout<<"Choose Action\n";
        cout<<"1.Change Selection\n";
        cout<<"2.Change Mutation\n";
        cout<<"3.Go back\n";
        cin>>ch_main;
        switch(ch_main)
        {
            case 1:
                selection_menu(gene);
                break;
            case 2:
                mutation_menu(gene);
                break;
            default:
                return;
        }
    }while(ch_main!=3);
}
