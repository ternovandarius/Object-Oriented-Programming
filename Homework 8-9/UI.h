//
// Created by terno on 3/25/2019.
//
#pragma once
#include "Controller.cpp"

class UI{
private:
    Controller ctrl;
    std::string file_name;
    int mode;
public:
    UI(const Controller& c, std::string file_name, int mode) : ctrl(c), file_name(file_name), mode(mode) {}
    void run();
};