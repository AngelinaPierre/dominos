#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "pilha.h"
#define MAX 100

typedef int tp_item;

typedef struct{
    tp_item item[MAX];
    int ini, fim;
    // int tam;
}tp_fila;

void initialize_q(tp_fila *f){
    f->ini = f->fim = MAX -1;
    // f->tam = 0;
}

int empty_q(tp_fila *f){
    if(f->ini == f->fim){
        return 0;
    }
}

int next(int pos){
    if(pos==MAX-1){
        return 0;
    }
    return ++pos;
}

int full_q(tp_fila *f){
    if(next(f->fim)==f->ini){
        return 1;
    }
    return 0;
}

int insert_q(tp_fila *f, tp_item e){
    if(full_q(f)){
        return 0; //não foi possivel add
    }
    f->fim = next(f->fim);
    f->item[f->fim] = e;
    // f->tam++;
    return 1;
}

int remove_q(tp_fila *f, tp_item *e){
    if(empty_q(f)){
        return 0; // not possible remove
    }
    f->ini = next(f->ini);
    *e = f->item[f->ini];
    //f->tam--;
    return 1;
}

void print_q(tp_fila f){
    tp_item e;
    while(!empty_q(&f)){
        remove_q(&f,&e);
        printf("\t|%d",e);
    }
}

// We have three options for the function of the size_q

int size_q(tp_fila *f){
    if(empty_q(f)){
        return 0;
    }
    if(f->ini < f->fim){
        return f->fim - f->ini;
    }
    return MAX -1 - f->ini + f->fim + 1;
}


int size_q2(tp_fila f){
    int cont =0;
    tp_item e;
    while(!empty_q(&f)){
        remove_q(&f,&e);
        cont++;
    }
    return cont;
}

// int size_q3(tp_fila *f){
//     return f->tam;
// }

void invert_q(tp_fila *f){
    tp_pilha paux;
    tp_item e;
    inicializa_pilha(&paux);
    while(!empty_q(f)){
        remove_q(f,&e);
        push(&paux,e);
    }
    while(!pilha_vazia(&paux)){
        pop(&paux,&e);
        insert_q(f,e);
    }
}

#endif