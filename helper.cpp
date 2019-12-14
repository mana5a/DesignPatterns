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