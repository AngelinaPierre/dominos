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
    imprime_listade(p2->hand,1);
    imprime_listade(p3->hand,1);
    imprime_listade(p4->hand,1);

    switch(ordem_jogo(*p1, *p2, *p3, *p4)){
    	case 1:
    		escolha_peca(m, p1);
    		break;
    	case 2:
    		escolha_peca(m, p2);
    		break;
    	case 3:
    		escolha_peca(m, p3);
    		break;
    	case 4:
    		escolha_peca(m, p4);
    		break;
	}
    int cont=0;
    printf("\n");
    imprime_listade(m->mesa, 1);
    printf("\n");
    while (1) {
        system("cls");
        printf("%d\n", cont);
        imprime_listade(p1->hand,1);
        printf("jog 1\n");
        imprime_listade(m->mesa, 1);
        printf("mesa\n");
        escolha_peca(m, p1);
        system("cls");
        imprime_listade(p2->hand,1);
        printf("jog 2\n");
        imprime_listade(m->mesa, 1);
        printf("mesa\n");
        escolha_peca(m, p2);
        system("cls");
        imprime_listade(p3->hand,1);
        printf("jog 3\n");
        imprime_listade(m->mesa, 1);
        printf("mesa\n");
        escolha_peca(m, p3);
        system("cls");
        imprime_listade(p4->hand,1);
        printf("jog 4\n");
        imprime_listade(m->mesa, 1);
        printf("mesa\n");
        escolha_peca(m, p4);
        cont++;
    }

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
