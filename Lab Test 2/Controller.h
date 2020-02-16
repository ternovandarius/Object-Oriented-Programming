#pragma once
#include "Domain.cpp"
#include <vector>

class Controller{
private:
    std::vector<Car> r;
    Engine* createEngine(std::string engineType, std::string fuelType, int autonomy);
public:
    void addCar(std::string bodyStyle, std::string engineType, std::string fuelType, int autonomy);
    void showCars();
    void saveToFile(std::string file, double price);
};