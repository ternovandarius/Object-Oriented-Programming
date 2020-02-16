#pragma once

class Bacteria{
private:
    std::string name;
    int number;
    bool isImmune;
public:
    Bacteria(std::string name, int number, bool isImmune) {this->name=name; this->number=number; this->isImmune=isImmune;};
    Bacteria();
    std::string toString();
    std::string get_title();
    int get_pop();
    void set_pop(int newPop);
    bool get_immunity();
};