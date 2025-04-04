// Alunos: Andre Felipe Guimaraes Herzfeld, Rafael Mehrle Kraemer e Thiago Fernandes Jacques
#ifndef LISTADUPLAMENTE_INCLUDED
#define LISTADUPLAMENTE_INCLUDED

#include <iostream>

using namespace std;

template <typename TIPO>
struct TElemento
{

    TIPO dado;
    TElemento<TIPO> *prox;
    TElemento<TIPO> *ant;
};

template <typename TIPO>
struct TLista
{

    TElemento<TIPO> *inicio;
    TElemento<TIPO> *final;
};

template <typename TIPO>
bool Inserir_inicio(TLista<TIPO> &Lista, TIPO Inserido)
{

    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo.dado = Inserido;
    novo->prox = NULL;
    novo->ant = NULL;

    if (Lista.inicio == NULL)
    { // Se a lista ta vazia
        Lista.inicio = novo;
        Lista.final = novo;
        return true;
    }

    else
    { // Se ja tiver algo na lista
        novo->Prox = lista.inicio;
        Lista.inicio = novo;
    }
};

template <typename TIPO>
bool Inserir_fim(TLista<TIPO> &Lista, TIPO Inserido)
{

    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo.dado = Inserido;
    novo->prox = NULL;
    novo->ant = NULL;

    if (Lista.inicio == NULL)
    {
        Lista.inicio = novo;
        Lista.final = novo;
        return true;
    }

    else
    {
        novo->ant = Lista.final;  // Faz o *anterior do novo apontar pra onde o lista final esta apontando(ultimo elemento)
        Lista.final->prox = novo; // Faz o *prox do ultimo elemento apontar pro novo
        Lista.final = novo;       // auto explicativo
        return true;
    }
};

template <typename TIPO>
bool Inserir_pos(TLista<TIPO> &Lista, TIPO Inserido, int pos)
{

    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo.dado = Inserido;
    novo->prox = NULL;
    novo->ant = NULL;
    TElemento<TIPO> *atual = Lista.inicio;

    if (Lista.inicio == NULL)
    {
        Lista.inicio = novo;
        Lista.final = novo;
        return true;
    }

    else
    {
        int i = 0;
        while(atual->prox != null && i<pos-1)
        { // faz com que o ponteiro pare na posição anterior a POS
                atual = atual->prox;
            i++;
        }

        novo->prox = atual->prox; //
        novo->ant = atual;
        atual->prox = novo;
        novo->prox->ant = novo;
        return true;
    }
};

template <typename TIPO>
bool Remover_inicio(TLista<TIPO> &Lista)
{

    if (Lista.inicio == NULL)
    { // Lista vazia nao da pra remover nada
        return false;
    }
    else
    {
        TElemento<TIPO> *temp = Lista.inicio; // criando variavel temporaria pra poder excluir depois
        Lista.inicio = Lista.inicio->prox;
        Lista.inicio->ant = NULL;
        delete temp;
        return true;
    }
};

template <typename TIPO>
bool Remover_fim(TLista<TIPO> &Lista)
{

    if (Lista.inicio == NULL)
    { // Lista vazia nao da pra remover nada
        return false;
    }

    else
    {
        TElemento<TIPO> *temp = Lista.final;
        Lista.final = Lista.final->prox;
        Lista.final->prox = NULL;
        delete temp;
        return true;
    }
}

template <typename TIPO>
bool Remover_pos(TLista<TIPO> &Lista, int pos)
{
    TElemento<TIPO> *atual;
    TElemento<TIPO> *tras;
    TElemento<TIPO> *frente;

    if (Lista.inicio == NULL)
    { // Lista vazia nao da pra remover nada
        return false;
    }

    else
    {
        int i = 0;
        while(atual->prox != NULL && i<pos-1)
        {
            atual = atual->prox;
            i++
        }
        tras = atual->ant;
        frente = atual->prox; // configuração dos ponteiros

        tras->prox = frente; // faz com que o atual(posição que queremos remover) nao seja apontado por ninguem
        frente->ant = tras;
        delete atual;
        return true;
    }
}

template <typename TIPO>
void bubblesort(TLista<TIPO> &Lista)
{

    int i, j, cond;
    TIPO tempDado;
    TElemento<TIPO> *aux;

    for (i = (Lista.quantidade - 1); (i >= 1) && (cond == 1); i--)
    {
        cond = 0;
        aux = Lista.inicio;

        for (j = 0; j < i; j++)
        {
            if (aux->dado > aux->prox->dado)
            {
                tempDado = aux->dado;
                aux->dado = aux->prox->dado;
                aux->prox->dado = tempDado;
                cond = 1;
            }
            aux = aux->prox;
        }
    }
}

template <typename TIPO>
TElemento<TIPO> particiona(TElemento<TIPO> *inicio, TElemento<TIPO> *final) // função pra dividir a lista em duas
{
    TIPO pivo = final->dado;
    TElemento<TIPO> *i = inicio->ant;
    for (TElemento<TIPO> *j = inicio; j != final; j = j->proximo)
    {
        if (j->dado < pivo)
        {
            // ocorre a troca dos menores que o pivo para a esquerda assim ficando os maiores a direita
            i = i->proximo;
            TIPO temp = i->dado;
            i->dado = j->dado;
            j->dado = temp;
        }
    }
    // traz o pivo (ultimo da lista no caso) para a posicao certa
    i = i->proximo;
    TIPO temp = final->dado;
    final->dado = i->dado;
    i->dado = temp;
    return (i);
}
template <typename TIPO>
void quicksort(TElemento<TIPO> *inicio, TElemento<TIPO> *final)
{
    // condicao para funcionar e parada de recursividade
    if (final != NULL && inicio != final && inicio != final->proximo)
    // cond 1 final = null ou esta vazia ou ja percorreu todos elementos
    // inicio != final caso eles sejam iguais ja esta ordenado (tem somente um elemento na lista)
    // impede que inicio ultrapasse o final (significa que inicio ja passou final e nao tem mais nada para ordenar)
    {
        // p vira a posicao que o pivo esta e apartir dele fazemos os "sorts" por 2 partes a de maiores que ele e a dos menores
        Telemento<TIPO> *p = particiona(inicio, final);
        // divide do inicio ate o antecessor do pivo
        quicksort(inicio, p->anterior);
        // divide do depois do pivo ate o final da lista
        quicksort(p->proximo, final);
    }
}

#endif