//
// Created by terno on 3/12/2019.
//

#include "staticrepo.h"

Repo createRepo()
{
    Repo arr;
    arr.length=0;
    return arr;
}

int addCountry(Repo *arr, Country *c)
{
    int i;
    int ok=1;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(arr->array[i]), getName(c))==0)
        {
            ok=0;
            printf("Found the same!");
            break;
        }
    }
    if (ok==1)
    {
        printf("Not the same.");
        arr->array[arr->length] = c;
        arr->length += 1;
    }
    return ok;
}

int removeCountry(Repo *arr, char name[])
{
    int i, j;
    int ok=0;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(arr->array[i]), name)==0)
        {
            for (j=i+1; j<arr->length; j++)
                arr->array[j-1]=arr->array[j];
            ok=1;
            arr->length--;
            break;
        }
    }
    return ok;
}

int updateSimple(Repo* arr, char name[], int newPop)
{
    int i;
    int ok=0;
    if (newPop<0)
        return 0;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(arr->array[i]), name)==0)
        {
            setPopulation(arr->array[i], newPop);
            ok=1;
        }
    }
    return ok;
}

void printLength(Repo arr)
{
    printf("%d", arr.length);
}

int updateMigration(Repo *arr, char coming[], char leaving[], int diff)
{
    int i, j;
    int okc=0;
    int okl=0;
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getName(arr->array[i]), coming)==0)
        {
            okc=1;
            for (j=0; j<arr->length; j++)
            {
                if (strcmp(getName(arr->array[j]), leaving)==0)
                {
                    okl=1;
                    arr->array[j]->population-=diff;
                    break;
                }
            }
            if (okl==1)
            {
                arr->array[i]->population += diff;
                return 1;
            }
        }
    }
    return 0;
}

void printAllCountries(Repo arr, char str[])
{
    int len, i;
    char newStr[100];
    char str2[500]="";
    len=arr.length;
    for (i=0; i<arr.length; i++)
    {
        printCountry(*arr.array[i], newStr);
        strcat(str2, newStr);
    }
    sprintf(str, str2);
}

void searchPartial(Repo *arr, char str[], char newStr[])
{
    int i;
    newStr="";
    char newStr2[100]="";
    char auxStr[100]="";
    for (i=0; i<arr->length; i++)
    {
        if(strstr(getName(arr->array[i]), str))
        {
            printCountry(*arr->array[i], auxStr);
            strcat(newStr2, auxStr);
        }
    }
    sprintf(newStr, newStr2);
}

void printContinentAsc(Repo *arr, char continent[], char str[])
{
    int i;
    char newStr[100]="";
    char newStr2[100]="";
    for (i=0; i<arr->length; i++)
    {
        if (strcmp(getContinent(arr->array[i]), continent)==0)
        {
            printCountry(*arr->array[i], newStr);
            strcat(newStr2, newStr);
        }
    }
    sprintf(str, newStr2);
}