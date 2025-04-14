#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <iostream>

using namespace std;

template<typename TIPO>
struct TNo{
    TIPO dado;
    int chave;
    TNo<TIPO> *direita;
    TNo<TIPO> *esquerda;
};

template<typename TIPO>
struct TArvore{
    TNo<TIPO> *raiz;
};


template<typename TIPO>
void inicializaArvore(TArvore<TIPO> &arvore){
    arvore.raiz = NULL;
    arvore.raiz->direita = NULL;
    arvore.raiz->esquerda = NULL;
};

template<typename TIPO>
void insereArvore(TNo<TIPO> *&no, TIPO dado, int chave){
    if(no == NULL){
        no = new TNo;
        no->dado = dado;
        no->chave = chave;
        no->direita = NULL;
        no->esquerda = NULL;
    }else{
        if(no->chave < chave){
            insereArvore(no->direita,dado,chave);
        }else{
            insereArvore(no->esquerda,dado,chave);
        }
    }
};

#endif