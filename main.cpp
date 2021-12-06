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
#include <locale.h>
#include "monte.h"
#include "player.h"
#include "domino.h"
#include "mesa.h"

using namespace std;
auto start = chrono::steady_clock::now();

int main(){
	setlocale(LC_ALL, "Portuguese");
    printf("\n\n[==============|START|==============]\n\n");


    int vez, vencedor=0, pc0=8, pc1=8, pc2=8, pc3=8, pc4=8, pc5=8, pc6=8;
    // int x; // switch op
    tp_pilha *monte;
    monte = inicializa_pilha();

    // INICIALIZANDO JOGADORES
    tp_player *p1,*p2,*p3,*p4;

    tp_mesa *m;
    printf("PLAYER 1, DIGITE SEU NOME: ");
    p1 = inicializa_players();
    printf("\nPLAYER 2, DIGITE SEU NOME: ");
    p2 = inicializa_players();
    printf("\nPLAYER 3, DIGITE SEU NOME: ");
    p3 = inicializa_players();
    printf("\nPLAYER 4, DIGITE SEU NOME: ");
    p4 = inicializa_players();
    m = inicializa_mesa();

    //printf("\nPLAYER 1  = |%s",p1->name);
    //printf("\nPLAYER 2  = |%s",p2->name);
    //printf("\nPLAYER 3  = |%s",p3->name);
    //printf("\nPLAYER 4  = |%s",p4->name);

    gera_pecas(monte);
    embaralha_pecas(monte);

    pega_pecas(monte,p1,p2,p3,p4);
    system("cls");
    printf("JOGADORES %s, %s, %s E %s, PREPAREM-SE PARA A PARTIDA!\n\n", p1->name, p2->name, p3->name, p4->name);
    printf("JOGADORES, PARA SELECIONAR A PEDRA, SELECIONE O NÚMERO CORRESPONDENTE A ORDEM\nEM QUE A PEDRA ESTÁ INSERIDA NA SUA MÃO!\n\n");
    printf("O JOGO ACABA QUANDO UM JOGADOR USAR TODAS AS PEDRAS QUE TINHA EM SUA MÃO!\n\n");
    printf("CASO O JOGO FIQUE EM UMA POSIÇÃO QUE NENHUM JOGADOR PODE JOGAR, VENCE O JOGADOR QUE\nTIVER O MENOR NÚMERO AO SOMAR AS PEDRAS RESTANTES!\n\n");
    printf("PRIMEIRO JOGADOR, LEMBRE-SE QUE VOCÊ DEVE COMEÇAR USANDO A BUCHA DE QUINA |5|5|!!\n\n");
    system("pause");
    vez = ordem_jogo(*p1, *p2, *p3, *p4);

    while (vencedor != 1) {
        int aux1 = 8, aux2 = 8;
        system("cls");
        //printf(" %d %d %d %d %d %d %d\n", pc0, pc1, pc2, pc3, pc4, pc5, pc6);
        qtd_pecas(p1,p2,p3,p4);
        //printf("%d\n", vencedor);
        switch(vez){
        	case 1:
                inserir_peca_na_mesa(m, p1, &aux1, &aux2);
                verificar_vencedor(p1, &vencedor);
                vez = 2;
        		break;
        	case 2:
                inserir_peca_na_mesa(m, p2, &aux1, &aux2);
                verificar_vencedor(p2, &vencedor);
                vez = 3;
        		break;
        	case 3:
                inserir_peca_na_mesa(m, p3, &aux1, &aux2);
                verificar_vencedor(p3, &vencedor);
                vez = 4;
        		break;
        	case 4:
                inserir_peca_na_mesa(m, p4, &aux1, &aux2);
                verificar_vencedor(p4, &vencedor);
                vez = 1;
        		break;
    	}
        if (vencedor == 0){
            system("cls");
            printf("mesa\n");
            imprime_listade(m->mesa, 1);
            vencedor = verifica_num_pecas_jogo(aux1, aux2, &pc0, &pc1, &pc2, &pc3, &pc4, &pc5, &pc6, m);
        }
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
