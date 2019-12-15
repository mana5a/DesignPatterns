#include"genetic.h"

int random_num(int start, int end);

bool compare(const pair<vector <int>, int>&i, const pair<vector <int>, int>&j);

bool AlmostEqualRelative(float A, float B);

std::ostream& operator<<(std::ostream& out, const MutationType value);

std::ostream& operator<<(std::ostream& out, const SelectionType value);

void menu(Genome&);

void selection_menu(Genome&);

void mutation_menu(Genome&);
