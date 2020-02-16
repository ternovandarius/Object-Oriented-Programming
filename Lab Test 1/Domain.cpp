#include "Domain.h"

Bacteria::Bacteria() {
    this->name="";
    this->number=0;
    this->isImmune= false;
}

std::string Bacteria::toString() {
    std::string t;
    std::string aux;
    if (this->isImmune==true)
        aux="true";
    else
        aux="false";
    t="Name: "+this->name+", Population: "+std::to_string(this->number)+", Immune: "+aux+"\n";
    return t;
}

std::string Bacteria::get_title() {
    return this->name;
}

int Bacteria::get_pop() {
    return this->number;
}

void Bacteria::set_pop(int newPop) {
    this->number=newPop;
}

bool Bacteria::get_immunity() {
    return this->isImmune;
}