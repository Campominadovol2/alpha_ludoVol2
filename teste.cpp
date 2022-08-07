#include <iostream>
#include <cstdio>
#include "analisador.h"
#include "random.h"
using namespace std;

int main()
{
    int vetor[10], an;
    while (1)
    {
        cout << "Digite o numero de tokens in: ";
        cin >> an;
        if (an == 333)
        {
            break;
        }
        zerarvetor(vetor, 10);
        random_numbers(vetor, 0, 3);
        printf("\n");
        analisamento(vetor, an);
    }

    return 0;
}
