/**
 * @file main.cpp
 * @author ANGELINA PIERRE (gaptp95@gmail.com)
 * @brief Domino game
 * @version 0.1
 * @date 2021-11-03
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <chrono>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "monte.h"
#include "player.h"
#include "domino.h"
#include "mesa.h"
#include "peca.h" //temporario

using namespace std;
auto start = chrono::steady_clock::now();



int main(){

    printf("\n\n[==============|INI|==============]\n\n");

    // int x; // switch op
    tp_pilha *monte;
    monte = inicializa_pilha();

    // INICIALIZANDO JOGADORES
    tp_player *p1,*p2,*p3,*p4;

    tp_mesa *m;
    p1 = inicializa_players();
    p2 = inicializa_players();
    p3 = inicializa_players();
    p4 = inicializa_players();
    m = inicializa_mesa();

    printf("\nPLAYER 1  = |%s",p1->name);
    printf("\nPLAYER 2  = |%s",p2->name);
    printf("\nPLAYER 3  = |%s",p3->name);
    printf("\nPLAYER 4  = |%s",p4->name);



    gera_pecas(monte);
    embaralha_pecas(monte);

    pega_pecas(monte,p1,p2,p3,p4);

    qtd_pecas(p1,p2,p3,p4);

    imprime_listade(p1->hand,1);

    escolha_pecaini(m, p1);
    printf("\n deu certo \n");
    imprime_listade(m->mesa, 1);
/*
    printf("\n");
    tp_peca x, y, z;
    x.ld1 = 0;
    x.ld2 = 0;
    y.ld1 = 0;
    y.ld2 = 1;
    z.ld1 = 0;
    z.ld2 = 2;



    insert_lde_fim(m->mesa, x);

    if(y.ld2 != x.ld1){
        int aux;
        aux = y.ld2;
        y.ld2 = y.ld1;
        y.ld1 = aux;
    }

   insert_lde_inicio(m->mesa, y);
    //printf("\n |%d|%d| ", m->mesa->ini->info.ld1, m->mesa->ini->info.ld1);
    //printf("|%d|%d|\n", m->mesa->fim->info.ld1, m->mesa->fim->info.ld2);
    insert_lde_fim(m->mesa, z);
    imprime_listade(m->mesa, 1);
    printf("\n|%d|%d| ", m->mesa->ini->info.ld1, m->mesa->ini->info.ld2);
    printf("|%d|%d|\n", m->mesa->fim->info.ld1, m->mesa->fim->info.ld2);

*/

    printf("\n\n[==============|FIM|==============]\n\n");
    cout << "\n";
    cout << "[DURATION]";
    cout << "\n";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    cout << "\n\t";
    return 0;
}
