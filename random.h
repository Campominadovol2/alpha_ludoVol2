#ifndef RANDOM_H
#define RANDOM_H
#include <time.h>

void random_numbers(int vetor[])
{
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        do
        {
            vetor[i] = rand() % 7;
        } while (vetor[i] == 0);

        if (vetor[i] != 6)
        {
            break;
        }
    }
}

#endif // RANDOM_H