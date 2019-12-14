#include "genetic.h"

class Strategy_Mutation
{
  public:
    Strategy_Mutation();
  private:
    virtual chromosome justify(chromosome chr) = 0;
};

class Swap_Mutation: public Strategy_Mutation
{
  public:
    Swap_Mutation();
  private:
     chromosome justify(chromosome chr);
};

class Inversion_Mutation: public Strategy_Mutation
{
  public:
    Inversion_Mutation();
  private:
     chromosome justify(chromosome chr);
};

class Scramble_Mutation: public Strategy_Mutation
{
  public:
    Scramble_Mutation();
  private:
     chromosome justify(chromosome chr);
};