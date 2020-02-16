//
// Created by terno on 3/11/2019.
//
#include "model.h"
#include <string.h>
#include <malloc.h>

Country* createCountry(char* name, char* continent, int population)
{
    Country* c = (Country*)malloc(sizeof(Country));
    c->name=(char*)malloc(sizeof(char) * strlen(name)+1);
    strcpy(c->name, name);
    c->continent=(char*)malloc(sizeof(char) * strlen(name)+1);
    strcpy(c->continent, continent);
    c->population=population;

    return c;
}

void destroyCountry(Country *c)
{
    free(c->name);
    free(c->continent);
    free(c);
}

char* getName(Country *c)
{
    return c->name;
}
char* getContinent(Country *c)
{
    return c->continent;
}
int getPopulation(Country *c)
{
    return c->population;
}

void setPopulation(Country* c, int newPop)
{
    c->population=newPop;
}

void printCountry(Country* c, char str[])
{
    sprintf(str, "Name: %s, Continent: %s, Population:%d\n", c->name, c->continent, c->population);
}