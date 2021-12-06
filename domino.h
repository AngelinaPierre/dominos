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
        // primeiro nÃ³
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
            //printf("INSERT_P1 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p1, a);
		    //imprime_listade(p1->hand, 1);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            //printf("INSERT_P2 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p2, a);
		    //imprime_listade(p2->hand, 1);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            //printf("INSERT_P3 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p3, a);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &a);
            //printf("INSERT_P4 -> |%d|%d|\n",a.ld1,a.ld2);
		    insere_ordenado(p4, a);
	    }
    }
}

void escolha_peca(tp_mesa *mesa, tp_player *jog, int *lda1, int *lda2){ //Verificar quina
	char lado, passa;
	int p, i, fl = 0, laux;
    tpi_hand e;
    tp_noh *atu;

	if (empty_lde(mesa->mesa)){
		while(1){
	        printf("\n");
	        atu = jog->hand->ini;
	        printf("\nEscolha uma peça: ");
	        scanf("%d",&p);
	        for(i = 0; i < p-1; i++){
	            atu = atu->prox;
	        }
	        if((atu->info.ld1 == 5) && (atu->info.ld2 == 5)){
				*lda1 = atu->info.ld1;
				*lda2 = atu->info.ld2;
				insert_lde_fim (mesa->mesa, atu->info);
				remove_listade(jog->hand, atu->info);
				break;
	        }
	    }
	}
	else{
		while(fl != 1){
			fl = 0;
			printf("\n");
	        atu = jog->hand->ini;
			printf("\nDeseja passar? (Digite s para sim ou n para não): ");
			scanf(" %c",&passa);

			if(passa == 's') return;

			printf("\nEscolha uma peça: ");
	        scanf("%d",&p);
	        for(i = 0; i < p-1; i++){
	            atu = atu->prox;
	        }
			printf("\nEscolha um lado (digite e para o lado esquerdo ou d para o lado direito da mesa): ");
			scanf(" %c",&lado);
			switch (lado) {
				case 'e':
					if(atu->info.ld2 == mesa->mesa->ini->info.ld1){
						*lda1 = atu->info.ld1;
						*lda2 = atu->info.ld2;
						insert_lde_inicio (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else if(atu->info.ld1 == mesa->mesa->ini->info.ld1){
						*lda1 = atu->info.ld1;
						*lda2 = atu->info.ld2;
						laux = atu->info.ld2;
						atu->info.ld2 = atu->info.ld1;
						atu->info.ld1 = laux;
						insert_lde_inicio (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else{
						printf("Não tem onde jogar a peça\n");
					}
				case 'd':
					if(atu->info.ld1 == mesa->mesa->fim->info.ld2){
						*lda1 = atu->info.ld1;
						*lda2 = atu->info.ld2;
						insert_lde_fim (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else if(atu->info.ld2 == mesa->mesa->fim->info.ld2){
						*lda1 = atu->info.ld1;
						*lda2 = atu->info.ld2;
						laux = atu->info.ld2;
						atu->info.ld2 = atu->info.ld1;
						atu->info.ld1 = laux;
						insert_lde_fim (mesa->mesa, atu->info);
						remove_listade(jog->hand, atu->info);
						fl = 1;
						break;
					}
					else{
						printf("Não tem onde jogar a peça\n");
					}
				default: printf("Lado inválido\n");
			}
		}
	}
}

void inserir_peca_na_mesa(tp_mesa *m, tp_player *pl, int *aux1, int *aux2){
    printf("\nPlayer: %s\n", pl->name);
    imprime_listade(pl->hand,1);
    printf("\n-------------------------------------\n");
    imprime_listade(m->mesa, 1);
    printf("\n-------------------------------------\n");
    escolha_peca(m, pl, aux1, aux2);
}

void verificar_vencedor(tp_player *pl, int *venc){
    if(empty_lde(pl->hand)){
        printf("\nParabêns %s! Você ganhou a partida! :)\n", pl->name);
        system("pause");
        *venc = 1;
    } else {
        *venc = 0;
    }
}

int verifica_num_pecas_jogo(int np1, int np2, int *pc0, int *pc1, int *pc2, int *pc3, int *pc4, int *pc5, int *pc6, tp_mesa *m){
    switch (np1) {
        case 0:
            *pc0 = *pc0-1;
            break;
        case 1:
            *pc1 = *pc1-1;
            break;
        case 2:
            *pc2 = *pc2-1;
            break;
        case 3:
            *pc3 = *pc3-1;
            break;
        case 4:
            *pc4 = *pc4-1;
            break;
        case 5:
            *pc5 = *pc5-1;
            break;
        case 6:
            *pc6 = *pc6-1;
            break;
    }
    switch (np2) {
        case 0:
            *pc0 = *pc0-1;
            break;
        case 1:
            *pc1 = *pc1-1;
            break;
        case 2:
            *pc2 = *pc2-1;
            break;
        case 3:
            *pc3 = *pc3-1;
            break;
        case 4:
            *pc4 = *pc4-1;
            break;
        case 5:
            *pc5 = *pc5-1;
            break;
        case 6:
            *pc6 = *pc6-1;
            break;
    }
	if(*pc0 == 0){
		if(m->mesa->ini->info.ld1 == 0 && m->mesa->fim->info.ld2 == 0){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc1 == 0){
		if(m->mesa->ini->info.ld1 == 1 && m->mesa->fim->info.ld2 == 1){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc2 == 0){
		if(m->mesa->ini->info.ld1 == 2 && m->mesa->fim->info.ld2 == 2){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc3 == 0){
		if(m->mesa->ini->info.ld1 == 3 && m->mesa->fim->info.ld2 == 3){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc4 == 0){
		if(m->mesa->ini->info.ld1 == 4 && m->mesa->fim->info.ld2 == 4){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc5 == 0){
		if(m->mesa->ini->info.ld1 == 5 && m->mesa->fim->info.ld2 == 5){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	if(*pc6 == 0){
		if(m->mesa->ini->info.ld1 == 6 && m->mesa->fim->info.ld2 == 6){
			printf("O jogo fechou e ninguem ganhou :( \n");
			return 1;
		}
	}
	return 0;
}

#endif
