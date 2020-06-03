//
// Created by barbosa on 19-05-2019.
//

#ifndef REVERSIGRUPO8_STACK_H
#define REVERSIGRUPO8_STACK_H

#include "estado.h"

//Declarar o nodo da lista-ligada
struct Node {
    ESTADO est;
    struct Node* next;
};
struct Node* top;

void nestado (ESTADO e);
void anterior();

#endif //REVERSIGRUPO8_STACK_H
