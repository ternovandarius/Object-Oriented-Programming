//
// Created by terno on 3/11/2019.
//

#include "repository.h"
#include <stdlib.h>
#include <assert.h>

Repo* createRepo(int capacity)
{
    Repo* arr = (Repo*)malloc(sizeof(Repo));
    if (arr==NULL)
    {
        return NULL;
    }

    arr->capacity = capacity;
    arr->length = 0;

    arr->array = (Country*)malloc(capacity*sizeof(Country));
    if (arr->array==NULL)
        return NULL;

    return arr;
}

void destroyRepo(Repo* arr)
{
    if (arr==NULL)
        return;

    for (int i=0; i<arr->length; i++)
        destroyCountry(&arr->array[i]);

    free(arr->array);
    arr->array=NULL;

    free(arr);
}

void resize(Repo* arr)
{
    if (arr==NULL)
        return;

    arr->capacity*=2;
    Country *aux=(Country*)realloc(arr->array, arr->capacity*sizeof(Country));
    if (aux==NULL)
        return;
    arr->array=aux;
}

void printAllCountries(Repo* arr, char str[])
{
    int len, i;
    len=arr->length;
    char newStr[60]="";
    char str2[500]="";
    for (i=0; i<arr->length; i++)
    {
        printCountry(&arr->array[i], newStr);
        strcat(str2, newStr);
    }
    sprintf(str, str2);
}

int addCountry(Repo *arr, Country *c)
{
    if (arr==NULL)
        return -1;
    if (arr->array==NULL)
        return -1;

    int ok=0;

    for(int i=0; i<arr->length; i++)
    {
        if (strcmp(getName(&arr->array[i]), getName(c))==0)
            ok=-1;
    }

    if (ok==0) {
        if (arr->length == arr->capacity)
            resize(arr);

        arr->array[arr->length] = *c;
        arr->length++;
    }
    return ok;
}

int removeCountry(Repo *arr, char name[], char continent[])
{
    if (arr==NULL)
        return -1;
    if (arr->array==NULL)
        return -1;

    int pop=0;
    int i, j;
    int ok=0;
    for (i=0; i<arr->length; i++)
    {
        if(strcmp(getName(&arr->array[i]), name)==0)
        {
            strcpy(continent, getContinent(&arr->array[i]));
            pop=getPopulation(&arr->array[i]);
            for (j=i+1; j<arr->length; j++)
                arr->array[j-1]=arr->array[j];
            ok=1;
            destroyCountry(&arr->array[arr->length]);
            arr->length--;
            break;
        }
    }
    return pop;
}

int updateSimple(Repo *arr, char name[], char continent[], int newPop)
{
    int i;
    int oldPop=-1;
    int ok=0;
    if (newPop<0)
        return -1;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(&arr->array[i]), name)==0)
        {
            strcpy(continent,getContinent(&arr->array[i]));
            oldPop=getPopulation(&arr->array[i]);
            setPopulation(&arr->array[i], newPop);
            ok=1;
        }
    }
    return oldPop;
}

void searchPartial(Repo *arr, char str[], char newStr[])
{
    int i=0;
    char newStr2[100]="";
    char auxStr[100]="";
    for (i=0; i<arr->length; i++)
    {
        if(strstr(getName(&arr->array[i]), str))
        {
            printCountry(&arr->array[i], auxStr);
            strcat(newStr2, auxStr);
        }
    }
    sprintf(newStr, newStr2);
}

int updateMigration(Repo *arr, char coming[], char leaving[], int diff)
{
    int i, j;
    int okc=0;
    int okl=0;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(&arr->array[i]), coming)==0)
        {
            okc=1;
            for (j=0; j<arr->length; j++)
            {
                if (strcmp(getName(&arr->array[j]), leaving)==0)
                {
                    okl=1;
                    arr->array[j].population-=diff;
                    break;
                }
            }
            if (okl==1)
            {
                arr->array[i].population += diff;
                return 1;
            }
        }
    }
    return 0;
}

void printLength(Repo arr)
{
    printf("%d", arr.length);
}

void printContinentAsc(Repo *arr, char continent[], char str[]) {
    int i;
    char sort_arr[15][100];
    int j = 0;
    for (i = 0; i < 15; i++)
        strcpy(sort_arr[i], "");
    char newStr[100] = "";
    char newStr2[100] = "";
    for (i = 0; i < arr->length; i++) {
        if (strcmp(getContinent(&arr->array[i]), continent) == 0) {
            printCountry(&arr->array[i], newStr);
            strcpy(sort_arr[j++], newStr);
        }
    }
    char auxStr[500]="";
    for (i = 0; i < j-1; i++)
    {
        for (int k=i+1; k<j; k++)
            if (strcmp(sort_arr[i], sort_arr[j])>0)
            {
                strcpy(auxStr, sort_arr[i]);
                strcpy(sort_arr[i], sort_arr[j]);
                strcpy(sort_arr[j], auxStr);
            }
    }
    for (i=0; i<=j; i++)
        strcat(newStr2, sort_arr[i]);
    sprintf(str, newStr2);
}

void printContinentMinPop(Repo *arr, char continent[], int pop, char str[])
{
    int i;
    char newStr[500]="";
    char newStr2[500]="";
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getContinent(&arr->array[i]), continent)==0 && getPopulation(&arr->array[i])>=pop)
        {
            printCountry(&arr->array[i], newStr);
            strcat(newStr2, newStr);
        }
    }
    sprintf(str, newStr2);
}