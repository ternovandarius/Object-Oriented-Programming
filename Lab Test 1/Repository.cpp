//
// Created by terno on 4/10/2019.
//

#include "Repository.h"
#include <assert.h>

int Repository::addBacteria(Bacteria b) {
    /*
     * This function adds a new population of Bacteria by calling the "add" function in the DynamicVector.
     * If the population already exists, it will simply add the current number of bacteria to the old bacteria in the repo.
     * If a new population was added, it will return 1.
     * Input: b
     * Preconditions: d = DynamicVector<Bacteria>; b = Bacteria
     * Output: 1 if new population was added, 0 otherwise
     * Postconditions:d' = d + b OR d' = d, d[i] modified (where d[i].get_title=b.get_title)
     */
    return this->d.add(b);
}

DynamicVector<Bacteria> Repository::get_all() {
    return this->d;
}

int Repository::pass_size() {
    return d.get_size();
}

void Repository::simulate_sugar() {
    for (int i=0; i<d.get_size(); i++)
    {
        int newPop=d[i].get_pop()*2;
        d[i].set_pop(newPop);
    }
}

void Repository::simulate_antibiotic() {
    for (int i=0; i<d.get_size(); i++)
    {
        if (d[i].get_immunity()==false)
        {
            int newPop=d[i].get_pop()/2;
            d[i].set_pop(newPop);
        }
    }
}

void test_Repo()
{
    DynamicVector<Bacteria> d;
    Repository r(d);
    assert(r.pass_size()==0);
    Bacteria b1("E_coli", 100, false);
    r.addBacteria(b1);
    assert(r.pass_size()==1);
    r.addBacteria(b1);
    assert(r.pass_size()==1);
    assert(d[0].get_pop()==200);
    Bacteria b2("Strep", 2000, true);
    r.addBacteria(b2);
    assert(r.pass_size()==2);
    r.simulate_antibiotic();
    assert(d[0].get_pop()==100);
    assert(d[1].get_pop()==2000);
    r.simulate_sugar();
    assert(d[0].get_pop()==200);
    assert(d[1].get_pop()==4000);
}