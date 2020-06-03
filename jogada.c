//
// Created by barbosa on 19-05-2019.
//

#include "Jogada.h"
#include "estado.h"

/**
 * A função "veJogadaUp" verifica se é possível o jogador efetuar uma jogada para cima. Deste modo percorre a coluna para cima comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaUp (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l - 1, ci = c;
    if (e.grelha [li][ci] != v || li < 1) return 0;
    else {
        li--;
        while (li != 0 && e.grelha [li][ci] == v) li--;
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaDown" verifica se é possível o jogador efetuar uma jogada para baixo. Deste modo percorre a coluna para baixo comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaDown (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l + 1, ci = c;
    if (e.grelha [li][ci] != v || li > 6) return 0;
    else {
        li++;
        while (li != 7 && e.grelha [li][ci] == v) li++;
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaRight" verifica se é possível o jogador efetuar uma jogada para a direita. Deste modo percorre a linha para a direita comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaRight (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l, ci = c + 1;
    if (e.grelha [li][ci] != v || ci > 6) return 0;
    else {
        ci++;
        while (ci != 7 && e.grelha [li][ci] == v) ci++;
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaLeft" verifica se é possível o jogador efetuar uma jogada para a esquerda. Deste modo percorre a linha para a esquerda comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaLeft (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l, ci = c - 1;
    if (e.grelha [li][ci] != v || ci < 1) return 0;
    else {
        ci--;
        while (ci != 0 && e.grelha [li][ci] == v) ci--;
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaDgdirup" verifica se é possível o jogador efetuar uma jogada para cima e para a direita. Deste modo percorre a coluna para cima e a linha para a direita simultaneamente comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaDgdirup (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l - 1, ci = c + 1;
    if (e.grelha [li][ci] != v || ci > 6 || li < 1) return 0;
    else {
        ci++;
        li--;
        while (ci != 7 && li != 0 && e.grelha [li][ci] == v) {ci++;li--;}
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaDgesqup" verifica se é possível o jogador efetuar uma jogada para cima e para a esquerda. Deste modo percorre a coluna para cima e a linha para a esquerda simultaneamente comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaDgesqup (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l - 1, ci = c - 1;
    if (e.grelha [li][ci] != v || ci < 1 || li < 1) return 0;
    else {
        ci--;
        li--;
        while (ci != 7 && li != 0 && e.grelha [li][ci] == v) {ci--;li--;}
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaDgdirdown" verifica se é possível o jogador efetuar uma jogada para baixo e para a direita. Deste modo percorre a coluna para baixo e a linha para a direita simultaneamente comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaDgdirdown (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l + 1, ci = c + 1;
    if (e.grelha [li][ci] != v || ci > 6 || li > 6) return 0;
    else {
        ci++;
        li++;
        while (ci != 7 && li != 0 && e.grelha [li][ci] == v) {ci++;li++;}
        if (e.grelha [li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "veJogadaDgesqdown" verifica se é possível o jogador efetuar uma jogada para baixo e para a esquerda. Deste modo percorre a coluna para baixo e a linha para a esquerda simultaneamente comparando sempre a sua peça com o que se encontra
 * em cada quadrado do tabuleiro até encontrar uma peça igual à sua de modo a que a jogada possa ser efetudada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */
int veJogadaDgesqdown (int l, int c, ESTADO e) {
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    int li = l + 1, ci = c - 1;
    if (e.grelha[li][ci] != v || ci > 1 || li > 6) return 0;
    else {
        ci--;
        li++;
        while (ci != 7 && li != 0 && e.grelha[li][ci] == v) {ci--;li++;}
        if (e.grelha[li][ci] == e.peca) return 1;
        else return 0;
    }
}

/**
 * A função "verificajog" verifica se a jogada é passível de ser realizada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return 0 (verdade) caso a função dê verdadeiro.
 */

int verificajog (int l, int c , ESTADO e){
    if (veJogadaDgdirdown (l,c,e)) return 1;
    else if (veJogadaDgdirup (l,c,e)) return 1;
    else if (veJogadaDgesqdown (l,c,e)) return 1;
    else if (veJogadaDgesqup (l,c,e)) return 1;
    else if (veJogadaDown (l,c,e)) return 1;
    else if (veJogadaUp (l,c,e)) return 1;
    else if (veJogadaLeft (l,c,e)) return 1;
    else if (veJogadaRight (l,c,e)) return 1;
    else return 0;
}

/**
 * A função "joga" efetua a jogada a ser realizada.
 * @param l, é a linha do tabuleiro.
 * @param c, é a coluna do tabuleiro.
 * @param e, é o estado de jogo atual.
 * @return estado de jogo alterado.
 */
ESTADO joga (int l, int c, ESTADO e) {
    int a = veJogadaDgdirdown (l,c,e);
    int b = veJogadaDgdirup (l,c,e);
    int d = veJogadaDgesqdown (l,c,e);
    int f = veJogadaDgesqup (l,c,e);
    int g = veJogadaDown (l,c,e);
    int h = veJogadaUp (l,c,e);
    int i = veJogadaLeft (l,c,e);
    int j = veJogadaRight (l,c,e);
    int l2 = l, c2 = c;

    e.grelha[l][c] = e.peca;
    if (a) {
        c2 = c + 1;
        l2 = l + 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c2++;
            l2++;
        }
    }
    if (b) {
        c2 = c + 1;
        l2 = l - 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c2++;
            l2--;
        }
    }
    if (d) {
        c2 = c - 1;
        l2 = l + 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c--;
            l2++;
        }
    }
    if (f) {
        c2 = c - 1;
        l2 = l - 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c2--;
            l2--;
        }
    }
    if (g) {
        c2 = c;
        l2 = l + 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            l2++;
        }
    }
    if (h) {
        c2 = c;
        l2 = l - 1;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            l2--;
        }
    }
    if (i) {
        c2 = c - 1;
        l2 = l;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c2--;
        }
    }
    if (j) {
        c2 = c + 1;
        l2 = l;
        while (e.grelha[l2][c2] != e.peca) {
            e.grelha[l2][c2] = e.peca;
            c2++;
        }
    }
    if (e.peca == VALOR_X) e.peca = VALOR_O;
    else e.peca = VALOR_X;
    return e;
}