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

    int vez, vencedor=0;
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
    system("cls");
    vez = ordem_jogo(*p1, *p2, *p3, *p4);

    while (vencedor != 1) {
        system("cls");
        qtd_pecas(p1,p2,p3,p4);
        printf("%d\n", vencedor);
        switch(vez){
        	case 1:
                inserir_peca_na_mesa(m, p1);
                verificar_vencedor(p1, &vencedor);
                vez = 2;
        		break;
        	case 2:
                inserir_peca_na_mesa(m, p2);
                verificar_vencedor(p2, &vencedor);
                vez = 3;
        		break;
        	case 3:
                inserir_peca_na_mesa(m, p3);
                verificar_vencedor(p3, &vencedor);
                vez = 4;
        		break;
        	case 4:
                inserir_peca_na_mesa(m, p4);
                verificar_vencedor(p4, &vencedor);
                vez = 1;
        		break;
    	}
    }

    printf("deu certo\n");
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
