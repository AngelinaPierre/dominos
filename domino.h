#ifndef DOMINO_H
#define DOMINO_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "mesa.h"
#include "player.h"


// terminar função para pegar na peca -> fazer com 1 jogador por x

// void pega_pecas(tp_pilha *monte, tp_player *p1,tp_player *p2,tp_player *p3,tp_player *p4){
// 	// Inserir_na_lista
// 	int i;
// 	tp_peca a;
// 	for(i = 0; i < 7; i++){
// 		pop(monte, &a);
// 		insert_lde_fim (p1->hand, a);
// 	}
// 	// for(i = 0; i < 7; i++){
// 	// 	pop(monte, &a);
// 	// 	insert_lde_fim (p2->hand, a);
// 	// }
// 	// for(i = 0; i < 7; i++){
// 	// 	pop(monte, &a);
// 	// 	insert_lde_fim (p3->hand, a);
// 	// }
// 	// for(i = 0; i < 7; i++){
// 	// 	pop(monte, &a);
// 	// 	insert_lde_fim (p4->hand, a);
// 	// }
// }

void pega_pecas(tp_pilha *monte, tp_player *p1, tp_player *p2, tp_player *p3, tp_player *p4){
	// Inserir_na_lista
	int i;
	tp_peca a, b, c, d;
	while(!pilha_vazia(monte)){
        for(i = 0; i < 7; i++){
		    pop(monte, &a);
            printf("INSERT_P1 -> |%d|%d|\n",a.ld1,a.ld2);
		    insert_lde_fim (p1->hand, a);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &b);
            printf("INSERT_P2 -> |%d|%d|\n",b.ld1,b.ld2);
		    insert_lde_fim (p2->hand, b);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &c);
            printf("INSERT_P3 -> |%d|%d|\n",c.ld1,c.ld2);
		    insert_lde_fim (p3->hand, c);
	    }
	    for(i = 0; i < 7; i++){
		    pop(monte, &d);
            printf("INSERT_P4 -> |%d|%d|\n",d.ld1,d.ld2);
		    insert_lde_fim (p4->hand, d);
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


#endif
