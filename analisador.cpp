#include <iostream>
#include <cstdio>
#include "random.h"
using namespace std;
void analisamento(int vetor[], int tokens_in)
{
    int cont = 0, num = 0, i = 0, tokens_out = 4 - tokens_in;
    while (vetor[i] > 0 && vetor[i] < 7)
    {
        if (vetor[i] == 6)
        {
            num++;
        }
        cont++;
        i++;
    }
    if (num != 0)
    {
        if (vetor[2] == 6)
        {
            cout << "passa a vez\n";
        }
        else if (tokens_in == 4)
        {
            cout << "escolha um token para retirar\n";
        }
        else if (tokens_in > 0 && tokens_in < 4)
        {
            cout << "possivel de retirar um token\n";
        }
        else
        {
            cout << "apenas movimentar tokens\n";
        }
    }
    else
    {
        if(tokens_in==4){
            cout << "Sem possibilidades\n";
        }
        else{
            if(tokens_out==1){
                cout << "movimentacao automatica\n";
            }
            else{
                cout << "escolha um token para movimentar\n";
            }
        }
    }
}
int main()
{
    int vetor[3]={0}, n02;
    random_numbers(vetor);
    printf(":::: %i %i %i\n", vetor[0], vetor[1], vetor[2]);
    while (1)
    {
        cout << "Digite o numero de tokens: ";
        cin >> n02;
        analisamento(vetor, n02);
    }

    return 0;
}