#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <iostream>

using namespace std;

template <typename TIPO>
struct TNo
{
    TIPO dado;
    int chave;
    TNo<TIPO> *direita;
    TNo<TIPO> *esquerda;
};

template <typename TIPO>
struct TArvore
{
    TNo<TIPO> *raiz;
};

template <typename TIPO>
void inicializaArvore(TArvore<TIPO> &arvore)
{
    arvore.raiz = NULL; // Apenas inicializa a raiz como NULL
};

template <typename TIPO>
void insereArvore(TNo<TIPO> *&no, TIPO dado, int chave)
{
    if (no == NULL)
    {
        no = new TNo<TIPO>;
        no->dado = dado;
        no->chave = chave;
        no->direita = NULL;
        no->esquerda = NULL;
    }
    else
    {
        if (chave > no->chave)
        {
            insereArvore(no->direita, dado, chave);
        }
        else
        {
            if (chave < no->chave)
            {
                insereArvore(no->esquerda, dado, chave);
            }
        }
    }
};

template <typename TIPO>
void caminhamentoPRE(TNo<TIPO> *no)
{
    if (no != NULL)
    {
        // Pré-ordem: visita a raiz, depois esquerda, depois direita
        cout << no->dado << endl;      // Visita o nó
        caminhamentoPRE(no->esquerda); // Percorre subárvore esquerda
        caminhamentoPRE(no->direita);  // Percorre subárvore direita
    }
};

template <typename TIPO>
void caminhamentoCentral(TNo<TIPO> *no)
{
    if (no != NULL)
    {
        // Central : visita a esquerda, a raiz,  a direita
        caminhamentoCentral(no->esquerda); // Percorre subárvore esquerda
        cout << no->dado << endl;          // Visita o nó
        caminhamentoCentral(no->direita);  // Percorre subárvore direita
    }
};

template <typename TIPO>
void caminhamentoPOS(TNo<TIPO> *no)
{
    if (no != NULL)
    {
        // Pos-ordem: visita a esquerda, depois direita, depois a raiz
        caminhamentoPOS(no->esquerda); // Percorre subárvore esquerda
        caminhamentoPOS(no->direita);  // Percorre subárvore direita
        cout << no->dado << endl;      // Visita o nó
    }
};

template <typename TIPO>
void procuraRemove(TNo<TIPO> *&no, int chave)
{
    if (no != NULL)
    {
        if (no->chave == chave)
        {
            remove(no); // Chama a remoção quando encontra o nó
        }
        else
        {
            if (chave < no->chave)
            {
                procuraRemove(no->esquerda, chave);
            }
            else
            {
                procuraRemove(no->direita, chave);
            }
        }
    }
}

template <typename TIPO>
void remove(TNo<TIPO> *&no)
{
    TNo<TIPO> *apagar;               // Ponteiro para o nó que será deletado
    TNo<TIPO> *maior = no->esquerda; // Busca o maior da subárvore esquerda

    // Caso 1: Nó não tem filho esquerdo (folha ou só direito)
    if (maior == NULL)
    {
        apagar = no;
        no = no->direita; // Substitui pelo filho direito (ou NULL)
        delete apagar;
        return;
    }

    TNo<TIPO> *pai = NULL;
    // Encontra o maior nó da subárvore esquerda (mais à direita)
    while (maior->direita != NULL)
    {
        pai = maior;
        maior = maior->direita;
    }

    // Reconecta os ponteiros:
    maior->direita = no->direita;

    if (pai != NULL)
    {
        pai->direita = maior->esquerda;
        maior->esquerda = no->esquerda;
    }

    apagar = no;
    no = maior; // Substitui o nó pelo maior encontrado
    delete apagar;
};
#endif