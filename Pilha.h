#ifndef PILHA_H
#define PILHA_H
#include <iostream>

using namespace std;

template <typename TIPO>
struct Titem
{
    TIPO dado;
    Titem *proximo;
};

template <typename TIPO>
struct TPilha
{
    Titem<TIPO> *primeiro;
    int quantidade;
};

template <typename TIPO>
void inicializaPilha(TPilha<TIPO> &pilha)
{
    pilha.primeiro = NULL;
}
template <typename TIPO>
bool inserir_Titem_primeiro(TPilha<TIPO> &x, TIPO novo)
{

    Titem<TIPO> *novoTitem = new Titem<TIPO>;
    novoTitem->dado = novo;
    novoTitem->proximo = NULL;

    if (x.primeiro == NULL)
    {
        x.primeiro = novoTitem; // No caso de nao haver nenhum Titem, o primeiro aponta para o primeiro Titem
        x.quantidade++;
        return true;
    }
    else
    {

        novoTitem->proximo = x.primeiro; // Ponteiro do novo Titem dinamico recebe o endereÃ§o que esta contido no ponteiro que aponta para o agora antigo primeiro Titem da TPilha
        x.primeiro = novoTitem;          // primeiro agora aponta para o endereco do novo Titem atraves do ponteiro que aponta pra o Titem dinamico, que possui o seu endereco

        x.quantidade++;

        return true;
    }

    return false;
}

template <typename TIPO>
TIPO remover_Titem_primeiro(TPilha<TIPO> &x)
{
    if (x.quantidade == 0)
    {
        return false;
    }
    Titem<TIPO> *removido = x.primeiro;
    if (x.primeiro->proximo == NULL)
    {
        delete removido;
        x.primeiro = NULL;
        x.quantidade--;
        return true;
    }

    x.primeiro = x.primeiro->proximo;
    TIPO dado = removido->dado;
    delete removido;
    x.quantidade--;

    return dado;
}

#endif