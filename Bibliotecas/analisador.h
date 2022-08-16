#ifndef ANALISE_H
#define ANALISE_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "random.h"

void loopnumberssix(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass);
void generalnumbers(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass);
void testando(int vetor[]);

// PRINCIPAL FUNÇÃO
void jogamentos(int tokens_stopped, int tokens_finish, int posx, int posy)
{
    // stopped->estao dentro da casa    finish->chegaram ao fim    percurso->estao trafegando
    int tokens_inpercurso = 4 - (tokens_stopped + tokens_finish);
    // gotoxy(posx, posy++);

    // etapa de sorteio dos tres primeiros numeros possiveis
    int vetor[10] = {0};
    random_numbers(vetor, 3);

    int allnumbers, numberssix, pass = 1;
    while (pass == 1)
    {
        organizador(vetor);
        countnumbers(vetor, allnumbers, numberssix);
        loopnumberssix(vetor, tokens_stopped, tokens_inpercurso, tokens_finish, numberssix, allnumbers, posx, posy, pass);
        generalnumbers(vetor, tokens_stopped, tokens_inpercurso, tokens_finish, numberssix, allnumbers, posx, posy, pass);
    }
}

// USO TEMPORARIO APENAS PARA TESTAR A POSSIBILIDADE DE DELETAR UM TOKEN
void testando(int vetor[])
{
    // futuramente essa função sera modificada para receber um valor booleano e então permitir a função deletetoken que faa novos sorteios
    int temp;
    printf("0/1 para teste de delete: ");
    scanf("%i", &temp);
    if (temp == 1)
    {
        deletetoken(vetor);
    }
}

void loopnumberssix(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass)
{
    printf("entrou na 6\n");
    organizador(vetor);
    countnumbers(vetor, allnumbers, numberssix);
    viewvector(vetor, 10);
    while (numberssix != 0 && tokens_finish != 4)
    {
        viewvector(vetor, 10);
        // o laco ocorrera enquanto houver numeros "6"
        printf("\tConsumira o numero: %i\n", vetor[0]);
        // por regra, se hover 3 "6" provenientes de sorteio o jogador perde a vez
        if (vetor[2] == 6 && tokens_finish != 4)
        {
            // gotoxy(posx, posy++);
            printf("passa a vez01\n");
            // getch();
            return;
        }


        // TEM TOKEN APENAS NA CASA OU NO FINAL
        else if (tokens_inpercurso == 0 && tokens_stopped != 0 && tokens_finish != 4)
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
                // if deletar algum token;
                testando(vetor);
            }
        }

        // TEM TOKENS APENAS NO PERCURSO OU NO FIM
        else if (tokens_inpercurso != 0 && tokens_stopped == 0 && tokens_finish != 4)
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
            // if deletar algum token ==== deletetoken(vetor);
            testando(vetor);
        }
        organizador(vetor);
    }
    remaining(vetor, pass);
}

void generalnumbers(int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass)
{
    printf("entro na segunda\n");
    organizador(vetor);
    countnumbers(vetor, allnumbers, numberssix);
    viewvector(vetor, 10);
    // enquanto houver elementos o laco ocorrera
    while (allnumbers != 0 && tokens_stopped != 4)
    {
        // gotoxy(posx, posy++);
        viewvector(vetor, 10);
        printf("\tConsumira o numero: %i\n", vetor[0]);
        if (tokens_inpercurso == 0)
        {
            // se nao tiver nenhum numero "6" o usuario nao podera retirar um de seus 4 tokens, perde a vez
            // gotoxy(posx, posy++);
            printf("Sem possibilidades10\n");
            return;
        }

        else if (tokens_inpercurso == 1 && tokens_finish != 4)
        {
            // movimenta o unico token que está fora
            // gotoxy(posx, posy++);
            printf("movimentacao automatica11\n");
            clearposic(vetor, allnumbers);
            // if deletar algum token ==== deletetoken(vetor); alterar pass para 1 e dar return
            testando(vetor);
        }

        else if (tokens_finish != 4)
        {
            // função para mover alguns dos tokens
            // gotoxy(posx, posy++);
            printf("movimentacao seletiva1, (%i)12\n", tokens_inpercurso);

            clearposic(vetor, allnumbers);
            // if deletar algum token ==== deletetoken(vetor); alterar pass para 1 e dar return
            testando(vetor);
        }
        organizador(vetor);
    }
    remaining(vetor, pass);
}

// NOTES:
// a funcao e capaz de para a qualquer momento assim que um jogador ganhar?????

#endif // ANALISE_H