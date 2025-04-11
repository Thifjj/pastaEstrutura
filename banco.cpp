#include <iostream>
#include "Fila.h"
#include <time.h>
using namespace std;
struct pessoa
{
    string nome;
    int quantidade_boleto;
};

int main()
{
    srand(time(nullptr));

    Tfila<pessoa> guiche;
    inicializaFila(guiche);
    for (int i = 1; i <= 5; i++)
    {
        pessoa pessoaInserir;
        pessoaInserir.nome = "Cliente " + to_string(i);
        pessoaInserir.quantidade_boleto = rand() % 3 + 1;
        queue(guiche, pessoaInserir);
    }
    int contUnidadesTempoTotais = 0;
    while (guiche.inicio != NULL)
    {
        pessoa atual = dequeue(guiche);
        while (atual.quantidade_boleto > 0)
        {
            cout << atual.nome << " Em atendimento com " << atual.quantidade_boleto << endl;
            contUnidadesTempoTotais++;
            atual.quantidade_boleto--;
        }
        cout << atual.nome << " Atendido " << endl << endl;
    }
    cout<<"Quantidade de execucoes: "<<contUnidadesTempoTotais<<endl;
}