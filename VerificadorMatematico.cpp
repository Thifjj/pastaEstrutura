#include <iostream>
#include "Pilha.h"
#include "string.h"
using namespace std;
bool VerificaEXP(char exp[])
{
    TPilha<char> pilha;
    inicializaPilha(pilha);
    char c;
    for (int i = 0; i < strlen(exp); i++)
    {
        c = exp[i];
    }
}
int main()
{
    char expressao[] = ("2 * ( 3 - [ 4+ { 2 + 3 }] )");
    if (VerificaEXP(expressao))
    {
        cout << "Expressao valida!";
    }
    else
    {
        cout << "Expressao invalida!";
    }
}