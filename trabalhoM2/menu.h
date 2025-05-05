#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
#include "pessoas.h"
#include "fila.h"
using namespace std;
void esperaEnter()
{
    cout << "Aperte ENTER para continuar!!" << endl;
    cin.get();
}

template <typename TIPO>
int verificaMenor(Tfila<TIPO> fila[], int qntMAX)
{
    int menorI = 0;
    menor = fila[0].quantidade;
    for (int i = 1; i < qntMAX; i++)
    {
        if (menor < fila[i].quantidade)
        {
            menorI = i;
        }
    }
    return menorI;
}

void menu(int qntGuiches_Socio, int qntGuiches_Torcedor, int qntP_antes, int qntP_procuraPorTempo, int qntTempoSimulado)
{
    Tfila<torcedor> GuichesTorcedor[qntGuiches_Torcedor];
    Tfila<socioTorcedor> GuichesSocio[qntGuiches_Socio];
    torcedor a;
    socioTorcedor b;
    int qntSocios = 0;
    int qntTorcedor = 0;

    // Calcula quantos devem ser sócios (5%)
    int numSocios = qntP_antes * 5 / 100;
    int numTorcedores = qntP_antes - numSocios;

    // Inicializa o gerador de números aleatórios apenas uma vez
    srand(time(0));

    // Cria os sócios
    for (int i = 0; i < numSocios; i++)
    {
        criaSocioTorcedor(b, qntSocios);
        entrar_na_fila(GuichesSocio[verificaMenor(GuichesSocio, qntGuiches_Socio)], b);
        qntSocios++;
    }

    // Cria os torcedores normais
    for (int i = 0; i < numTorcedores; i++)
    {
        criaTorcedor(a, qntTorcedor);
        entrar_na_fila(GuichesTorcedor[verificaMenor(GuichesTorcedor, qntGuiches_Torcedor)], a);
        qntTorcedor++;
    }
}

#endif