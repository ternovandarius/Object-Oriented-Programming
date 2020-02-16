//
// Created by terno on 3/19/2019.
//
#pragma once

#include "repository.c"
#include <string.h>

typedef struct
{
    Country* c;
    char* opType;
}Operation;

Operation* createOperation(Country* c, char* opType);
void destroyOperation(Operation* o);
char* getOperationType(Operation* o);
Country* getCountry(Operation* o);

typedef struct
{
    Operation* o[100];
    int length;
}OperationStack;

OperationStack* createOperationStack();
void destroyOperationStack(OperationStack* s);
void push(OperationStack* s, Operation* o);
Operation* pop(OperationStack* s);
int getLength(OperationStack* s);
