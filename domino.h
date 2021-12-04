#ifndef DOMINO_H
#define DOMINO_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "mesa.h"
#include "player.h"


// terminar função para pegar na peca

void pega_pecas(tp_pilha *monte, tp_player *p1, tp_player *p2, tp_player *p3, tp_player *p4){ 
	// Inserir_na_lista
	int i;
	tp_peca a;
	for(i = 0; i < 7; i++){
		pop(monte, &a);
		insert_lde_fim (p1->hand, a);
	}
	// for(i = 0; i < 7; i++){
	// 	pop(monte, &a);
	// 	insert_lde_fim (p2->hand, a);
	// }
	// for(i = 0; i < 7; i++){
	// 	pop(monte, &a);
	// 	insert_lde_fim (p3->hand, a);
	// }
	// for(i = 0; i < 7; i++){
	// 	pop(monte, &a);
	// 	insert_lde_fim (p4->hand, a);
	// }
}



#endif