#ifndef ANALISE_H
#define ANALISE_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "random.h"

void loopnumberssix(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &tam, int &numberssix, int &allnumbers, int posx, int posy);
void generalnumbers(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &tam, int &numberssix, int &allnumbers, int posx, int posy);

// PRINCIPAL FUNÇÃO
void jogamentos(int tokens_stopped, int tokens_finish, int posx, int posy)
{
    // stopped->estao dentro da casa    finish->chegaram ao fim    percurso->estao trafegando
    int tokens_inpercurso = 4 - (tokens_stopped + tokens_finish);
    // gotoxy(posx, posy++);

    // etapa de sorteio dos tres primeiros numeros possiveis
    int vetor[10] = {0};
    random_numbers(vetor, 3);

    int allnumbers, numberssix, temp, pass = 0;

    while (pass == 0)
    {
        countnumbers(vetor, allnumbers, numberssix);
        int tam = allnumbers;
        viewvector(vetor, 3);
        loopnumberssix(vetor, tokens_stopped, tokens_inpercurso, tokens_finish, tam, numberssix, allnumbers, posx, posy);
        generalnumbers(vetor, tokens_stopped, tokens_inpercurso, tokens_finish, tam, numberssix, allnumbers, posx, posy);
        pass++;
    }

    // gotoxy(posx, posy++);
    int newsize = organizador(vetor);
    // gotoxy(posx, posy++);
    cout << "Numeros restante: " << newsize << "\n";
    // gotoxy(posx, posy++);
}

void loopnumberssix(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &tam, int &numberssix, int &allnumbers, int posx, int posy)
{
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
                removesix(vetor, numberssix, allnumbers);
                tokens_stopped--;
                tokens_inpercurso++;
            }
            else
            {
                // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar uma das peças da casa
                // gotoxy(posx, posy++);
                printf("escolha um token para retirar(%i): 03\n", tokens_inpercurso);
                // implementar escolha de tokens da desenhos.h
                // função para retirar token
                removesix(vetor, numberssix, allnumbers);
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
            printf("possivel de retirar um token\nDeseja retirar um token?(0/1)04\n");
            // funcao de escolha
            cin >> temp;
            if (temp == 1) // se optar por retirar o/os token/s presente/s na casa
            {
                if (tokens_stopped == 1) // se na casa houver apenas um tokens ele sera retirado automaticamente
                {
                    // funcao para retirar token automaticamente
                    removesix(vetor, numberssix, allnumbers);
                    tokens_stopped--;
                    tokens_inpercurso++;
                }
                else // se houver mais de um token o usuario devera escolher
                {
                    // gotoxy(posx, posy++);
                    printf("escolha um token para retirar: 05\n");
                    // funcao para escolher token
                    //  função para retirar token
                    removesix(vetor, numberssix, allnumbers);
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
                    printf("movimentacao automatica06\n");
                    removesix(vetor, numberssix, allnumbers);
                }
                else // se houver mais de uma peca em jogo o usuario devera escolher
                {
                    // gotoxy(posx, posy++);
                    printf("Digite o token que deseja mover(%i): 07\n", tokens_inpercurso);
                    // função para escolher token
                    //  função para mover token
                    removesix(vetor, numberssix, allnumbers);
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
                printf("movimentacao automatica08\n");
                // funcao para mover token
                removesix(vetor, numberssix, allnumbers);
            }
            else // se houver mais de um token fora o usuario devera escolher
            {
                // gotoxy(posx, posy++);
                printf("apenas movimentar tokens09\n");
                // funcao para escolher token
                // função para mover token
                removesix(vetor, numberssix, allnumbers);
            }
            // if deletar algum token ==== deletetoken(vetor, tam, temp);
        }
        // fim da etapa dos numeros 6
    }
}

void generalnumbers(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &tam, int &numberssix, int &allnumbers, int posx, int posy)
{
    // enquanto houver elementos o laco ocorrera
    while (allnumbers != 0 && tokens_stopped != 4)
    {
        // gotoxy(posx, posy++);

        if (tokens_inpercurso == 0)
        {
            // se nao tiver nenhum numero "6" o usuario nao podera retirar um de seus 4 tokens, perde a vez
            // gotoxy(posx, posy++);
            printf("Sem possibilidades10\n");
            return;
        }

        else if (tokens_inpercurso == 1)
        {
            // movimenta o unico token que está fora
            // gotoxy(posx, posy++);
            printf("movimentacao automatica11\n");
            clearposic(vetor, allnumbers);
            // if deletar algum token ==== deletetoken(vetor, tam, temp); alterar pass para 1 e dar return
        }

        else
        {
            // função para mover alguns dos tokens
            // gotoxy(posx, posy++);
            printf("movimentacao seletiva1, (%i)12\n", tokens_inpercurso);

            clearposic(vetor, allnumbers);
            // if deletar algum token ==== deletetoken(vetor, tam, temp); alterar pass para 1 e dar return
        }
    }
}

// NOTES:
// a funcao e capaz de para a qualquer momento assim que um jogador ganhar?????

#endif // ANALISE_H