//
// Created by terno on 3/12/2019.
//
#pragma once
#include "operationStack.c"

typedef struct{
    Repo* arr;
    OperationStack* undoStack;
    OperationStack* redoStack;
    Repo* arrOfArr;
}Controller;

Controller *createController();
void destroyController(Controller *con);

int addCountryController(Controller *con, char* name, char* continent, int population);
int removeCountryController(Controller *con, char* name);
void printAllCountriesController(Controller *con, char str[]);
int updateSimpleController(Controller *con, char* name, int newPop);
void searchPartialController(Controller *con, char str[], char newStr[]);
int updateMigrationController(Controller *con, char* coming, char* leaving, int diff);
void printContinentAscController(Controller *con, char continent[], char str[]);
void printContinentMinPopController(Controller *con, char continent[], int pop, char str[]);
void undoOperation(Controller *con);