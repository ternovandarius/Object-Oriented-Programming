//
// Created by terno on 3/11/2019.
//

#include "validation.h"


int validate(Country *c)
{
    if (strcmp(getName(c),"")==0)
        return -1;
    if (strcmp(getContinent(c),"")==0)
        return -1;
    if (getPopulation(c)<0)
        return -1;
    return 0;
}