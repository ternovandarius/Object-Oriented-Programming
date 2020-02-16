//
// Created by terno on 3/12/2019.
//

#include "controller.h"

Controller* createController()
{
    Controller* con=(Controller*)malloc(sizeof(Controller));
    con->arr=createRepo(10);
    con->undoStack=createOperationStack();
    con->redoStack=createOperationStack();
    con->arrOfArr=createRepo(100);
    return con;
}

/*void copy(Controller *con)
{
    con->arrOfArr->array[con->arrOfArr->length++]=*con->arr->array;
}*/

void destroyController(Controller *con)
{
    destroyRepo(con->arr);
    destroyOperationStack(con->undoStack);
    destroyOperationStack(con->redoStack);
    free(con);
}

int addCountryController(Controller *con, char *name, char *continent, int population)
{
    Country* c;
    c=createCountry(name, continent, population);
    int x=validate(c);
    int y;
    if (x==0) {
        y=addCountry(con->arr, c);
        if (y!=-1) {
            char *opType = "add";
            Operation *op = createOperation(c, opType);
            push(con->undoStack, op);
            return y;
        }
    }
    //destroyCountry(c);
    return x;
}

int removeCountryController(Controller *con, char* name)
{
    int x;
    char continent[25];
    char newName[50];
    int pop=0;
    pop=removeCountry(con->arr, name, continent);
    if (pop!=-1)
    {
        strcpy(newName, name);
        Country *c=createCountry(newName, continent, pop);
        char *opType="remove";
        Operation *op=createOperation(c, opType);
        push(con->undoStack, op);
    }
}

void printAllCountriesController(Controller *con, char str[])
{
    printAllCountries(con->arr, str);
}

int updateSimpleController(Controller *con, char* name, int newPop)
{
    char continent[25]="";
    int oldPop= updateSimple(con->arr, name, continent, newPop);
    if (oldPop!=-1)
    {
        Country *c=createCountry(name, continent, oldPop);
        char *opType="update";
        Operation *o=createOperation(c, opType);
        push(con->undoStack, o);
        return 0;
    }
    else
        return -1;
}

void searchPartialController(Controller *con, char str[], char newStr[])
{
    searchPartial(con->arr, str, newStr);
}

int updateMigrationController(Controller *con, char* coming, char* leaving, int diff)
{
/*    char comingContinent[25]="";
    char leavingContinent[25]="";*/
    return updateMigration(con->arr, coming, leaving, diff);
}

void printContinentAscController(Controller *con, char continent[], char str[])
{
    printContinentAsc(con->arr, continent, str);
}

void printContinentMinPopController(Controller *con, char continent[], int pop, char str[])
{
    printContinentMinPop(con->arr, continent, pop, str);
}

void undoOperation(Controller *con)
{
    if (getLength(con->undoStack)!=0) {
        Operation *o = pop(con->undoStack);
        char opType[50]="";
        strcpy(opType, getOperationType(o));
        if (strcmp(opType, "add") == 0) {
            Country *c = getCountry(o);
            char name[50] = "";
            strcpy(name, getName(c));
            char continent[25] = "";
            strcpy(continent, getContinent(c));
            int pop;
            pop=removeCountry(con->arr, name, continent);
            char newOpType[25] = "remove";
            Operation *newO = createOperation(c, newOpType);
            push(con->redoStack, newO);
        } else if (strcmp(opType, "remove") == 0) {
            Country *c = getCountry(o);
            addCountry(con->arr, c);
            char newOpType[25] = "add";
            Operation *newO = createOperation(c, newOpType);
            push(con->redoStack, newO);
        } else if (strcmp(opType, "update") == 0) {
            Country *c = getCountry(o);
            char name[50]="";
            strcpy(name, getName(c));
            int newPop=getPopulation(c);
            char continent[25]="";
            strcpy(continent, getContinent(c));
            int oldPop=updateSimple(con->arr, name, continent, newPop);
            Country *c2 =createCountry(name, continent, oldPop);
            char opType2[25]="update";
            Operation *o2=createOperation(c2, opType2);
            push(con->redoStack, o2);
        }
        //destroyOperation(o);
    }
    else
        printf("No more actions to undo!\n");
}

void redoOperation(Controller *con)
{
    if (getLength(con->redoStack)!=0) {
        Operation *o = (Operation*)malloc(sizeof(Operation));
        o=pop(con->redoStack);
        char opType[50] = "";
        strcpy(opType, getOperationType(o));
        if (strcmp(opType, "add") == 0) {
            Country *c = getCountry(o);
            char name[50] = "";
            strcpy(name, getName(c));
            char continent[25] = "";
            strcpy(continent, getContinent(c));
            int pop;
            pop=removeCountry(con->arr, name, continent);
            char newOpType[25] = "";
            strcpy(newOpType, "remove");
            Operation *newO = createOperation(c, newOpType);
            push(con->undoStack, newO);
        } else if (strcmp(opType, "remove") == 0) {
            Country *c = getCountry(o);
            addCountry(con->arr, c);
            char newOpType[25] = "";
            strcpy(newOpType, "add");
            Operation *newO = createOperation(c, newOpType);
            push(con->undoStack, newO);
        } else if (strcmp(opType, "update") == 0) {
            Country *c = getCountry(o);
            char name[50]="";
            strcpy(name, getName(c));
            int newPop=getPopulation(c);
            char continent[25]="";
            strcpy(continent, getContinent(c));
            int oldPop=updateSimple(con->arr, name, continent, newPop);
            Country *c2 =createCountry(name, continent, oldPop);
            char opType2[25]="update";
            Operation *o2=createOperation(c2, opType2);
            push(con->undoStack, o2);
        }
        //destroyOperation(o);
    }
    else
        printf("No more actions to redo!\n");
}