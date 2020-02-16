#include <fstream>
#include "Controller.h"

Engine* Controller::createEngine(std::string engineType, std::string fuelType, int autonomy) {
    Engine* e;
    if (engineType=="Electric" or engineType=="electric")
    {
        e=new ElectricEngine(fuelType, autonomy);
    }
    else{
        e=new TurboEngine(fuelType);
    }
    return e;
}

void Controller::addCar(std::string bodyStyle, std::string engineType, std::string fuelType, int autonomy) {
    Engine* e=createEngine(engineType, fuelType, autonomy);
    Car c(bodyStyle, e);
    r.push_back(c);
    std::cout<<"The price of the newly added car is: "+std::to_string(this->r[this->r.size()-1].getPrice())+"\n";
}

void Controller::showCars() {
    int i;
    for(i=0; i<this->r.size(); i++)
    {
        std::string s;
        s=this->r[i].toString();
        std::cout<<s<<std::endl;
    }
    std::cout<<std::endl;
}

void Controller::saveToFile(std::string file, double price) {
    std::vector<Car> newr;
    std::ofstream o;
    o.open(file);
    for(int i=0; i<this->r.size(); i++)
    {
        if(this->r[i].getPrice()<price)
            newr.push_back(this->r[i]);
    }
    for(int i=0; i<newr.size()-1; i++)
    {
        for(int j=i+1; j<newr.size(); j++)
        {
            if(newr[i].getPrice()>newr[j].getPrice())
            {
                Car aux;
                aux=newr[i];
                newr[i]=newr[j];
                newr[j]=aux;
            }
        }
    }
    for(int i=0; i<newr.size(); i++)
    {
        o<<newr[i].toString()<<std::endl;
    }
    o.close();
}