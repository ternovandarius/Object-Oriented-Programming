//
// Created by terno on 4/10/2019.
//

#include "Controller.h"

int Controller::addBacteria(std::string name, int number, bool isImmune) {
    /*
     * This function first creates a Bacteria object with the input parameters.
     * The function then calls the addBacteria function from the Repository class, and returns 1 if a new population was added.
     * Input: name, number, isImmune
     * Preconditions: r= Repository, name=std::string, number=int, isImmune=bool
     * Output:1 if new population was added, 0 otherwise
     * Postconditions:d' = d + b OR d' = d, d[i] modified (where d[i].get_title=b.get_title and d=the DynamicVector<Bacteria>
     * held in the Repository object)
     */
    Bacteria b(name, number, isImmune);
    return this->r.addBacteria(b);
}

DynamicVector<Bacteria> Controller::get_allController() {
    return r.get_all();
}

void Controller::simulate_sugar() {
    this->r.simulate_sugar();
}

void Controller::simulate_antibiotic() {
    this->r.simulate_antibiotic();
}

void test_Controller()
{
    DynamicVector<Bacteria> d;
    Repository r(d);
    Controller c(r);
    assert(d.get_size()==0);
    c.addBacteria("a", 100, true);
    assert(d.get_size()==1);
    c.addBacteria("a", 2, false);
    assert(d.get_size()==1);
    assert(d[0].get_pop()==102);
    c.addBacteria("b", 1000, false);
    assert(d.get_size()==2);
    c.simulate_antibiotic();
    assert(d[0].get_pop()==102);
    assert(d[1].get_pop()==500);
    c.simulate_sugar();
    assert(d[0].get_pop()==204);
    assert(d[1].get_pop()==1000);
}