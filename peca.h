#ifndef PECA_H
#define PECA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ld1,ld2;
}tp_peca;

/**
 * @brief CRIAR: gera_peca();
 * 
 */

// void gera_pecas(tp_pilha *monte){

// }


// void gera_pecas(tp_pilha *p_p){
// 	tp_item peca;
// 	int j, i;
// 	for (j = 0; j < 7; j++){
// 		for (i = 0; i < 7; i++){
// 			if (i <= j){
// 			peca.ld2 = j;
// 			peca.ld1 = i;
// 			push(p_p, peca);
// 			}
// 		}	
	

/**
 * @brief CRIAR: soma_peca();
 * 
 */

int soma_peca(tp_peca p){
    return p.ld1 + p.ld2;
}

/**
 * @brief CRIAR: Ordenação das peças
 * 
 */


#endif