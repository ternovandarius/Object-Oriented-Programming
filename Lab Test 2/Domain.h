#pragma once

class Engine{
protected:
    std::string fuelType;
    double basePrice=3000;
public:
    double getPrice();
    virtual std::string toString();
    Engine();
    Engine(std::string fuel);
};

class ElectricEngine: public Engine{
private:
    int autonomy;
public:
    double getPrice();
    std::string toString() override;
    ElectricEngine();
    ElectricEngine(std::string fuel, int autonomy);
};

class TurboEngine: public Engine{
public:
    double getPrice();
    std::string toString() override;
    TurboEngine();
    TurboEngine(std::string fuel);
};

class Car{
private:
    std::string bodyStyle;
    Engine *engine;
    double price;
public:
    Car();
    Car(std::string bodyStyle, Engine* e);
    std::string toString();
    double getPrice();
    //double computePrice();
};