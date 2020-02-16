//
// Created by terno on 3/12/2019.
//
#pragma once
#include "controller.c"

typedef struct{
    Controller* con;
}UI;

UI* createUI();
void destroyUI(UI *ui);

void runUI(UI *ui);