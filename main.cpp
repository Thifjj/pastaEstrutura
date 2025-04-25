#include <iostream>
#include "arvorebinaria.h"
using namespace std;


int main() {
    TArvore<int> arvore;
    inicializaArvore(arvore);

    // Insere elementos (o primeiro vira raiz)
    insereArvore(arvore.raiz, 50, 50);  // Raiz
    insereArvore(arvore.raiz, 30, 30);  // Esquerda
    insereArvore(arvore.raiz, 70, 70);  // Direita
    insereArvore(arvore.raiz, 20, 20);  // Esquerda do 30
    insereArvore(arvore.raiz, 40, 40);  // Direita do 30

    cout << "Pré-ordem:" << endl;
    caminhamentoPRE(arvore.raiz);

    cout << "\nCentral (In-Order):" << endl;
    caminhamentoCentral(arvore.raiz);

    cout << "\nPós-ordem:" << endl;
    caminhamentoPOS(arvore.raiz);

    return 0;
}