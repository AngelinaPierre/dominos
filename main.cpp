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

using namespace std;
auto start = chrono::steady_clock::now();

int main(){

    printf("\n\n[==============|INI|==============]\n\n");

    // int x; // switch op
    tp_pilha *monte;
    monte = inicializa_pilha();

    // INICIALIZANDO JOGADORES
    tp_player *p1,*p2,*p3,*p4;
    // pp1 = &p1;
    // pp2 = &p2;
    // pp3 = &p3;
    // pp4 = &p4;

    inicializa_players(p1,p2,p3,p4);

    printf("PLAYER 1  = |%s",p1->name);
    printf("PLAYER 2  = |%s",p2->name);
    printf("PLAYER 3  = |%s",p2->name);
    printf("PLAYER 4  = |%s",p4->name);


    // teste LDE PARA MAO
    // tp_listade *hand;
    // hand = inicializa_lde();
    // insert_lde_fim(hand,10);
    // insert_lde_fim(hand,20);
    // insert_lde_fim(hand,30);
    // insert_lde_fim(hand,40);
    // imprime_listade(hand,1);
    // remove_listade(hand,20);
    // remove_listade(hand,30);
    // imprime_listade(hand,1);
    // destroi_listade(hand);
    

    // teste pilha
    // push(monte,10);
    // push(monte,20);
    // push(monte,30);

    // tpi_monte e;
    gera_pecas(monte);
    embaralha_pecas(monte);
    imprime_pilha(*monte);
    // pop(monte,&e);
    // printf("\\n\t\t|%d|",e);

    // push(monte,40);

    // destroi(monte);



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
