#pragma once
#include "Repository.cpp"

class Controller {
private:
    Repository &r;
public:
    Controller(Repository &r): r{r}{};
    int addBacteria(std::string name, int number, bool isImmune);
    DynamicVector<Bacteria> get_allController();
    void simulate_sugar();
    void simulate_antibiotic();
};

void test_Controller();