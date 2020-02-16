//
// Created by terno on 4/10/2019.
//

#include "UI.h"

void UI::run() {
    int ok=1;
    while(ok==1)
    {
        std::cout<<"1.Add a bacteria.\n2.Print all bacteria.\n3.Simulate sugar environment.\n4.Simulate antibiotic environment.\n5.Exit\n";
        int x;
        std::cin>>x;
        if (x==1)
        {
            int ok2=1;
            int y;
            std::string name;
            int number;
            bool isImmune;
            std::string aux;
            std::cout<<"\nPlease insert the name of the bacteria.\n";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout<<"\nPlease insert the number of bacteria.\n";
            std::cin>>number;
            std::cout<<"\nIs the bacteria immune to antibiotic? Y/N";
            std::cin.ignore();
            std::getline(std::cin, aux);
            if(aux=="y" or aux=="Y")
                isImmune=true;
            else if (aux=="n" or aux=="N")
                isImmune=false;
            else
            {
                ok2=0;
                std::cout<<"Invalid command!\n";
            }
            if (ok2==1)
            {
                y=c.addBacteria(name, number, isImmune);
                if (y==1)
                    std::cout<<"A new Bacteria was added!\n";
            }

        }
        else if (x==2)
        {
            DynamicVector<Bacteria> d=c.get_allController();
            for(int i=0; i<d.get_size(); i++)
                std::cout<<d[i].toString();
        }
        else if (x==3)
        {
            c.simulate_sugar();
        }
        else if (x==4)
        {
            c.simulate_antibiotic();
        }
        else if (x==5)
            ok=0;
    }
}