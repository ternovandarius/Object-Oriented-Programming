#include <stdio.h>
#include "ui.c"

void tests() {
    char name[]="Australia";
    char continent[]="Australia";
    int population=10;
    char name2[]="Romania";
    char continent2[]="Europe";
    int pop2=100000;
    char name3[]="Hungary";
    char continent3[]="Europe";
    int pop3=200000;
    /*Country* c;
    c=createCountry(name, continent, population);
    Repo* r=createRepo(10);
    addCountry(r, c);
    Country* d;
    d=createCountry(name2, continent2, pop2);
    Country* e;
    e=createCountry(name3, continent3, pop3);
    addCountry(r, d);
    addCountry(r, e);
    char str[500]="";
    printAllCountries(r, str);
    printf("%s", str);*/
    Controller* con;
    con=createController();
    addCountryController(con, "a", "b", 12);
    addCountryController(con, name2, continent2, pop2);
    char str1[500]="man";
    char str2[500]="";
    searchPartialController(con, str1, str2);
    printf("%s", str2);
    /*x=removeCountryController(con, name);
    x=addCountryController(con, name2, continent2, pop2);
    x=addCountryController(con, name3, continent3, pop3);
    int newPop=10;
    updateSimpleController(con, name3, newPop);
    updateMigrationController(con, name3, name2, newPop);

    char newStr[100]="";*/
    /*char str[100]="";
    printAllCountriesController(con, str);
    printf("%s", str);*/
    /*strcpy(str, "man");
    searchPartialController(con, str, newStr);
    printf("%s", newStr);*/
}

int main()
{
    //tests();
    UI* ui;
    ui=createUI();
    runUI(ui);
    destroyUI(ui);
    return 0;
}