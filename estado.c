//
// Created by barbosa on 19-05-2019.
//

#include <stdio.h>
#include "estado.h"
#include "Jogada.h"

/**
 * A função "printa" imprime o estado de jogo atual.
 * @param e, é o estado atual do jogo.
 */
void printa(ESTADO e)
{
    char c = ' ';

    if(e.modo == 1)printf("A ");
    else printf("M ");

    if(e.peca == VALOR_X)printf("X\n");
    else printf("O\n");

    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ",i);
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}

/**
 * A função "printaS" imprime o estado de jogo atual com as posições em que o jogador pode efetuar as suas jogadas.
 * @param e, é o estado atual do jogo.
 */
void printaS(ESTADO e)
{
    char c = ' ';

    if(e.modo == 1)printf("A ");
    else printf("M ");

    if(e.peca == VALOR_X)printf("X\n");
    else printf("O\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    if (verificajog(i,j,e) == 1) c = '.';
                    else c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}