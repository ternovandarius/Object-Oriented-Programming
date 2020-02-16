//
// Created by terno on 3/11/2019.
//
#pragma once

typedef struct
{
    char* name;
    char* continent;
    int population;
}Country;

Country* createCountry(char* name, char* continent, int population);
void destroyCountry(Country* c);

char* getName(Country *c);
char* getContinent(Country *c);
int getPopulation(Country *c);
void printCountry(Country* c, char str[]);
void setPopulation(Country *c, int newPop);
