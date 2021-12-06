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

//criar ordenação da mão por soma

void ordena_pecas(tp_player *p){
    tp_noh *esq, *dir,*atu;
    esq = p->hand->ini;
    atu = p->hand->ini;
    dir = p->hand->ini->prox;
    imprime_listade(p->hand,1);
    while(soma_peca(esq->info) > soma_peca(dir->info)){
        if(esq->ant == NULL){
            atu = dir;
            dir = esq;
            esq = atu;
        }
    }
}

// void ordena_pecas(tp_player *p){
//     // int tam = tamanho_listade(p->hand),s1,s2;
//     // tp_peca peca;
//     printf("\n|ordenando peças|\n");
//     tp_noh *atu=p->hand->ini,*temp;
//     imprime_listade(p->hand,1);

//     while(soma_peca(atu->info) > soma_peca(atu->prox->info)){
//         if(atu->ant == NULL){
//             temp = atu;
//             // PRIMEIRO ITEM
//             // ligando o segundo ao ini
//             p->hand->ini = atu->prox;
//             // ligando atu
//             atu->prox = atu->prox->prox;
//             atu->ant = p->hand->ini;
//             // ligando o 3
//             p->hand->ini->prox->ant = atu;
//             // ligando o primeiro
//             p->hand->ini->prox = temp;
//             p->hand->ini->ant = NULL;
//             printf("\n|O1|\n");
//             imprime_listade(p->hand,1);

//         }else if(atu->prox->prox == NULL){
//             temp = atu->prox;
//             temp->ant = atu->ant;
//             temp->prox = atu;
//             atu->ant = temp;
//             atu->prox = NULL;
//             printf("\n|O2|\n");
//             // imprime_listade(p->hand,1);
//         }else{
//             temp = atu->prox;
//             atu->prox = temp->prox;
//             temp->ant = atu->ant;
//             temp->prox = atu;
//             atu->ant = temp;            
//             printf("\n|O3|\n");
//             // imprime_listade(p->hand,1);
//         }
//         atu = atu->prox;
//     }
//     imprime_listade(p->hand,1);
// }



int ordem_jogo(tp_player p1, tp_player p2, tp_player p3, tp_player p4){ //Busca lista
	int jog1, jog2, jog3, jog4;
	
	jog1 = busca_lista_pc(p1.hand, 5,5);
	jog2 = busca_lista_pc(p2.hand, 5,5);
	jog3 = busca_lista_pc(p3.hand, 5,5);
	jog4 = busca_lista_pc(p4.hand, 5,5);
	
	if(jog1 != 7) return 1;
	if(jog2 != 7) return 2;
	if(jog3 != 7) return 3;
	if(jog4 != 7) return 4;
}

#endif