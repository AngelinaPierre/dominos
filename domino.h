#ifndef DOMINO_H
#define DOMINO_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "mesa.h"
#include "player.h"


// terminar função para pegar na peca
// void pegar_pedra(tp_player *player, tp_peca peca){
// 	tp_noh *novo, *atu;
// 	novo->info = peca;
// 	if(empty_lde(player->hand)){
// 		novo->prox = NULL;
//         novo->ant = NULL;
//         player->hand->ini = player->hand->fim = novo;
// 	}else{
// 		atu = player->hand->ini;
// 		while(){
//         	atu = atu->prox;
//     	}
// 	}
	
	
// }

void pega_pecas(tp_pilha *monte){ 
    // Inserir_na_lista
    int i;
    tp_peca a;
    for(i = 0; i < 7; i++){
        pop(monte, &a);
        printf("%d ", a.ld1);
        // insert_lde_fim (jogador1->hand, a);
        //pega_pedra(jogador1, a);
    }
//    for(i = 0; i < 7; i++){
        //pop(p_p, &a);
        //pega_pedra(jogador2, a);
//    }
//    for(i = 0; i < 7; i++){
        //pop(p_p, &a);
        //pega_pedra(jogador3, a);
//    }
//    for(i = 0; i < 7; i++){
    //    pop(p_p, &a);
        //pega_pedra(jogador4, a);
//    }
}



#endif