//
// Created by terno on 3/12/2019.
//
#pragma once
#include "validation.c"

typedef struct
{
    Country* array[100];
    int length;
}Repo;

Repo createRepo();
int addCountry(Repo *arr, Country *c);
int removeCountry(Repo *arr, char name[]);
void printAllCountries(Repo arr, char str[]);
int updateSimple(Repo *arr, char name[], int newPop);
void searchPartial(Repo *arr, char str[], char newStr[]);
int updateMigration(Repo *arr, char coming[], char leaving[], int diff);
void printLength(Repo arr);
void printContinentAsc(Repo *arr, char continent[], char str[]);