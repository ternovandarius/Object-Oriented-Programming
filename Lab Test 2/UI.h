#pragma once
#include "Controller.cpp"

class UI
{
private:
    Controller c;
public:
    void run();
    UI(Controller c);
};