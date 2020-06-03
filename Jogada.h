//
// Created by barbosa on 19-05-2019.
//

#ifndef REVERSIGRUPO8_JOGADA_H
#define REVERSIGRUPO8_JOGADA_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "estado.h"
#include "jogo.h"
int veJogadaUp (int l, int c, ESTADO e);
int veJogadaDown (int l, int c, ESTADO e);
int veJogadaRight (int l, int c, ESTADO e);
int veJogadaLeft (int l, int c, ESTADO e);
int veJogadaDgdirup (int l, int c, ESTADO e);
int veJogadaDgesqup (int l, int c, ESTADO e);
int veJogadaDgdirdown (int l, int c, ESTADO e);
int veJogadaDgesqdown (int l, int c, ESTADO e);
int verificajog (int l, int c , ESTADO e);
ESTADO joga (int l, int c, ESTADO e);

#endif //REVERSIGRUPO8_JOGADA_H
