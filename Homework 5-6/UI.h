//
// Created by terno on 3/25/2019.
//
#pragma once
#include "Controller.cpp"

class UI{
private:
    Controller ctrl;
public:
    UI(const Controller& c) : ctrl(c) {}
    void run();
};