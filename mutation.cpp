#include<bits/stdc++.h>

typedef vector<int> chromosome; //remove later

int random_num(int start, int end) 
{ 
    int range = (end-start); 
    int random_int = start+(rand()%range); 
    return random_int; 
} 

chromosome m_inversion(chromosome chr)
{
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    reverse(chr.begin()+l,chr.begin()+r);
    return chr;
}

chromosome m_scramble(chromosome chr)
{
    for(int i=0;i<5;++i)
    {
        int r=random_num(1,CHR_SIZE-1);
        int l=random_num(1,CHR_SIZE-1);
        int temp=chr[l];
        chr[l]=chr[r];
        chr[r]=temp;
    }
    return chr;
}

chromosome m_swap(chromosome chr)
{
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    int temp=chr[l];
    chr[l]=chr[r];
    chr[r]=temp;
    return chr;
}