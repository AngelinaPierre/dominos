#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX 100
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef int
    tp_item;

typedef struct{
    int topo;
    tp_item item[MAX];
}tp_pilha;


void inicializa_pilha(tp_pilha *p){
    p->topo = -1;
};

int pilha_vazia(tp_pilha *p){
    if(p->topo == -1){
        // printf("Pilha Vazia");
        return 1;
    }else{
        return 0;
    }
};

int pilha_cheia(tp_pilha *p){
    if(p->topo ==MAX-1){//99
        // printf("Pilha cheia!");
        return 1;
    }else{
        return 0;
    }
};

int push(tp_pilha *p, tp_item e){
    if(pilha_cheia(p)==1){
        return 0;
    }
    p->topo++;
    p->item[p->topo]=e;
    return 1;
};

int pop(tp_pilha *p, tp_item *e){
    if(pilha_vazia(p)==1){
        return 0;
    }
    *e = p->item[p->topo];
    p->topo--;
    return 1;
};

int top(tp_pilha *p, tp_item *e){
    if(pilha_vazia(p)){
        return 0;
    }
    *e = p->item[p->topo];
    return 1;
};

void imprime_pilha(tp_pilha p){
    tp_item e;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p,&e);
        printf("|%d|\n",e);
    }
};

int altura_pilha(tp_pilha *p){
    return p->topo+1;
};

// int remove_impar(tp_pilha *p){
//     tp_pilha pilha2;
//     inicializa_pilha(&pilha2);
//     tp_item e;

//     while(p->item[p->topo]!= -1){ // while(!pilha_vazia(p))
//         pop(p,&e);
//         if(e%2==0){
//             push(&pilha2,e);
//         }
//     }
//     inicializa_pilha(p);

//     while(pilha2.topo != -1){
//         pop(&pilha2,&e);
//         push(p,e);
//     }

// };

// void contador_duplo(tp_pilha *p, char string[]){
//     int a = (strlen(string)-1 );
//     tp_item aux;
//     int cont = 0;

//     for(int i = 0; i<a;i++){
//        push(p,string[i]);
//     }

//     for(int j = 0;j<a;j++){
//         pop(p,&aux);
//         if(aux == '('){ // areia basta trocar o <
//             cont++;
//             printf("\ncont- = |%d|\n",cont);
//         }else if(aux == ')'){ // areia basta trocar o >
//             cont--;
//             printf("\ncont- = |%d|\n",cont);
//         }
//     }

//     if(cont == 0){
//         printf("\nCERTO!\n");
//     }else{
//         printf("\nERRADO!\n");
//     }
// };

// int igualdade(tp_pilha *p1, tp_pilha *p2){
//     if(altura_pilha(p1) != altura_pilha){
//         return 0;
//     }else{
//         for(int i = 0; i<altura_pilha(p2);i++){
//             if(p1->item[p1->topo] != p2->item[p2->topo]){
//                 return 0;
//             }else{
//                 return 1;
//             }
//         }
//     }
// }

// void empilha_pilha(tp_pilha *p1, tp_pilha *p2){
//     tp_item e;
//     if(p1->item[p1->topo]<MAX && p2->item[p2->topo] < MAX){
//         while(p2->item[p2->topo] != -1){
//         pop(p2,&e);
//         push(p1,e);
//     }
// }

// FUNÇÕES PROFESSOR

// void retira_impares(tp_pilha *p){
//     tp_pilha paux;
//     inicializa_pilha(&paux);
//     tp_item e;
//     // desempilha a original e armazena apenas os pares na auxiliar
//     while(!pilha_vazia(p)){
//         pop(p,&e);
//         if(e%2==0){
//             push(&paux,e);
//         }
//     }//fim do while

//     while(!pilha_vazia(&paux)){
//         pop(&paux,&e);
//         push(p,e);
//     }
// }

// int pilhas_iguais(tp_pilha p1, tp_pilha p2){
//     tp_item e1,e2;
//     if(altura_pilha(&p1) != altura_pilha(&p2)){
//         return 0
//     }
//     while(!pilha_vazia(&p1)){
//         pop(&p1,&e1);
//         pop(&p2,&e2);
//         if(e1 != e2){
//             return 0;
//         }
//     }
//     return 1;
// }

// int empilha_pilhas(tp_pilha *p1, tp_pilha *p2){
//     tp_item e;
//     tp_pilha paux;
//     inicializa_pilha(&paux);
//     if(altura_pilha(p1)+altura_pilha(p2) > MAX) return 0; // falha
//     while(!pilha_vazia(p2)){
//         pop(p2,&e);
//         push(*paux,e);
//     }
//     while(!pilha_vazia(&paux)){
//         pop(&paux,&e);
//         push(p1,e);
//     }
//     return 1; // success

// }

#endif









































