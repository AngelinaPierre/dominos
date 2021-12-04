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

#endif