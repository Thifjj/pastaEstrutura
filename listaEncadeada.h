// Alunos: Andre Felipe Guimaraes Herzfeld, Rafael Mehrle Kraemer e Thiago Fernandes Jacques
#ifndef LISTA_SIMPLESMENTE_ENCADEADA_H
#define LISTA_SIMPLESMENTE_ENCADEADA_H
#include <iostream>

using namespace std;

template <typename tipo>
struct elemento
{

    tipo dado;
    elemento *proximo;
};

template <typename tipo>
struct lista
{

    elemento<tipo> *inicio;
    int quantidade;
};

template <typename tipo>
bool inserir_elemento_final(lista<tipo> &x, tipo novo)
{

    elemento<tipo> *novoElemento = new elemento<tipo>;
    novoElemento->dado = novo;
    novoElemento->proximo = NULL;

    if (x.inicio == NULL)
    {
        x.inicio = novoElemento;
        x.quantidade++;
    }
    else
    {
        elemento<tipo> *aux = x.inicio;
        while (aux->proximo != NULL)
        {
            aux->proximo = aux->proximo->proximo;
        }
        aux->proximo = novoElemento;
        x.quantidade++;

        return true;
    }
    return false;
}

template <typename tipo>
bool inserir_elemento_inicio(lista<tipo> &x, tipo novo)
{

    elemento<tipo> *novoElemento = new elemento<tipo>;
    novoElemento->dado = novo;
    novoElemento->proximo = NULL;

    if (x.inicio == NULL)
    {
        x.inicio = novoElemento; // No caso de nao haver nenhum elemento, o inicio aponta para o primeiro elemento
        x.quantidade++;
        return true;
    }
    else
    {

        novoElemento->proximo = x.inicio; // Ponteiro do novo elemento dinamico recebe o endereÃ§o que esta contido no ponteiro que aponta para o agora antigo primeiro elemento da lista
        x.inicio = novoElemento;          // Inicio agora aponta para o endereco do novo elemento atraves do ponteiro que aponta pra o elemento dinamico, que possui o seu endereco

        x.quantidade++;

        return true;
    }

    return false;
}

template <typename tipo>
bool inserir_elemento_posicao(lista<tipo> &x, tipo novo, int posicao)
{

    elemento<tipo> *novoElemento = new elemento<tipo>;
    novoElemento->dado = novo;
    novoElemento->proximo = NULL;

    if (posicao > (x.quantidade + 1))
    {
        return false; // Cancela a insercao por conta da impossibilidade de inserir um elemento em uma posicao separada das demais ja inseridas
    }

    if (x.inicio == NULL)
    {
        x.inicio = novoElemento;
        novoElemento->proximo = NULL;
        x.quantidade++;
        return true;
    }

    if (posicao <= x.quantidade && posicao > -1 && x.inicio != NULL)
    {
        int cont = 0;
        elemento<tipo> *aux;
        elemento<tipo> *fin;

        while (cont < posicao)
        {
            if (cont == 0)
            {
                aux = x.inicio;
                cont++;
            }
            else
            {
                aux = aux->proximo;
                cont++;
            }
        }

        fin = aux->proximo;
        aux->proximo = novoElemento;
        novoElemento->proximo = fin;

        x.quantidade++;

        return true;
    }
}

template <typename tipo>
bool remover_elemento_final(lista<tipo> &x)
{

    if (x.quantidade == 0)
    {
        return false;
    }

    elemento<tipo> *aux = x.inicio;
    elemento<tipo> *removido;
    elemento<tipo> *aux2 = x.inicio;

    if (x.inicio->proximo == NULL)
    {
        removido = x.inicio;
        delete removido;
        x.inicio = NULL;
        x.quantidade--;
        return true;
    }

    while (aux->proximo != NULL)
    {
        aux2 = aux;
        aux = aux->proximo;
    }

    removido = aux;
    delete removido;
    aux2->proximo = NULL;
    x.quantidade--;

    return true;
}

template <typename tipo>
bool remover_elemento_inicio(lista<tipo> &x)
{

    if (x.quantidade == 0)
    {
        return false;
    }

    elemento<tipo> *removido = x.inicio;

    if (x.inicio->proximo == NULL)
    {
        delete removido;
        x.inicio = NULL;
        x.quantidade--;
        return true;
    }

    x.inicio = x.inicio->proximo;
    delete removido;
    x.quantidade--;
    return true;
}

template <typename tipo>
bool remover_elemento_posicao(lista<tipo> &x, int posicao)
{

    if (x.quantidade == 0)
    {
        return false;
    }

    elemento<tipo> *removido = x.inicio;

    if (x.inicio->proximo == NULL)
    {
        delete removido;
        x.inicio = NULL;
        x.quantidade--;
        return true;
    }

    if (posicao > x.quantidade)
    {
        return false;
    }

    if (posicao <= x.quantidade && posicao > -1)
    {

        elemento<tipo> *aux = x.inicio;
        elemento<tipo> *aux2 = x.inicio;

        while (cont < posicao)
        {
            aux2 = aux;
            aux = aux->proximo;
            cont++
        }

        removido = aux;
        aux = aux->proximo;
        aux2->proximo = aux;
        delete removido;
        x.quantidade--;
        return true;
    }
}

template <typename tipo>
void bubblesort(lista<tipo> &x)
{
    int i, j, cond;
    tipo tempDado;
    elemento<tipo> *aux;

    for (i = (x.quantidade - 1); (i >= 1) && (cond == 1); i--)
    {
        cond = 0;
        aux = x.inicio;

        for (j = 0; j < i; j++)
        {
            if (aux->dado > aux->proximo->dado)
            {
                tempDado = aux->dado;
                aux->dado = aux->proximo->dado;
                aux->proximo->dado = tempDado;
                cond = 1;
            }
            aux = aux->proximo;
        }
    }
}

template <typename tipo>
void quicksort(elemento<tipo> *inicio, elemento<tipo> *fim)
{
    if (inicio != NULL && inicio != fim && inicio != fim->proximo) // verifica se esta vazio, se tem 2 pelo menos e se o inicio nao passou do fim
    {
        elemento<tipo> *pivo = particiona(inicio, fim);

        elemento<tipo> *aux = inicio;
        while (aux != pivo) // percorre a lista desde o inicio ate achar o anterior do pivo
        {
            aux = aux->proximo;
        }
        // quick da esquerda
        if (aux != NULL) // Se o anterior do pivo for NULL o pivo e o primeiro elemento do subarray
        {
            quicksort(inicio, aux); // tem que ser o anterior do pivo porque senao o pivo vai ser incluido denovo na lista
        }

        // quick da direita
        quicksort(pivo->proximo, fim); // mesmo motivo do da esquerda so que nos temos o ponteiro do proximo do pivo ja
    }
}

template <typename tipo>
elemento<tipo> *particiona(elemento<tipo> *inicio, elemento<tipo> *fim)
{
    tipo pivo = fim->dado;
    elemento<tipo> *i = inicio;
    elemento<tipo> *j = inicio;

    while (j != fim)
    {
        if (j->dado < pivo)
        {
            swap(i->dado, j->dado); // troca i com J
            i = i->proximo;
        }
        j = j->proximo;
    }

    swap(i->dado, fim->dado); // troca o I com o Pivo deixando o pivo no lugar certo

    return i; // Retorna o ponteiro que aponta para onde o pivo deve estar
}

#endif