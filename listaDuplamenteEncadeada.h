#include <iostream>

using namespace std;

template <typename TIPO>
struct Telemento
{
    TIPO dado;
    Telemento<TIPO> *proximo;
    Telemento<TIPO> *anterior;
};
template <typename TIPO>
struct Lista
{
    Telemento<TIPO> *inicio;
    Telemento<TIPO> *final;
};

template <typename TIPO>
void inicializaLista(Lista<TIPO> &list)
{
    list.inicio = NULL;
    list.final = NULL;
}

template <typename TIPO>
void inserirInicio(Lista<TIPO> &list, TIPO dado)
{
    if (list.inicio != NULL)
    {
    }
    else
    {
        Telemento<TIPO> *aux = new Telemento<TIPO>;
        aux->dado = dado;
        aux->proximo = NULL;
        aux->anterior = NULL;
        list.inicio = aux;
    }
};