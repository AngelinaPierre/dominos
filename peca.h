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