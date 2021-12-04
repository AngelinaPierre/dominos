#ifndef PLAYER_H
#define PLAYER_H


#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "pedra_lde_m.h"
// #include "monte.h"



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

void qtd_pecas(tp_player *p1, tp_player *p2, tp_player *p3, tp_player *p4){ //tamanho_lista
	int jog1, jog2, jog3, jog4;
	
	jog1 = tamanho_listade(p1->hand);
	jog2 = tamanho_listade(p2->hand);
	jog3 = tamanho_listade(p3->hand);
	jog4 = tamanho_listade(p4->hand);
	
	printf("               %s : %d . %s : %d . %s: %d . %s: %d", p1->name, jog1,p2->name, jog2, p3->name, jog3,p4->hand , jog4);
	printf("\n");
}

#endif