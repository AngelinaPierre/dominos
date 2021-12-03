#ifndef MONTE_H
#define MONTE_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"



typedef tp_peca tpi_monte;
//typedef int tpi_monte;


/**
 * @brief FUNÇÕES ESTRUTURA DE PILHA IMPLEMENTADA POR LISTA ENCADEDA
 * 
 */

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









/**
 * @brief FUNÇÕES PARA JOGO
 * 
 * @param monte 
 */

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


void embaralha_pecas(tp_pilha *monte){
    int x, i;
    tp_pilha *aux1, *aux2, *aux3, *aux4;
    aux1 = inicializa_pilha();
    aux2 = inicializa_pilha();
    aux3 = inicializa_pilha();
    aux4 = inicializa_pilha();
    tp_peca pa, pb, pc, pd, pe;

    srand(time(NULL));

    for (i = 0; i < 28; i++) {
        x = rand() % 40;
        pop(monte, &pa);
        if(x < 10){
			push(aux1, pa);
		} else if((x > 10) && (x < 20) || (x == 10)){
			push(aux2, pa);
		} else if((x > 20) && (x < 30) || (x == 20)){
			push(aux3, pa);
		} else if((x > 30)|| (x == 30)){
			push(aux4, pa);
		}
    }
    while(!pilha_vazia(aux1)){
		pop(aux1, &pb);
		push(monte, pb);
	}
	while(!pilha_vazia(aux2)){
		pop(aux2, &pc);
		push(monte, pc);
	}
	while(!pilha_vazia(aux3)){
		pop(aux3, &pd);
		push(monte, pd);
	}
	while(!pilha_vazia(aux4)){
		pop(aux4, &pe);
		push(monte, pe);
	}
}


#endif
