#ifndef RANDOM_H
#define RANDOM_H
#include <time.h>

// FAZ SORTEIO DE NUMEROS
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

// ZERA TODOS OS ELEMENTOS DO VETOR, EVITA LIXO DE MEMORIA
void zerarvetor(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = 0;
    }
}

// RETIRA OS ZEROS, ORDENA DE FORMA DECRESCENTE E RETORNA A QUANTIDADE DE ELEMENTOS
int organizador(int vetor[])
{
    int aux[10] = {0};

    // serve para retirar as primeiras casas com 0 e contar os numeros que ainda restam no vetor
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        // copiara os valores diferentes de 0 para o vetor auxiliar
        if (vetor[i] != 0)
        {
            aux[j] = vetor[i];
            j++;
        }
    }

    // copiara os valores do auxiliar organizado para o vetor original
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = aux[i];
    }

    // colocara os numeros em ordem decrescente
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
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

    // contara o numero de elementos (diferentes de 0)
    int ind = 0;
    while (vetor[ind] != 0)
    {
        ind++;
    }
    return ind;
}

// FAZ OS NOVOS SORTEIOS, CONCATENA. USAR O RETURN PARA QUEBRAR O LAÇO
void deletetoken(int vetor[], int tam, int &returnbroke)
{
    int aux[7] = {0};
    organizador(vetor);
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

// EXIBE ELEMENTOS DO VETOR
void viewvector(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("{ %i }", vetor[i]);
    }
    printf("\n");
}

// OBTEM O NUMERO DE ELEMENTOS GERAIS E OS DE NUMERO SEIS
void countnumbers(int vetor[], int &allnumbers, int &allnumberssix)
{
    organizador(vetor);
    allnumbers = 0;
    allnumberssix = 0;
    int i = 0;
    while (vetor[i] > 0 && vetor[i] < 7)
    {
        // fará uma varredura pelo vetor recem preenchido pelo sorteio
        if (vetor[i] == 6)
        {
            // contara o numero de "6", ja que eh um numero especial para o jogo
            allnumberssix++;
        }
        // contara o numero geral de elementos
        allnumbers++;
        i++;
    }
}

// NECESSARIO PARA IR EXCLUINDO OS ELEMENTOS DE NUMERO 6
void removesix(int vetor[], int &numberssix, int &allnumbers)
{
    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] == 6)
        {
            // subtrai algum elemento de numero "6"
            vetor[i] = 0;
            numberssix--;
            break;
        }
    }
    allnumbers--;
}

// NECESSARIO PARA IR EXCLUINDO OS ELEMENTOS JA USADOS
void clearposic(int vetor[], int &allnumbers)
{
    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] != 0)
        {
            // movimenta a peca
            vetor[i] = 0;
            allnumbers--;
        }
    }
}

#endif // RANDOM_H