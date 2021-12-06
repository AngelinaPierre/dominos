#ifndef DOMINO_H
#define DOMINO_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "mesa.h"
#include "player.h"


void insere_ordenado(tp_player *player, tpi_hand peca){
	tp_noh *novo_no, *atu;
	int pos = 0;
    novo_no = aloca_ndeh();
    novo_no->info = peca;
    if(empty_lde(player->hand)){
        // primeiro nó
        player->hand->ini = novo_no;
        player->hand->fim = novo_no;
        novo_no->prox = NULL;
        novo_no->ant = NULL;
    }else{
    	atu = player->hand->ini;
    	while(soma_peca(peca) >= soma_peca(atu->info) && atu->prox != NULL){
    		atu = atu->prox;
    		pos++;
		}
		if(atu->prox == NULL && soma_peca(peca) >= soma_peca(atu->info)){
			novo_no->prox = NULL;
    		novo_no->ant = atu;
    		atu->prox = novo_no;
        	player->hand->fim = novo_no;
		}else{
			if(atu->prox == NULL && soma_peca(peca) < soma_peca(atu->info)){
				novo_no->prox = atu;
				if(pos == 0){
					novo_no->ant = NULL;
				}else{
					novo_no->ant = atu->ant;
				}
				if(pos != 0){
					atu->ant->prox = novo_no;
				}
				atu->ant = novo_no;
				atu->prox = NULL;
				player->hand->fim = atu;
				if(pos == 0){
					player->hand->ini = novo_no;
				}
			}else{
				if(pos > 0){
					novo_no->prox = atu;
					novo_no->ant = atu->ant;
					atu->ant->prox = novo_no;
					atu->ant = novo_no;
				}else{
					novo_no->prox = atu;
					novo_no->ant = NULL;
					atu->ant = novo_no;
					player->hand->ini = novo_no;
				}
			}
		}

	}
}

void pega_pecas(tp_pilha *monte, tp_player *p1, tp_player *p2, tp_player *p3, tp_player *p4){
	// Inserir_na_lista
	int i;
	tp_peca a;
	while(!pilha_vazia(monte)){
        for(i = 0; i < 7; i++){
		    pop(monte, &a);
            printf("INSERT_P1 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p1, a);
		    imprime_listade(p1->hand, 1);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            printf("INSERT_P2 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p2, a);
		    imprime_listade(p2->hand, 1);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            printf("INSERT_P3 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p3, a);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            printf("INSERT_P4 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p4, a);
	    }
    }
}

void escolha_peca(tp_mesa *mesa, tp_player *jog){ //Verificar quina
	char lado, passa;
	int p, i, fl, laux;
    tpi_hand e;
    tp_noh *atu;

	if (empty_lde(mesa->mesa)){
		while(1){
	        printf("\n");
	        atu = jog->hand->ini;
	        printf("\nEscolha uma peca: ");
	        scanf("%d",&p);
	        for(i = 0; i < p-1; i++){
	            atu = atu->prox;
	        }
	        if((atu->info.ld1 == 5) && (atu->info.ld2 == 5)){
	            insert_lde_fim (mesa->mesa, atu->info);
				remove_listade(jog->hand, atu->info);
				break;
	        }
	    }
	}
	else{
		while(fl != 1){
			fl = 0;
			//imprime_listade(jog->hand,1);
			//imprime_listade(mesa->mesa, 1);
			printf("\n");
	        atu = jog->hand->ini;
			printf("\nDeseja passar?: ");
			scanf(" %c",&passa);

			if(passa == 's') return;

			printf("\nEscolha uma peca: ");
	        scanf("%d",&p);
	        for(i = 0; i < p-1; i++){
	            atu = atu->prox;
	        }
			printf("\nEscolha um lado: ");
			scanf(" %c",&lado);
			switch (lado) {
				case 'e':
					if(atu->info.ld2 == mesa->mesa->ini->info.ld1){
						insert_lde_inicio (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else if(atu->info.ld1 == mesa->mesa->ini->info.ld1){
						laux = atu->info.ld2;
						atu->info.ld2 = atu->info.ld1;
						atu->info.ld1 = laux;
						insert_lde_inicio (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else{
						printf("Nao tem onde jogar a peca\n");
					}
				case 'd':
					if(atu->info.ld1 == mesa->mesa->fim->info.ld2){
						insert_lde_fim (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else if(atu->info.ld2 == mesa->mesa->fim->info.ld2){
						laux = atu->info.ld2;
						atu->info.ld2 = atu->info.ld1;
						atu->info.ld1 = laux;
						insert_lde_fim (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else{
						printf("Nao tem onde jogar a peca\n");
					}
				default: printf("Lado invalido\n");
			}
		}
	}
}

void inserir_peca_na_mesa(tp_mesa *m, tp_player *pl){
    printf("\nPlayer: %s\n", pl->name);
    imprime_listade(pl->hand,1);
    printf("\n-------------------------------------\n");
    imprime_listade(m->mesa, 1);
    printf("\n-------------------------------------\n");
    escolha_peca(m, pl);
}

void verificar_vencedor(tp_player *pl, int *venc){
    if(empty_lde(pl->hand)){
        printf("\nParabens %s voce ganhou a partida :)\n", pl->name);
        system("pause");
        *venc = 1;
    } else {
        *venc = 0;
    }
}


#endif
