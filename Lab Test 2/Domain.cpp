#include "Domain.h"
#include <cstring>

std::string Engine::toString() {
    /*std::string s;
    s="Fuel type: "+this->fuelType+", base price: "+std::to_string(this->basePrice)+"\n";
    return s;*/
}

double Engine::getPrice() {
    return this->basePrice;
}

double ElectricEngine::getPrice() {
    return this->basePrice;
}

std::string ElectricEngine::toString() {
    std::string s;
    s="Fuel type: "+this->fuelType+", base price: "+std::to_string(this->basePrice)+", autonomy: "+std::to_string(this->autonomy);
    return s;
}

std::string TurboEngine::toString() {
    std::string s;
    s="Fuel type: "+this->fuelType+", base price: "+std::to_string(this->basePrice);
    return s;
}

double TurboEngine::getPrice() {
    return this->basePrice;
}

Engine::Engine() {
    this->basePrice=3000;
    this->fuelType="";
}

Engine::Engine(std::string fuel) {
    this->fuelType=fuel;
    this->basePrice=3000;
}

ElectricEngine::ElectricEngine() {
    this->autonomy=0;
    this->basePrice=3000;
    this->fuelType="";
}

ElectricEngine::ElectricEngine(std::string fuel, int autonomy) {
    this->fuelType="";
    this->autonomy=autonomy;
    this->basePrice=3000+autonomy*0.01;
}

TurboEngine::TurboEngine() {
    this->basePrice=3000;
    this->fuelType="";
}

TurboEngine::TurboEngine(std::string fuel) {
    this->fuelType=fuel;
    if(this->fuelType=="Gasoline" or this->fuelType=="gasoline")
        this->basePrice=3000+0.01*100;
    else if (this->fuelType=="Diesel" or this->fuelType=="diesel")
        this->basePrice=3000+0.01*150;
}

Car::Car() {
    this->bodyStyle="";
    Engine* e;
    this->engine=e;
    this->price=0;
}

Car::Car(std::string bodyStyle, Engine *e) {
    this->bodyStyle=bodyStyle;
    this->engine=e;
    if (this->bodyStyle=="Sedan" or this->bodyStyle=="sedan")
        this->price=8000+this->engine->getPrice();
    else if(this->bodyStyle=="Convertible" or this->bodyStyle=="convertible")
        this->price=9000+this->engine->getPrice();
}

std::string Car::toString() {
    std::string s;
    s="Body type: "+this->bodyStyle+", price:"+std::to_string(this->price)+", engine: "+this->engine->toString();
    return s;
}

double Car::getPrice() {
    return this->price;
}