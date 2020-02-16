#pragma once
#include "Controller.cpp"

class UI{
private:
    Controller c;
public:
    UI(Controller c): c{c}{};
    void run();
};