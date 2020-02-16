#include <iostream>
#include "UI.cpp"

void tests()
{
    test_Repo();
    test_Controller();
}

int main() {
    tests();
    DynamicVector<Bacteria> v;
    Repository r(v);
    Controller c(r);
    UI ui(c);
    ui.run();
    return 0;
}