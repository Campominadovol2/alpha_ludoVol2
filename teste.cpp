#include <iostream>
#include <cstdio>
#include "random.h"
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int vetor[10], aux[7], an;

    while (1)
    {
        zerarvetor(vetor, 3);
        random_numbers(vetor, 3);
        deletetoken(vetor, 10);
        cout << "Continue? ";
        cin >> an;
        if (an == 0)
        {
            break;
        }
    }

    return 0;
}
