//
// Created by barbosa on 19-05-2019.
//

#ifndef PROJETOF_ESTADO_H
#define PROJETOF_ESTADO_H

/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/
// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;

void printa(ESTADO e);
void printaS(ESTADO e);

#endif //PROJETOF_ESTADO_H