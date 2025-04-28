#ifndef PESSOAS_H
#define PESSOAS_H
#include <iostream>
#include "fila.h"
using namespace std;

struct torcedor
{
    string nome;
    int unidadesTempo;
};

void criaTorcedor(torcedor &a, int &qnt)
{
    string nomeCliente = "Torcedor " + to_string(qnt);
    a.nome = nomeCliente;
    qnt++; // Incrementa para o próximo
    a.unidadesTempo = rand()%2;
}

struct socioTorcedor{
    string nome;
    int unidadesTempo;
};

void criaSocioTorcedor(socioTorcedor &a, int &qnt){
    string nomeCliente = "Socio_torcedor " + to_string(qnt);
    a.nome = nomeCliente;
    qnt++; // Incrementa para o próximo
    a.unidadesTempo = rand()%3;
}
#endif