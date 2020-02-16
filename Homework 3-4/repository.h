//
// Created by terno on 3/11/2019.
//
#pragma once
#include "validation.c"

typedef struct{
    Country* array;
    int length;
    int capacity;
}Repo;

Repo* createRepo(int capacity);
void destroyRepo(Repo* arr);
void resize(Repo* arr);
int addCountry(Repo *arr, Country *c);
int removeCountry(Repo *arr, char name[], char continent[]);
int updateSimple(Repo *arr, char name[], char continent[], int newPop);
void searchPartial(Repo *arr, char str[], char newStr[]);
int updateMigration(Repo *arr, char coming[], char leaving[], int diff);
void printLength(Repo arr);
void printAllCountries(Repo* arr, char str[]);
void printContinentAsc(Repo *arr, char continent[], char str[]);
void printContinentMinPop(Repo *arr, char continent[], int pop, char str[]);
//void delete(Repo* arr, Country c);
