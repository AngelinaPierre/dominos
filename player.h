#ifndef PLAYER_H
#define PLAYER_H


#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "listade.h"



typedef struct{
    char *name; // ou vetor se não cosneguir fazer alocação dinamica
    tp_listade *hand;
}tp_player;

// função para iniciar a mão quando for pegar a peça no monte

tp_player *aloca_player(){
    tp_player *novo_player;
    novo_player = (tp_player *)malloc(sizeof(tp_player));
    if(novo_player == NULL){
        printf("\n|PLAYERS NOT ALLOCATED|\n");
    }
    novo_player->name = (char *)malloc(sizeof(char));
    novo_player->hand = inicializa_lde();
    return novo_player;
}


tp_player *inicializa_players(tp_player *p1, tp_player *p2, tp_player *p3, tp_player *p4){
    // alocando os jogadores
    p1 = aloca_player();
    p2 = aloca_player();
    p3 = aloca_player();
    p4 = aloca_player();

    printf("DIGITE NOME PLAYER 1: ");
    scanf("%[^\n]s",p1->name);
    fflush(stdin);
    printf("DIGITE NOME PLAYER 2: ");
    scanf("%[^\n]s",p2->name);
    fflush(stdin);
    printf("DIGITE NOME PLAYER 3: ");
    scanf("%[^\n]s",p3->name);
    fflush(stdin);
    printf("DIGITE NOME PLAYER 4: ");
    scanf("%[^\n]s",p4->name);
    // fflush(stdin);

    printf("\n|NOME JOGADORES|\n");
    printf("\n|PLAYER 1| = |%s|\n",p1->name);
    printf("\n|PLAYER 2| = |%s|",p2->name);
    printf("\n|PLAYER 3| = |%s|",p3->name);
    printf("\n|PLAYER 4| = |%s|",p4->name);
    return p1,p2,p3,p4;
}

#endif