#pragma once
#include "DynamicArray.cpp"

class Repository{
private:
    DynamicVector<Bacteria> &d;
public:
    Repository (DynamicVector<Bacteria> &d) : d{d}{};
    int addBacteria(Bacteria b);
    DynamicVector<Bacteria> get_all();
    int pass_size();
    void simulate_sugar();
    void simulate_antibiotic();
};

void test_Repo();