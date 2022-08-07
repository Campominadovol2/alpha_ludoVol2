#ifndef ANALISE_H
#define ANALISE_H

using namespace std;

#include <cstdio>
#include <cstdlib>
/*
#include "tabuleiro.h"
#include "posicao.h"
#include "jogo.h"
#include "auxiliares.h"
*/
#include "random.h"
void exibidoh(int vetor[], int tam);



void analisamento(int vetor[], int tokens_in)
{
    cout << "=============\n";
    exibidoh(vetor, 3);
    int cont = 0, num = 0, i = 0;
    while (vetor[i] > 0 && vetor[i] < 7)
    {
        // fará uma varredura pelo vetor recem preenchido pelo sorteio
        if (vetor[i] == 6)
        {
            // contara o numero de "6", ja que eh um numero especial para o jogo
            num++;
        }
        // contara o numero geral de elementos
        cont++;
        i++;
    }
    int tam = cont;

    while (num != 0)
    {
        exibidoh(vetor, 3);
        // o laco ocorrera enquanto houver numeros "6"
        if (vetor[2] == 6)
        {
            // por regra, se hover 3 "6" provenientes de sorteio o jogador perde a vez
            printf("passa a vez01\n");
            // getch();
            return;
        }
        else if (tokens_in == 4)
        {
            // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar a peça da casa
            printf("escolha um token para retirar: 02\n");
            // função para retirar token
            for (int i = 0; i < tam; i++)
            {
                if (vetor[i] == 6)
                {
                    vetor[i] = 0;
                    // subtrai algum elemento de numero "6"
                    tokens_in--;
                    num--;
                    break;
                }
            }
            // subtrai o numero de elementos no vetor
            cont--;
            // getch();
        }

        else if (tokens_in > 0 && tokens_in < 4)
        {
            // se houver tokens fora e dentro da casa o jogador tera a oportunidade de escolher sua jogada
            int temp;
            printf("possivel de retirar um token\nDeseja retirar um token?(0/1)03\n");
            cin >> temp;
            if (temp == 1)
            {
                printf("escolha um token para retirar: 04\n");
                // função para retirar token
                for (int i = 0; i < tam; i++)
                {
                    if (vetor[i] == 6)
                    {
                        vetor[i] = 0;
                        // subtrai algum elemento de numero "6"
                        num--;
                        cout << "entrou\n";
                        tokens_in--;
                        break;
                    }
                }
                cont--;
            }
            else
            {
                // se optar por nao retirar o token sera movida a unica peça que esta em jogo
                if (tokens_in == 3)
                {
                    // movimenta o unico token que está fora
                    printf("movimentacao automatica05\n");
                    for (int i = 0; i < tam; i++)
                    {
                        if (vetor[i] == 6)
                        {
                            // movimenta a peca
                            vetor[i] = 0;
                            num--;
                            break;
                        }
                    }
                }
                // se optar por nao retirar o token o usuario devera mover algumas das pecas em jogo
                else
                {
                    printf("Digite o token que deseja mover: 06\n");
                    // função para mover token
                    for (int i = 0; i < tam; i++)
                    {
                        if (vetor[i] == 6)
                        {
                            vetor[i] = 0;
                            // subtrai algum elemento de numero "6"
                            num--;
                            break;
                        }
                    }
                    cont--;
                }
            }

            // getch();
        }
        else
        {
            // se todos estiverem fora da casa so restara a opcao de mover as pecas em jogo
            printf("apenas movimentar tokens07\n");
            // função para mover token
            for (int i = 0; i < tam; i++)
            {
                if (vetor[i] == 6)
                {
                    vetor[i] = 0;
                    // subtrai algum elemento de numero "6"
                    num--;
                    break;
                }
            }
            cont--;
            // getch();
        }
    }

    // apos as operacoes com todos os numeros "6" o programa revisara os numeros restantes e as possibilidades de jogo
    // a funcao organizara os elementos restante e fara uma contagem deles
    exibidoh(vetor, 3);
    int numb = organizador(vetor, tam);
    cout << "Numeros restante: " << numb;
    exibidoh(vetor, 3);
    // enquanto houver elementos o laco ocorrera
    while (numb != 0)
    {
        exibidoh(vetor, 3);

        if (tokens_in == 4)
        {
            // se nao tiver nenhum numero "6" o usuario nao podera retirar um de seus 4 tokens, perde a vez
            printf("Sem possibilidades08\n");
            return;
        }

        else if (tokens_in == 3)
        {
            // movimenta o unico token que está fora
            printf("movimentacao automatica09\n");
            for (int i = 0; i < numb; i++)
            {
                if (vetor[i] != 0)
                {
                    // movimenta a peca
                    vetor[i] = 0;
                    numb--;
                }
            }
        }

        else
        {
            // função para mover alguns dos tokens
            printf("movimentacao seletiva10\n");
            for (int i = 0; i < numb; i++)
            {
                if (vetor[i] != 0)
                {
                    // movimenta a peca
                    vetor[i] = 0;
                    numb--;
                }
            }
        }
    }
}
void exibidoh(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("{ %i }", vetor[i]);
    }
    printf("\n");
}

#endif // ANALISE_H