/**
 * @file listase.h
 * @author ANGELINA PIERRE (you@domain.com)
 * @brief Biblioteca de lSE para a MÃO do jogador
 * @version 0.1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PEDRA_LDE_M_H
#define PEDRA_LDE_M_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"

typedef tp_peca tpi_hand;
// typedef int tpi_hand;


// Estrutura do nó que será inserido na mão
typedef struct tp_node_aux{
    tpi_hand info;
    struct tp_node_aux *ant, *prox;
}tp_noh;

typedef struct{
    tp_noh *ini,*fim;
}tp_listade; // ou tp_mao


// alocação da lista
tp_listade *inicializa_lde(){
    tp_listade *l;
    l = (tp_listade *)malloc(sizeof(tp_listade));
    l->ini = NULL;
    l->fim = NULL;
    printf("\n|LDE_ALOC|\n");
    return l;
}

// função p/ verificar se a lista esta vazia
int empty_lde(tp_listade *l){
    if(l->ini == NULL){
        return 1; // empty
    }else{
        return 0;
    }
}

// alocar nó na lista
tp_noh *aloca_ndeh(){ // ndeh = no duplamente encadeado mao
    tp_noh *pt;
    pt = (tp_noh *)malloc(sizeof(tp_noh));
    return pt;
}


// inserindo nó no fim
int insert_lde_fim (tp_listade *l, tpi_hand e){
    tp_noh *novo_no;
    novo_no = aloca_ndeh();
    if(!novo_no){
        return 0;;
    }
    novo_no->info = e;
    if(empty_lde(l)){
        // primeiro nó
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        l->ini = l->fim = novo_no;
    }else{
        novo_no->prox = NULL;
        novo_no->ant = l->fim;
        l->fim->prox = novo_no;
        l->fim = novo_no;
    }
    return 1;
}


// imprimindo lista -> imprimindo mao? printf_hand()
// op: 1- ordem normal 2 - ordem reversa
void imprime_listade(tp_listade *l, int op){
    tp_noh *atu;
    switch(op){
        case 1:
            atu = l->ini;
            while(atu!= NULL){
                printf("|%d|%d|\t",atu->info.ld1,atu->info.ld2);
                atu= atu->prox;
            }
            break;
        case 2:
            atu = l->fim;
            while(atu!=NULL){
                printf("|%d|\t",atu->info);
                atu = atu->ant;
            }
            break;
        default: printf("\n|COD ERROR|\n");
    }
    printf("\n");
}

int tamanho_listade(tp_listade *l){
    tp_noh *atu;
    int tam=0;
    atu = l->ini;
    while(atu!= NULL){
        atu= atu->prox;
        tam++;
    }
    return tam;
}

// removendo da lista -> com base no conteudo.
// int remove_listade(tp_listade *l, tpi_hand e){
//     tp_noh *atu;
//     atu = l->ini;
//     while((atu!=NULL) && (atu->info != e)){
//         atu = atu->prox; // procurando na lista
//     }
//     if(atu == NULL){
//         return 0; // não encontrado
//     }
//     if(l->ini == l->fim){
//         // unico elemento na lista
//         l->ini = l->fim = NULL;
//     }else{
//         if(l->ini == atu){
//             // 1 elelmento da lista - l=2
//             l->ini = atu->prox;
//             atu->prox->ant = NULL;
//         }else{
//             if(l->fim == atu){
//                 // ultimo no da lista
//                 l->fim = atu->ant;
//                 atu->ant->prox = NULL;
//             }else{
//                 atu->prox->ant = atu->ant;
//                 atu->ant->prox = atu->prox;
//             }
//         }
//     }
//     free(atu);
//     // atu = NULL;
//     return 1;
// }

// tp_noh *busca_listade(tp_listade *l, tpi_hand e){
//     tp_noh *atu;
//     atu = l->ini;
//     while((atu!=NULL)&&(atu->info != e)){
//         atu = atu->prox;
//     }
//     return atu;
// }

// Retira da memoria todos os nós da lista e também o descritor.
tp_listade *destroi_listade(tp_listade *l){
    tp_noh *atu;
    atu = l->ini;
    while(atu!=NULL){
        l->ini = atu->prox;
        free(atu);
        atu = l->ini;
    }
    printf("\n|LDE DESTROYED|\n");
    free(l);
    return NULL;

}


#endif