#ifndef FILA_H
#define FILA_H
#include <iostream>

using namespace std;

template <typename TIPO>
struct item
{
    TIPO dado;
    item *proximo;
};

template <typename TIPO>
struct Tfila
{
    item<TIPO> *inicio;
    int quantidade;
};
template <typename TIPO>
void inicializaFila(Tfila<TIPO> &queue)
{
    queue.inicio = NULL;
}
template <typename TIPO>
bool entrar_na_fila(Tfila<TIPO> &x, TIPO novo)
{

    item<TIPO> *novoitem = new item<TIPO>;
    novoitem->dado = novo;
    novoitem->proximo = NULL;

    if (x.inicio == NULL)
    {
        x.inicio = novoitem;
        x.quantidade++;
    }
    else
    {
        item<TIPO> *aux = x.inicio;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novoitem;
        x.quantidade++;

        return true;
    }
    return false;
}
template <typename TIPO>
TIPO atender(Tfila<TIPO> &fila)
{
    TIPO dado;
    if (fila.inicio == NULL)
    {
        cout << "Fila vazia";
    }
    else
    {
        item<TIPO> *remover = fila.inicio;
        dado = remover->dado;
        fila.inicio = fila.inicio->proximo;
        delete remover;
        return (dado);
    }
}

template <typename TIPO>
TIPO primeiro(Tfila<TIPO> fila){
    return fila.inicio;
}
#endif