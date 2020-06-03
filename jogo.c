//
// Created by barbosa on 19-05-2019.
//

#include "jogo.h"
#include "estado.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * A funçaõ "novojogo" cria um jogo novo.
 * @param e, é o estado de jogo atual.
 * @param v, é um array.
 * @return estado de jogo alterado.
 */
ESTADO novojogo (ESTADO e, char v[50])
{
    // estado inicial do tabuleiro. Inicio do jogo!
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    if(toupper(v[2]) == 'A')
    {
        e.modo = 1;
        if (toupper (v[4]) == 'X')
            e.peca = VALOR_X;
        else e.peca = VALOR_O;
    }
    else
    {
        e.modo = 0;
        if (toupper (v[2]) == 'X')
            e.peca = VALOR_X;
        else e.peca = VALOR_O;
    }

    return e;
}

/**
 * A função "escrever" abre um ficheiro e escreve o jogo nesse ficheiro , sendo que depois guarda e fecha o ficheiro.
 * @param e, é o estado de jogo atual.
 * @param n, é um char.
 */
void escrever (ESTADO e,char n[100])
{
    FILE *ficheiro = fopen(n,"w");
    if(e.modo == 0) fprintf(ficheiro,"M ");
    else fprintf(ficheiro,"A ");

    if(e.peca == 'X') fprintf(ficheiro,"X\n");
    else fprintf(ficheiro,"O\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_O)fprintf(ficheiro, "O ");
            else if (e.grelha[i][j] == VALOR_X)fprintf(ficheiro, "X ");
            else fprintf(ficheiro, "- ");
        }
        fprintf(ficheiro, "\n");
    }

    fclose(ficheiro);
}

/**
 * A função "ler" lê um ficheiro sendo que, se o mesmo tiver um jogo guardado, há possibilidades de fazer alterações ao mesmo e depois guarda-o e fecha o ficheiro.
 * @param e, é o estado de jogo atual.
 * @param n, é um char.
 * @return estado de jogo alterado.
 */
ESTADO ler (ESTADO e, char n[100])
{
    FILE *ficheiro = fopen(n,"r");
    char a;

    fscanf(ficheiro,"%c ",&a);


    if(a == 'M') e.modo = 0;
    else e.modo = 1;

    fscanf(ficheiro,"%c ",&a);


    if(a == 'X') e.peca = VALOR_X;
    else e.peca = VALOR_O;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            fscanf(ficheiro,"%c ",&a);
            if (a == 'X') e.grelha[i][j] = VALOR_X;
            else if (a == 'O') e.grelha[i][j] = VALOR_O;
            else e.grelha[i][j] = VAZIA;
        }

    }

    fclose(ficheiro);

    return e;
}