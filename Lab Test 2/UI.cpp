#include "UI.h"

UI::UI(Controller c) {
    this->c=c;
}

void UI::run() {
    bool ok=true;
    while(ok==true)
    {
        std::cout<<"1.Add car.\n2.Display all cars.\n3.Save to file all cars cheaper than a given price.\n4.Exit.\n";
        int x;
        std::cin>>x;
        if(x==4)
            ok=false;
        else if(x==1)
        {
            std::cout<<"Please insert the body type of the car. <Sedan> or <Convertible>\n";
            std::string bodyType;
            std::cin>>bodyType;
            std::cout<<"Please insert the engine type. <Electric> or <Turbo>\n";
            std::string engineType;
            std::cin>>engineType;
            std::cout<<"Please insert the fuel type. <Gasoline> or <Diesel>\n";
            std::string fuelType;
            std::cin>>fuelType;
            int autonomy=0;
            if(engineType=="Electric" or engineType=="electric")
            {
                std::cout<<"Please insert the autonomy of the engine.\n";
                std::cin>>autonomy;
            }
            c.addCar(bodyType, engineType, fuelType, autonomy);
        }
        else if(x==2)
        {
            c.showCars();
        }
        else if(x==3)
        {
            std::string file;
            std::cout<<"Please enter the file name.\n";
            std::cin>>file;
            std::cout<<"Please enter the price.\n";
            int price;
            std::cin>>price;
            c.saveToFile(file, price);
        }
        else
        {
            std::cout<<"Invalid command!\n";
        }
    }
}