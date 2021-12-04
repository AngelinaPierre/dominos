#ifndef MESA_H
#define MESA_H

#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "player.h"
#include "pedra_lde_m.h"

typedef struct{
    tp_listade *mesa;
}tp_mesa;

// função para iniciar a mão quando for pegar a peça no monte

tp_mesa *aloca_mesa(){
    tp_mesa *nova_mesa;
    nova_mesa = (tp_mesa *)malloc(sizeof(tp_mesa));
    if(nova_mesa == NULL){
        printf("\n|MESA NOT ALLOCATED|\n");
    }
    //novo_player->name = (char *)malloc(sizeof(char));

    nova_mesa->mesa = inicializa_lde();
    return nova_mesa;
}

tp_mesa *inicializa_mesa(){
    // alocando a mesa
    tp_mesa *m = aloca_mesa();

    printf("\n Mesa alocada \n");

    return m;
}

#endif
