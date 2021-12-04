#ifndef PLAYER_H
#define PLAYER_H


#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "pedra_lde_mao.h"



typedef struct{
    char name[100]; // ou vetor se não cosneguir fazer alocação dinamica
    tp_listade *hand;
}tp_player;

// função para iniciar a mão quando for pegar a peça no monte

tp_player *aloca_player(){
    tp_player *novo_player;
    novo_player = (tp_player *)malloc(sizeof(tp_player));
    if(novo_player == NULL){
        printf("\n|PLAYER NOT ALLOCATED|\n");
    }
    //novo_player->name = (char *)malloc(sizeof(char));
    
    novo_player->hand = inicializa_lde();
    return novo_player;
}


tp_player *inicializa_players(){
    // alocando os jogadores
    tp_player *p1 = aloca_player();

	
    printf("DIGITE NOME PLAYER: ");
    scanf("%[^\n]s",p1->name);
    printf("\n|PLAYER| = |%s|\n",p1->name);
    fflush(stdin);


    return p1;
}

#endif