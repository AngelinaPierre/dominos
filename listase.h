/**
 * @file listase.h
 * @author ANGELINA PIERRE (you@domain.com)
 * @brief Biblioteca de lSE para a mao do jogador
 * @version 0.1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"

typedef int tpi_hand;

typedef struct tp_no{
    tpi_hand info;
    struct tp_no *prox;
}tp_listaseH;

// inicializando o ponteiro para os nos
tp_listaseH *inicializa_mao(){
    return NULL;
}

// verificar se a lista esta vazia
int listase_vazia(tp_listaseH *l){
    if( == NULL){
        return 1; // lista vazia
    }else{
        return 0;
    }
}

// alocar espaço para a lista;

tp_listaseH *aloca_se(){
    tp_listaseH *nls;
    nls = (tp_listaseH *)malloc(sizeof(tp_listaseH));
    return nls;
}

//insere lista 


#endif