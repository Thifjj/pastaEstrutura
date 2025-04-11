#include <iostream>

using namespace std;

template <typename TIPO>
struct Telemento
{
    TIPO dado;
    Telemento<TIPO> *proximo;
};

template <typename TIPO>
struct Tlista
{
    Telemento<TIPO> *inicio;
    int quantidade;
};
template <typename TIPO>
void inicializaLista(Tlista<TIPO> &lista)
{
    lista.inicio = NULL;
}
template <typename TIPO>
void InsereInicioCircular(Tlista<TIPO> &lista, TIPO dado)
{
    Telemento<TIPO> *novoElemento = new Telemento<TIPO>;
    novoElemento->dado = dado;
    novoElemento->proximo = NULL;

    if (lista.inicio == NULL)
    {
        novoElemento->proximo = novoElemento;
        lista.inicio = novoElemento;
        lista.quantidade++;
    }
    else
    {
        lista.inicio->proximo = novoElemento;
        novoElemento->proximo = lista.inicio;
        lista.inicio = novoElemento;
    }
}
template <typename TIPO>
void insereFinalCircular(Tlista<TIPO> &lista, TIPO dado)
{
    Telemento<TIPO> *novoElemento = new Telemento<TIPO>;
    novoElemento->dado = dado;
    novoElemento->proximo = lista.inicio;

    if (lista.inicio == NULL)
    {
        novoElemento->proximo = novoElemento;
        lista.inicio = novoElemento;
        lista.quantidade++;
    }
    else
    {
        Telemento<TIPO> *nav = lista.inicio;
        while (nav->proximo != lista.inicio)
        {
            nav = nav->proximo;
        }
        nav->proximo = novoElemento;
        lista.quantidade++;
    }
}

template <typename TIPO>
void inserePosicaoCircular(Tlista<TIPO> &lista, TIPO dado, int pos)
{
    Telemento<TIPO> *novoElemento = new Telemento<TIPO>;
    novoElemento->dado = dado;
    novoElemento->proximo = NULL;

    if (pos == 0)
    {
        lista.inicio->proximo = novoElemento;
        novoElemento->proximo = lista.inicio;
        lista.inicio = novoElemento;
    }
    else if (pos < 0)
    {
        cout << "Posicao Invalida!" << endl;
    }
    else
    {
        if (lista.inicio == NULL)
        {
            novoElemento->proximo = lista.inicio;
            lista.inicio = novoElemento;
            lista.quantidade++;
        }
        else
        {
            int i = 0;
            Telemento<TIPO> *aux = lista.inicio;
            while (aux->proximo != lista.inicio && i < pos - 1)
            {
                aux = aux->proximo;
                i++;
            }
            novoElemento->proximo = aux->proximo
                                        aux->proximo = novoElemento;
            lista.quantidade++;
        }
    }
}

template <typename TIPO>
void removeInicio(Tlista<TIPO> &lista)
{
    if (lista.quantidade == 0 && lista.inicio == NULL)
    {
        cout << "A lista esta vazia" << endl;
    }
    else
    {
        Telemento<TIPO> *aux = lista.inicio;
        if (lista.inicio == lista.inicio->proximo)
        {
            lista.inicio = NULL;
        }
        else
        {
            while (aux->proximo != lista.inicio)
            {
                aux = aux->proximo;
            }
            lista.inicio = lista.inicio->proximo;
            aux->proximo = lista.inicio;
        }
    }
    lista.quantidade--;
}

template <typename TIPO>
void removeFim(Tlista<TIPO> &lista)
{
    if (lista.quantidade == 0 && lista.inicio == NULL)
    {
        cout<<"A lista esta vazia nao e possivel remover"<<endl;
    }
    else
    {
        if (lista.inicio == lista.inicio->proximo)
        {
            lista.inicio = NULL;
        }
        else
        {
            Telemento<TIPO> *aux = lista.inicio;
            while (aux->proximo->proximo != lista.inicio)
            {
                aux = aux->proximo;
            }
            aux->proximo = lista.inicio;
        }
    }
    lista.quantidade--;
}