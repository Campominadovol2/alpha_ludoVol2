#ifndef ANALISE_H
#define ANALISE_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "random.h"
#include "desenhos.h"

using namespace std;

void loopnumberssix(Player p[], int JogadorVez, char tabuleiro[17][18], int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass, int posvetor[]);
void generalnumbers(Player p[], int JogadorVez, char tabuleiro[17][18], int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass, int posvetor[]);
void testando(int vetor[]);
char selecionartoken(Player p, int numbersort);
int tokensDisponiveis(Player p, int _pos_x, int __pos_y, char vetor[], int cond);
char getLetraInPercurso(Player p);
char getLetraStopped(Player p);

// void selecion(Player p, int JogadorVez, int vetor, char tabuleiro[17][18], int &tokens_inpercurso, int &tokens_stopped, int &tokens_finish, int posx, int posy);

// PRINCIPAL FUNÇÃO
void jogamentos(Player p[], int JogadorVez, char tabuleiro[17][18], int tokens_stopped, int tokens_finish, int posx, int posy)
{
    // stopped->estao dentro da casa    finish->chegaram ao fim    percurso->estao trafegando
    int tokens_inpercurso = 4 - (tokens_stopped + tokens_finish);
    // etapa de sorteio dos tres primeiros numeros possiveis
    int vetor[10] = {0};

    random_numbers(vetor, 3);

    int posvetor[2] = {40, 3};

    // por regra, se hover 3 "6" provenientes do primeiro sorteio o jogador perde a vez
    if (vetor[2] == 6)
    {
        gotoxy(37, 7);
        printf("Foram sorteados 3 número 6.");
        gotoxy(37, 7);
        printf("PASSA A VEZ!");
        // getch(); OBSSSSSSSS: possivel de colocar sleep para usuario visualizar o motivo
        // return;
    }

    // como nao houve um terceiro termo igual a "6", o jogo pode continuar normalmente
    int allnumbers, numberssix, pass = 1;
    while (pass == 1)
    {
        organizador(vetor);
        countnumbers(vetor, allnumbers, numberssix);
        loopnumberssix(p, JogadorVez, tabuleiro, vetor, tokens_stopped, tokens_inpercurso, tokens_finish, numberssix, allnumbers, posx, posy, pass, posvetor);
        getch();
        generalnumbers(p, JogadorVez, tabuleiro, vetor, tokens_stopped, tokens_inpercurso, tokens_finish, numberssix, allnumbers, posx, posy, pass, posvetor);
        getch();
    }
}

void loopnumberssix(Player p[], int JogadorVez, char tabuleiro[17][18], int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass, int posvetor[])
{
    organizador(vetor);
    countnumbers(vetor, allnumbers, numberssix);

    while (numberssix != 0)
    {
        preencher_com_espacos(38, 13, 36, 5);
        viewvector(vetor, 10, posvetor[0], posvetor[1]);
        // o laco ocorrera enquanto houver numeros "6"

        // TEM TOKEN APENAS NA CASA
        if (tokens_inpercurso == 0 && tokens_stopped != 0)
        {
            if (tokens_stopped == 1)
            {
                // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar unica a peça da casa
                gotoxy(37, 7);
                printf("Retirada automatica de unico token dentro da casa 02\n");
                // funcao para retirar token automaticamente
                char temp = getLetraStopped(p[JogadorVez]);
                andarCasas(tabuleiro, vetor[0], temp, p);
                gotoxy(37, 8);
                printf("Movendo o token %c...", temp);
                removesix(vetor, numberssix, allnumbers);
                tokens_stopped--;
                tokens_inpercurso++;
            }
            else
            {
                // se houver ao menos um "6" e nenhum token fora o jogador e obrigado a retirar uma das peças da casa
                gotoxy(37, 7);
                printf("Selecione um token: ");
                char temp = selecionartoken(p[JogadorVez], 1);
                andarCasas(tabuleiro, vetor[0], temp, p);
                gotoxy(37, 9);
                printf("Movendo o token %c...", temp);
                removesix(vetor, numberssix, allnumbers);
                tokens_stopped--;
                tokens_inpercurso++;
            }
            preencher_com_espacos(38, 13, 36, 5);
        }

        // TEM TOKENS NO PERCURSO OU NA CASA
        else if (tokens_inpercurso != 0 && tokens_stopped != 0)
        {
            // se houver tokens fora e dentro da casa o jogador tera a oportunidade de escolher sua jogada
            gotoxy(37, 7);
            printf("Deseja retirar ou mover um token?");
            gotoxy(40, 9);
            printf("[SIM]");
            gotoxy(40, 10);
            printf("[NÃO]");
            int op = selecionar_opcao(37, 9, 2);
            preencher_com_espacos(38, 13, 36, 5);
            switch (op)
            {
            case 1:                      // se optar por retirar o/os token/s presente/s na casa
                if (tokens_stopped == 1) // se na casa houver apenas um tokens ele sera retirado automaticamente
                {
                    // funcao para retirar token automaticamente
                    char temp = getLetraStopped(p[JogadorVez]);
                    andarCasas(tabuleiro, vetor[0], temp, p);
                    gotoxy(37, 7);
                    printf("Movendo o token %c...", temp);
                    removesix(vetor, numberssix, allnumbers);
                    preencher_com_espacos(38, 13, 36, 5);
                    tokens_stopped--;
                    tokens_inpercurso++;
                }
                else // se houver mais de um token o usuario devera escolher
                {
                    gotoxy(37, 7);
                    printf("Selecione um token: ");
                    char temp = selecionartoken(p[JogadorVez], 1);
                    andarCasas(tabuleiro, vetor[0], temp, p);
                    gotoxy(37, 9);
                    printf("Movendo o token %c...", temp);
                    removesix(vetor, numberssix, allnumbers);
                    preencher_com_espacos(38, 13, 36, 5);
                    tokens_stopped--;
                    tokens_inpercurso++;
                }
                break;

            case 2:                         // se optar por nao retirar o/os token/s presente/s na casa devera mover algum fora
                if (tokens_inpercurso == 1) // se houver apenas uma peca em jogo movimentara ela automaticamente
                {
                    gotoxy(37, 7);
                    printf("Movimentacao automatica06\n");
                    // funcao para mover token automaticamente
                    char temp = getLetraInPercurso(p[JogadorVez]);
                    andarCasas(tabuleiro, vetor[0], temp, p);
                    gotoxy(40, 8);
                    printf("Movendo o token %c...", temp);
                    removesix(vetor, numberssix, allnumbers);
                    preencher_com_espacos(38, 13, 36, 5);
                }
                else // se houver mais de uma peca em jogo o usuario devera escolher
                {
                    gotoxy(37, 7);
                    printf("Selecione um token: ");
                    char temp = selecionartoken(p[JogadorVez], 0);
                    andarCasas(tabuleiro, vetor[0], temp, p);
                    gotoxy(37, 9);
                    printf("Movendo o token %c...", temp);
                    removesix(vetor, numberssix, allnumbers);
                    preencher_com_espacos(38, 13, 36, 5);
                }
                // if deletar algum token;
                // testando(vetor);
                break;

            default:
                break;
            }
            preencher_com_espacos(38, 13, 36, 5);
        }

        // TEM TOKENS APENAS NO PERCURSO
        else if (tokens_inpercurso != 0 && tokens_stopped == 0)
        {
            if (tokens_inpercurso == 1) // se houver apenas um token no percurso ele sera movimentado automaticamente
            {
                gotoxy(37, 7);
                printf("Movimentacao automatica08");
                // funcao para mover token automaticamente
                char temp = getLetraInPercurso(p[JogadorVez]);
                andarCasas(tabuleiro, vetor[0], temp, p);
                gotoxy(37, 9);
                printf("Movendo o token %c...", temp);
                removesix(vetor, numberssix, allnumbers);
                preencher_com_espacos(38, 13, 36, 5);
            }
            else // se houver mais de um token fora o usuario devera escolher
            {
                gotoxy(37, 7);
                printf("Selecione um token: ");
                char temp = selecionartoken(p[JogadorVez], 0);
                andarCasas(tabuleiro, vetor[0], temp, p);
                gotoxy(37, 9);
                printf("Movendo o token %c...", temp);
                removesix(vetor, numberssix, allnumbers);
                preencher_com_espacos(38, 13, 36, 5);
            }
            // if deletar algum token ==== deletetoken(vetor);
            // testando(vetor);
            preencher_com_espacos(38, 13, 36, 5);
        }
        organizador(vetor);
    }
    remaining(vetor, pass);
}

void generalnumbers(Player p[], int JogadorVez, char tabuleiro[17][18], int vetor[], int &tokens_stopped, int &tokens_inpercurso, int &tokens_finish, int &numberssix, int &allnumbers, int posx, int posy, int &pass, int posvetor[])
{
    organizador(vetor);
    countnumbers(vetor, allnumbers, numberssix);

    // enquanto houver elementos o laco ocorrera
    while (allnumbers != 0 && tokens_stopped != 4)
    {
        preencher_com_espacos(38, 13, 36, 5);
        viewvector(vetor, 10, posvetor[0], posvetor[1]);
        if (tokens_inpercurso == 0)
        {
            // se nao tiver nenhum numero "6" o usuario nao podera retirar um de seus 4 tokens, perde a vez
            gotoxy(37, 7);
            printf("Sem possibilidades de jogo.10");
            gotoxy(37, 8);
            printf("PASSA A VEZ!");
            preencher_com_espacos(38, 13, 36, 5);

            // return;
        }

        else if (tokens_inpercurso == 1)
        {
            gotoxy(37, 7);
            printf("Movimentacao automatica08");
            // funcao para mover token automaticamente
            char temp = getLetraInPercurso(p[JogadorVez]);
            andarCasas(tabuleiro, vetor[0], temp, p);
            clearposic(vetor, allnumbers);
            preencher_com_espacos(38, 13, 36, 5);
            // if deletar algum token ==== deletetoken(vetor); alterar pass para 1 e dar return
            // testando(vetor);
        }

        else if (tokens_finish != 4)
        {
            // função para mover alguns dos tokens
            gotoxy(37, 7);
            printf("Selecione um token: ");
            char temp = selecionartoken(p[JogadorVez], 0);
            andarCasas(tabuleiro, vetor[0], temp, p);
            gotoxy(37, 9);
            printf("Movendo o token %c...", temp);
            clearposic(vetor, allnumbers);
            // if deletar algum token ==== deletetoken(vetor); alterar pass para 1 e dar return
            // testando(vetor);
            preencher_com_espacos(38, 13, 36, 5);
        }
        organizador(vetor);
    }
    remaining(vetor, pass);
}

char getLetraInPercurso(Player p)
{
    for (int i = 0; i < 4; i++)
    {
        if (p.piece[i].estaEmJogo && !p.piece[i].estaNaPosicaoInicial)
        {
            return p.piece[i].letra;
        }
    }
    return ' ';
}

char getLetraStopped(Player p)
{
    for (int i = 0; i < 4; i++)
    {
        if (p.piece[i].estaNaPosicaoInicial)
        {
            return p.piece[i].letra;
        }
    }
    return ' ';
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

int tokensDisponiveis(Player p, int _pos_x, int __pos_y, char vetor[], int cond)
{
    int r = 0;
    for (int i = 0; i < 4; i++)
    {
        if (p.piece[i].estaEmJogo)
        {
            if (cond == 1)
            {
                if (p.piece[i].estaNaPosicaoInicial)
                {
                    gotoxy(_pos_x, __pos_y++);
                    cout << "[" << p.piece[i].letra << "]";
                    vetor[r] = p.piece[i].letra;
                    r++;
                }
            }
            else
            {
                if (!p.piece[i].estaNaPosicaoInicial)
                {
                    gotoxy(_pos_x, __pos_y++);
                    cout << "[" << p.piece[i].letra << "]";
                    vetor[r] = p.piece[i].letra;
                    r++;
                }
            }
        }
    }

    return r;
}

char selecionartoken(Player p, int cond)
{
    char tokensdisp[4];
    int quantidade = tokensDisponiveis(p, 40, 9, tokensdisp, cond);
    int numescolha = selecionar_opcao(37, 9, quantidade);

    return tokensdisp[numescolha - 1];
}

// NOTES:
// a funcao e capaz de para a qualquer momento assim que um jogador ganhar?????

#endif // ANALISE_H