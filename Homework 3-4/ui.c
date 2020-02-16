//
// Created by terno on 3/12/2019.
//

#include "ui.h"

UI* createUI()
{
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->con=createController();
    return ui;
}

void destroyUI(UI* ui)
{
    destroyController(ui->con);
    free(ui);
}

void runUI(UI *ui)
{
    int ok=0;
    while(ok==0)
    {
        printf("1.Add a country.\n2.Remove a country.\n3.Update a country's population.\n4.Search for a country.\n5.Print all countries.\n6.Print all countries from a certain continent in ascending order.\n7.Print all countries from a certain continent with a minimum population.\n8.Undo.\n9.Redo.\n10.Exit.");
        int x;
        scanf("%d", &x);
        if (x==1)
        {
            printf("Please input the name of the country.");
            char name[50];
            scanf("%s", name);
            printf("Please input the name of the continent.");
            char continent[20];
            scanf("%s", continent);
            printf("Please input the population.");
            int population;
            scanf("%d", &population);
            int ok2;
            ok2=addCountryController(ui->con, name, continent, population);//name, continent, population);
            if (ok2!=0)
                printf("Invalid operation! Either this country already exists, or your input was invalid.");
        }
        else if(x==2)
        {
            printf("Please input the name of the country you want to remove.");
            char name[50];
            scanf("%s", name);
            int ok2;
            ok2=removeCountryController(ui->con, name);
            if (ok2==0)
                printf("Invalid operation! This country doesn't exist in the database, so it cannot be removed.");
        }
        else if(x==3)
        {
            printf("Please input the name of the country whose population you want to update.");
            char name[50];
            scanf("%s", name);
            printf("Is migration the cause of the shift in population? 1=yes, 0=no");
            int y;
            scanf("%d", &y);
            if (y==0)
            {
                printf("Please enter the new population.");
                int pop;
                scanf("%d", &pop);
                int ok2;
                ok2=updateSimpleController(ui->con, name, pop);
                if (ok2==0)
                    printf("Invalid country name or population!");
            }
            else
            {
                printf("Please enter the other country affected by migration.");
                char name2[50];
                scanf("%s", name2);
                printf("Please enter the difference in population. (Country1+=difference");
                int diff;
                scanf("%d", &diff);
                int ok2;
                ok2=updateMigrationController(ui->con, name, name2, diff);
                if (ok2==0)
                    printf("Invalid input! One of the countries entered do not exist in the database!");
            }
        }
        else if(x==4)
        {
            printf("Please input the string you want to search for.");
            char str[50]="";
            scanf("%s", str);
            char str2[1000]="";
            searchPartialController(ui->con, str, str2);
            printf("%s", str2);
        }
        else if(x==5)
        {
            char str[500]="";
            printAllCountriesController(ui->con, str);
            printf("%s", str);
        }
        else if(x==6)
        {
            printf("Please input the continent.");
            char continent[25]="";
            scanf("%s", continent);
            char str[500]="";
            printContinentAscController(ui->con, continent, str);
            printf("%s", str);
        }
        else if(x==7)
        {
            printf("Please input the continent.");
            char continent[25]="";
            scanf("%s", continent);
            printf("Please input the minimum population.");
            int pop;
            scanf("%d", &pop);
            char str[500]="";
            printContinentMinPopController(ui->con, continent, pop, str);
            printf("%s", str);
        }
        else if(x==8)
        {
            undoOperation(ui->con);
        }
        else if (x==9)
        {
            redoOperation(ui->con);
        }
        else if(x==10){
            ok=1;
        }
        else
            printf("Invalid command!\n");
    }
}