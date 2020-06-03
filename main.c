#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "estado.h"
#include "jogo.h"
#include "Jogada.h"
#include <string.h>
#include "stack.h"

//grupo8

/**
 * A função "main" contém os comandos necessários para jogar o "Reversi" sendo estes o comando "J" que vai ser utilizado para cada jogador fazer a sua jogada,
 * o comando "L" que vai ler o ficheiro onde o nosso jogo está guardado, o comando "E" que vai escrever no ficheiro que estamos a utilizar, o comando "N" que cria um novo jogo,
 * o comando "U" que retrocede jogadas no nosso jogo e, caso o jogo esteja no seu estado inicial, retrocede para o jogo anterior e o comando "S" que imprime o estado atual de jogo com as
 * diferentes possibilidades de jogada para o jogador atual.
 * @return 0 (verdade) sendo que a função retorna o inteiro 0 se o caso utilizado for verdadeiro e funcional.
 */

int main()
{
    char comando[50];
    ESTADO e = {0};
    char nome[20];

    while (toupper(comando[0]) != 'Q'){

        printf("Digite algo:\n");
        fgets(comando,50,stdin); //vai por no array os comandos

        switch (toupper(comando[0])) {
            case 'J': {
                char s;
                int ci, li;
                sscanf(comando, "%c %d %d", &s, &li, &ci);
                if (verificajog(li,ci,e)) {
                    e = joga (li,ci,e);
                    nestado(e);
                }
                else printf ("JOGADA INVÁLIDA!\n");
                break;
            }
            case 'L': {
                sscanf(comando + 2, "%s", nome);
                e = ler(e, nome);
                break;
            }
            case 'E': {
                sscanf(comando + 2, "%s", nome);
                escrever(e, nome);
                struct Node *s;
                s = (struct Node *) malloc(sizeof(struct Node));
                s -> est = e;
                s -> next = NULL;
                top = s;
                break;
            }
            case 'N':
                e = novojogo (e,comando);
                struct Node *s;
                s = (struct Node *) malloc(sizeof(struct Node));
                s -> est = e;
                s -> next = NULL;
                top = s;
                break;
            case 'U':
                if (top -> next != NULL) {
                anterior();
                e = top -> est;
                }
                break;
            case 'S':
                printaS(e);
                break;
            default :
                printf("Comando inválido\nInsira um comando válido\n");
                break;
        }

        printf("\n");
        printa(e);
        printf("\n");

    }

    printf("Acabou o jogo!\n");

    return 0;
}