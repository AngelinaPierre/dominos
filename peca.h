#ifndef PECA_H
#define PECA_H

#include <stdio.h>
#include <stdlib.h>
// #include "monte.h"

typedef struct{
    int ld1,ld2;
}tp_peca;




/**
 * @brief CRIAR: soma_peca();
 *
 */

int soma_peca(tp_peca p){
    return p.ld1 + p.ld2;
}

#include "monte.h"
#include "pedra_lde_m.h"



#endif
