//
// Created by barbosa on 19-05-2019.
//

#include "stack.h"
#include "estado.h"
#include <malloc.h>
#include <stdio.h>

/**
 * A função nestado funciona como o push de uma stack sendo que guarda o estado atual de jogo numa stack.
 * @param e, é o estado de jogo atual.
 */
void nestado (ESTADO e) {
    struct Node *es;
    es = (struct Node *) malloc(sizeof(struct Node));
    es -> est = e;
    es -> next = top;
    top = es;
}

/**
 * A função "anterior" recupera o estado anterior de modo a conseguirmos utilizar o comando "U" do nosso jogo, sendo que no fim liberta o espaço de memória não utilizado.
 */
void anterior() {
    struct Node *ant;

    ant = top;
    top = top -> next;
    free(ant);
}