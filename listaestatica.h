// Alunos: Andre Felipe Guimaraes Herzfeld, Rafael Mehrle Kraemer e Thiago Fernandes Jacques
#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include <iostream>
using namespace std;

template <typename tipo>
struct itens
{

    tipo dado;
};

template <typename tipo, int max>
struct TLISTA
{

    itens<tipo> elementos[max];
    int quantidade;
};

template <typename tipo, int max>
bool inserir_elemento_fim(TLISTA<tipo, max> &x, tipo novo)
{

    if (x.quantidade < max)
    {
        itens<tipo> novoElemento;
        novoElemento.dado = novo;
        x.elementos[x.quantidade] = novoElemento;
        x.quantidade++;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool inserir_elemento_inicio(TLISTA<tipo, max> &x, tipo novo)
{

    if (x.quantidade < max)
    {
        itens<tipo> novoElemento;
        novoElemento.dado = novo;
        for (int i = x.quantidade; i > 0; i--)
        {

            x.elementos[i] = x.elementos[i - 1]; // Move todos elementos navegando pelo vetor da direita para a esquerda, os movendo em direcao a ultima posicao do vetor
        }

        x.elementos[0] = novo;
        x.quantidade++;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool inserir_elemento_posicao(TLISTA<tipo, max> &x, tipo novo, int posicao)
{

    if (x.quantidade < max && posicao <= x.quantidade)
    {
        itens<tipo> novoElemento;
        novoElemento.dado = novo;

        for (int i = x.quantidade; i > posicao; i--)
        {
            x.elementos[i] = x.elementos[i - 1];
        }

        x.elementos[posicao] = novoElemento;
        x.quantidade++;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool remover_elemento_fim(TLISTA<tipo, max> &x)
{

    if (x.quantidade > 0)
    {

        x.quantidade--;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool remover_elemento_inicio(TLISTA<tipo, max> &x)
{

    if (x.quantidade > 0)
    {

        for (int i = 0; i < (x.quantidade - 1); i++)
        {
            x.elementos[i] = x.elementos[i + 1];
        }

        x.quantidade--;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool remover_elemento_posicao(TLISTA<tipo, max> &x, int posicao)
{

    if (x.quantidade > 0 && posicao < x.quantidade && posicao > (-1))
    {

        for (int i = posicao; i < (x.quantidade - 1); i++)
        {
            x.elementos[i] = x.elementos[i + 1];
        }

        x.quantidade--;
        return true;
    }

    return false;
}

template <typename tipo, int max>
bool bubblesort(TLISTA<tipo, max> &x)
{

    int i, j, cond;
    itens<tipo> temp;

    for (i = max - 1; i >= 1 && (cond == 1); i--)
    {
        cond = 0;
        for (j = 0; j < i; j++)
        {
            if (x.elementos[j] > x.elementos[j + 1])
            {
                temp = x.elementos[j];
                x.elementos[j] = x.elementos[j + 1];
                x.elementos[j + 1] = temp;
                cond = 1;
            }
        }
    }
}

template <typename tipo, int max>
void quicksort(TLISTA<tipo, max> &x, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int pi = particiona(x, direita, esquerda);

        quicksort(x, esquerda, pi - 1); // cria o lado esquerdo
        quicksort(x, pi + 1, direita);  // cria o lado direito
    }
}

template <typename tipo, int max>
int particiona(TLISTA<tipo, max> &x, int high, int low)
{
    tipo pivo = x.elementos[high].dado; // Faz o pivo ser o ultimo elemento
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (x.elementos[j].dado < pivo) // compara o dado na posicao J com o Pivo
        {
            i++;
            swap(x.elementos[i], x.elementos[j]); // usando swap pra nao precisar colocar variavel temporaria no codigo
        }
    }
    swap(x.elementos[i + 1], x.elementos[high]);
    return i + 1;
}

#endif