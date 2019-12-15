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

bool AlmostEqualRelative(float A, float B)
{
    //Returns true if A>B
    // Calculate the difference.
    float diff = fabs(A - B);
    A = fabs(A);
    B = fabs(B);
    // Find the largest
    float largest = (B > A) ? B : A;
 
    return (diff <= largest * FLT_EPSILON);
    
}