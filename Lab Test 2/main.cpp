#include <iostream>
#include "UI.cpp"

int main() {
    Controller c;
    c.addCar("sedan", "electric", "diesel", 1000);
    c.addCar("convertible", "turbo", "gasoline", 10);
    c.addCar("convertible", "electric", "gasoline", 100000);
    c.addCar("sedan", "turbo", "diesel", 200);
    UI ui(c);
    ui.run();
    return 0;
}