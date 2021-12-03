#ifndef MONTE_H
#define MONTE_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"



typedef tp_peca tpi_monte;
//typedef int tpi_monte;

typedef struct tp_no_aux{
    tpi_monte info;
    struct tp_no_aux *prox;
}tp_nop;

typedef struct{
    tp_nop *topo; // head
}tp_pilha; // ou tp_lse_head

// alocação da pilha
tp_pilha *inicializa_pilha(){
    tp_pilha *p = (tp_pilha *)malloc(sizeof(tp_pilha));
    p->topo = NULL;
    // printf("\n|ALOC_SUCCESS|\n"); // criado o *pilha que ira apontar para o topo
    return p;
}

int pilha_vazia(tp_pilha *p){
    if(p->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}

// função auxiliar para alocar quando for inserir
tp_nop *aloca_no(){
    tp_nop *novo_no;
    novo_no = (tp_nop*)malloc(sizeof(tp_nop));
    if(novo_no==NULL){
        printf("\n|NO_NA|\n");
        return 0;
    }
    novo_no->prox = NULL;
    return novo_no;
}

// inserindo
// mudar

int push(tp_pilha *p, tpi_monte e){
    tp_nop *novo_no;
    novo_no = aloca_no();
    novo_no->info = e;
    // printf("\n| e = %d|\n",novo_no->info);
    if(pilha_vazia(p)){
        // printf("Primeiro item\n");
        p->topo = novo_no;
    }else{
        // printf("\n segundo item");
        novo_no->prox = p->topo;
        p->topo = novo_no;
    }
    return 1;
}

// removendo da pilha -> diretamente para  a mão do jgoador?
int pop(tp_pilha *p, tpi_monte *e){
    if(pilha_vazia(p)){
        return 0;
    }
    tp_nop *no_aux; // no que ira salvar o endereço do topo e depois ser deletado
    no_aux = p->topo;


    *e = p->topo->info; // salva o valor da variavel retirada em e.
/*    if(*e == p->topo->info){
        printf("\n|work|\n");
    }*/
    p->topo = p->topo->prox; // topo aponta para o anti-topo

    // desalocando o nó
    free(no_aux);
    no_aux =  NULL;

    return 1;
}

tp_pilha *destroi(tp_pilha *p){
    tpi_monte e;

    while(!pilha_vazia(p)){
        pop(p,&e);
    }
    free(p);
    printf("\n|destruindo pilha|\n");
    return NULL;
}

void imprime_pilha(tp_pilha p){
	tpi_monte e;
	printf("\n");
	while (!pilha_vazia(&p)){
		pop(&p,&e);
        //printf("%d\n", e);
		printf("%d ", e.ld2);
		printf("%d \n", e.ld1);
	}
}

void gera_pecas(tp_pilha *monte){
    tp_peca peca;
    int j, i, soma;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if(j >= i){
            soma = i + j;
            peca.ld1 = j;
            peca.ld2 = i;
            push(monte, peca);
            }
        }
    }
}

#endif
