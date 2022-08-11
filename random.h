#ifndef RANDOM_H
#define RANDOM_H
#include <time.h>

void random_numbers(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        do
        {
            vetor[i] = rand() % 7;
        } while (vetor[i] == 0 || vetor[i] > 7);

        if (vetor[i] != 6)
        {
            break;
        }
    }
}

// apenas para teste, a superior teve limite delimitado, embora não seja nessario
void random_generic(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        do
        {
            vetor[i] = rand() % 7;
        } while (vetor[i] == 0 || vetor[i] > 7);

        if (vetor[i] != 6)
        {
            break;
        }
    }
}

void zerarvetor(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = 0;
    }
}

int organizador(int vetor[], int tam)
{
    int aux[10] = {0};

    // serve para retirar as primeiras casas com 0 e contar os numeros que ainda restam no vetor
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        // copiara os valores diferentes de 0 para o vetor auxiliar
        if (vetor[i] != 0)
        {
            aux[j] = vetor[i];
            j++;
        }
    }

    // copiara os valores do auxiliar organizado para o vetor original
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = aux[i];
    }

    // colocara os numeros em ordem decrescente
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            int temp = 0;
            if (vetor[i] < vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    // contara o numero de valores reais (diferentes de 0)
    int ind = 0;
    while (vetor[ind] != 0)
    {
        ind++;
    }
    return ind;
}

void deletetoken(int vetor[], int tam, int &returnbroke)
{
    int aux[7] = {0};
    random_numbers(aux, 7);
    // numeros a partir da quarta posicao serao zerados para evitar lixo de memoria
    for (int i = 3; i < tam; i++)
    {
        vetor[i] = 0;
    }

    // concatenara o vetor principal e auxiliar
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == 0)
        {
            if (aux[j] != 0)
            {
                vetor[i] = aux[j];
                j++;
            }
            else
            {
                break;
            }
        }
    }

    // ordenacao em ordem decrescente
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            int temp = 0;
            if (vetor[i] < vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    
    // codicional para quebrar laco
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == 6)
        {
            returnbroke = 1;
        }
    }
    returnbroke = 0;
}

#endif // RANDOM_H