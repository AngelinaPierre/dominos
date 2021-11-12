/**
 * @file lista_de.h
 * @author ANGELINA PIERRE (gaptp95@gmail.com)
 * @brief LIBRARY OF CHAINED DOUBLE QUEUE
 * @version 0.1
 * @date 2021-11-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LISTA_DE_H
#define LISTA_DE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief ESTRUTURAS DO DESCRITOR E NÓ
 * 
 */

typedef int tp_item;

//ESTRUTURA DO NÓ
typedef struct tp_no_aux{
    tp_item info;
    struct tp_no_aux *ant;
    struct tp_no_aux *prox;
}tp_no;

//Estrutura do DESCRITOR

typedef struct{
    tp_no *ini;
    tp_no *fim;
    // int tamanho;
}tp_listade;

/**
 * @brief Aloca-se memoria para o descritor (explicado no inico deste arquivo) e faz o seus ponteiros apontarem para o nulo. * 
 */
tp_listade *inicializa_listade(){
    tp_listade *lista = (tp_listade*)malloc(sizeof(tp_listade));
    lista->ini=NULL;
    lista->fim=NULL;
    // lista->tamanho = 0;
    return lista;
}

int listade_vazia(tp_listade *lista){
    if(lista->ini == NULL) return 1;// lista vazia
    return 0;//lista com items
}

//aloca um nó da lista
tp_no *aloca_listade(){
    tp_no *pt;
    pt=(tp_no*)malloc(sizeof(tp_no));
    return pt;
}

// Insere um novo nó na lista
int insere_listade_fim(tp_listade *lista,tp_item e){
    tp_no *novo;
    novo = aloca_listade();
    if(!novo){
        return 0;
    }
    novo->info=e;
    // if((lista->ini==NULL)&&(lista->fim==NULL))
    if(listade_vazia(lista)){
        // primeiro elemento da lista
        novo->prox=NULL;
        novo->ant=NULL;
        lista->ini = lista->fim = novo;
    }else{
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim=novo;
    }
    // lista->tamanho++;
    return 1;
}

// IMPRIME OS CONTEUDOS DA LISTA (DE FRENTE P/ TRAS O DE TRAS P/ FRENTE)

void imprime_listade(tp_listade *lista, int ordem){
    tp_no *atu;
    switch (ordem)
    {
    case 1:
        atu = lista->ini;
        while(atu!=NULL){
            printf("|%d|\t",atu->info);
            atu = atu->prox;
        }
        break;
    case 2:
        atu = lista->fim;
        while(atu!=NULL){
            printf("|%d|\t",atu->info);
            atu = atu->ant;
        }
        break;    
    default: printf("\nCodigo invalido!\n");
    }
    printf("\n");
}

// Remove um elemento da lista

int remove_listade(tp_listade *lista, tp_item e){
    tp_no *atu;
    atu = lista->ini;
    while((atu!=NULL) && (atu->info != e)){
        atu = atu->prox;
    }
    if(atu == NULL) return 0;
    if(lista->ini == lista->fim){
        // se 0 for o unico elemento da lista
        lista->ini = lista->fim = NULL;
    }else{
        if(lista->ini == atu){
            // Se for o 1° elemento da lista
            lista->ini = atu->prox;
            atu->prox->ant = NULL;
        }else{
            if(lista->fim == atu){
                //se for o ultimo nó da lista
                lista->fim = atu->ant;
                atu->ant->prox = NULL;
            }else{
                atu->prox->ant = atu->ant;
                atu->prox = atu->prox;
            }
        }
    }
    free(atu);
    // lista->tamanho--;
    return 1;
}

// Com base em um conteudo, retorna-se o endereço do nó que contém o conteudo
tp_no *busca_listade(tp_listade *lista, tp_item e){
    tp_no *atu;
    atu = lista->ini;
    while((atu!=NULL)&&(atu->info != e)){
        atu = atu->prox;
    }
    return atu;
}

// Retira da memoria todos os nós da lista e também o descritor.
tp_listade *destroi_listade(tp_listade *lista){
    tp_no *atu;
    atu = lista->ini;
    while(atu!=NULL){
        lista->ini = atu->prox;
        free(atu);
        atu = lista->ini;
    }
    free(lista);
    return NULL;

}



#endif