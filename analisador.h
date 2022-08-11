#ifndef ANALISE_H
#define ANALISE_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "random.h"

// FUNÇÕES AUXILIARES
void viewvector(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("{ %i }", vetor[i]);
    }
}
void countnumbers(int vetor[], int &allnumbers, int &allnumberssix)
{
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
void removesix(int vetor[], int tam, int &numberssix, int &allnumbers)
{
    for (int i = 0; i < tam; i++)
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

// PRINCIPAL FUNÇÃO
void analisamento(int vetor[], int tokens_stopped, int tokens_finish, int posx, int posy)
{
    // PLAYERS QUE CHEGARAM AO FIM: tokens_finish
    // PLAYERS QUE ESTÃO DENTRO DA CASA: tokens_stopped
    // PLAYERS QUE ESTÃO NO PERCURSO:
    int tokens_inpercurso = 4 - (tokens_stopped + tokens_finish);
    int tokens_max = tokens_inpercurso + tokens_stopped;
    // gotoxy(posx, posy++);
    viewvector(vetor, 3);
    int allnumbers, numberssix, temp;
    countnumbers(vetor, allnumbers, numberssix);
    int tam = allnumbers;

    while (numberssix != 0 && tokens_finish != 4)
    {
        viewvector(vetor, 3);
        // o laco ocorrera enquanto houver numeros "6"

        // por regra, se hover 3 "6" provenientes de sorteio o jogador perde a vez
        if (vetor[2] == 6)
        {
            // gotoxy(posx, posy++);
            printf("passa a vez01\n");
            // getch();
            return;
        }

        // TEM TOKEN APENAS NA CASA OU NO FINAL
        else if (tokens_inpercurso == 0 && tokens_stopped != 0)
        {
            if (tokens_stopped == 1)
            {
                // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar unica a peça da casa
                // gotoxy(posx, posy++);
                printf("retirada automatica de unico token dentro da casa 02\n");
                // função para retirar token
                removesix(vetor, tam, numberssix, allnumbers);
                tokens_stopped--;
                tokens_inpercurso++;
            }
            else
            {
                // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar uma das peças da casa
                // gotoxy(posx, posy++);
                printf("escolha um token para retirar: 02\n");
                // implementar escolha de tokens da desenhos.h
                // função para retirar token
                removesix(vetor, tam, numberssix, allnumbers);
                tokens_stopped--;
                tokens_inpercurso++;
            }
        }

        // TEM TOKENS NO PERCURSO, NA CASA OU ATE NO FIM
        else if (tokens_inpercurso != 0 && tokens_stopped != 0)
        {
            // se houver tokens fora e dentro da casa o jogador tera a oportunidade de escolher sua jogada
            int temp;
            // gotoxy(posx, posy++);
            printf("possivel de retirar um token\nDeseja retirar um token?(0/1)03\n");
            // funcao de escolha
            cin >> temp;
            if (temp == 1) // se optar por retirar o/os token/s presente/s na casa
            {
                if (tokens_stopped == 1) // se na casa houver apenas um tokens ele sera retirado automaticamente
                {
                    // funcao para retirar token automaticamente
                    removesix(vetor, tam, numberssix, allnumbers);
                    tokens_stopped--;
                    tokens_inpercurso++;
                }
                else // se houver mais de um token o usuario devera escolher
                {
                    // gotoxy(posx, posy++);
                    printf("escolha um token para retirar: 04\n");
                    // funcao para escolher token
                    //  função para retirar token
                    removesix(vetor, tam, numberssix, allnumbers);
                    tokens_stopped--;
                    tokens_inpercurso++;
                }
            }
            else // se optar por nao retirar o/os token/s presente/s na casa devera mover algum fora
            {
                if (tokens_inpercurso == 1) // se houver apenas uma peca em jogo movimentara ela automaticamente
                {
                    // gotoxy(posx, posy++);
                    // funcao para mover automaticamente
                    printf("movimentacao automatica05\n");
                    removesix(vetor, tam, numberssix, allnumbers);
                }
                else // se houver mais de uma peca em jogo o usuario devera escolher
                {
                    // gotoxy(posx, posy++);
                    printf("Digite o token que deseja mover: 06\n");
                    // função para escolher token
                    //  função para mover token
                    removesix(vetor, tam, numberssix, allnumbers);
                }
                // if deletar algum token ==== deletetoken(vetor, tam, temp);
            }
        }

        // TEM TOKENS APENAS NO PERCURSO OU NO FIM
        else if (tokens_inpercurso != 0 && tokens_stopped == 0)
        {
            if (tokens_inpercurso == 1) // se houver apenas um token no percurso ele sera movimentado automaticamente
            {
                // gotoxy(posx, posy++);
                printf("movimentacao automatica05\n");
                // funcao para mover token
                removesix(vetor, tam, numberssix, allnumbers);
            }
            else // se houver mais de um token fora o usuario devera escolher
            {
                // gotoxy(posx, posy++);
                printf("apenas movimentar tokens07\n");
                // funcao para escolher token
                // função para mover token
                removesix(vetor, tam, numberssix, allnumbers);
            }
            // if deletar algum token ==== deletetoken(vetor, tam, temp);
        }
        // fim da etapa dos numeros 6
    }

    // apos as operacoes com todos os numeros "6" o programa revisara os numeros restantes e as possibilidades de jogo
    // a funcao organizara os elementos restante e fara uma contagem deles
    // gotoxy(posx, posy++);
    viewvector(vetor, 3);
    int newsize = organizador(vetor, tam);
    // gotoxy(posx, posy++);
    cout << "Numeros restante: " << newsize;
    // gotoxy(posx, posy++);
    viewvector(vetor, 3);

    // enquanto houver elementos o laco ocorrera
    while (newsize != 0 && tokens_stopped != 4)
    {
        // gotoxy(posx, posy++);
        viewvector(vetor, 3);

        if (tokens_inpercurso == 0)
        {
            // se nao tiver nenhum numero "6" o usuario nao podera retirar um de seus 4 tokens, perde a vez
            // gotoxy(posx, posy++);
            printf("Sem possibilidades08\n");
            return;
        }

        else if (tokens_inpercurso == 1)
        {
            // movimenta o unico token que está fora
            // gotoxy(posx, posy++);
            printf("movimentacao automatica09\n");
            for (int i = 0; i < newsize; i++)
            {
                if (vetor[i] != 0)
                {
                    // movimenta a peca
                    vetor[i] = 0;
                    newsize--;
                }
            }
            // if deletar algum token ==== deletetoken(vetor, tam, temp);
        }

        else
        {
            // função para mover alguns dos tokens
            // gotoxy(posx, posy++);
            printf("movimentacao seletiva1, meliante escolher o token que deseja movimentar0\n");

            for (int i = 0; i < newsize; i++)
            {
                if (vetor[i] != 0)
                {
                    // movimenta a peca
                    vetor[i] = 0;
                    newsize--;
                }
            }
            // if deletar algum token ==== deletetoken(vetor, tam, temp);
        }
    }
}

void generalnumbers()
{

}

// NOTES:
// a funcao e capaz de para a qualquer momento assim que um jogador ganhar?????

#endif // ANALISE_H