/**
 * @file C-template.cpp
 * @author ANGELINA PIERRE (gaptp95@gmail.com)
 * @brief Main() for the Dominos promject of AED1
 * @version 0.1
 * @date 2021-11-12
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
#include "lista_de.h"
#include "domino.h"
#include "pilha.h"
using namespace std;
auto start = chrono::steady_clock::now();


int main(){

    printf("\n\n[==============|INI|==============]\n\n");

    tp_listade table,player_1, player_2;
    tp_pilha boneyard;

    



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