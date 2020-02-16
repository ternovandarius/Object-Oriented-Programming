//
// Created by terno on 3/19/2019.
//

#include "operationStack.h"

Operation* createOperation(Country* c, char* opType)
{
    Operation *o = (Operation*)malloc(sizeof(Operation));
    o->c=createCountry(getName(c), getContinent(c), getPopulation(c));

    if (opType!=NULL)
    {
        o->opType=(char*)malloc(sizeof(char) * strlen(opType) + 1);
        strcpy(o->opType, opType);
    }
    else
        o->opType=NULL;
    return o;
}
void destroyOperation(Operation* o) {
    if (o == NULL)
        return;
    else {
        destroyCountry(o->c);
        free(o->opType);
        free(o);
    }
}

char* getOperationType(Operation* o)
{
    return o->opType;
}
Country* getCountry(Operation* o)
{
    return o->c;
}

//---------------------------------------------------------------------

OperationStack* createOperationStack()
{
    OperationStack* s = (OperationStack*)malloc(sizeof(OperationStack));
    s->length = 0;

    return s;
}

void destroyOperationStack(OperationStack* s)
{
    if (s==NULL)
        return;

    for (int i=0; i<s->length; i++)
        destroyOperation(s->o[i]);

    free(s);
}

void push(OperationStack* s, Operation* o)
{
    s->o[s->length]=o;
    s->length++;
}

Operation* pop(OperationStack* s)
{
    Operation* o;
    int i=s->length;
    i--;
    o=s->o[i];
    s->length--;
    return o;
}

int getLength(OperationStack* s)
{
    return s->length;
}