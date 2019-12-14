#include "genetic.h"

chromosome Inversion_Mutation::mutation(chromosome chr)
{
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    reverse(chr.begin()+l,chr.begin()+r);
    return chr;
}

chromosome Scramble_Mutation::mutation(chromosome chr)
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

chromosome Swap_Mutation::mutation(chromosome chr)
{
    int r=random_num(1,CHR_SIZE-1);
    int l=random_num(1,CHR_SIZE-1);
    int temp=chr[l];
    chr[l]=chr[r];
    chr[r]=temp;
    return chr;
}

