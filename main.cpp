#include <iostream>
#include "gconio.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <windows.h>

#define DELAY 0

using namespace std;

#include "tabuleiro.h"
#include "posicao.h"
#include "jogo.h"
#include "auxiliares.h"



void posicionarCursorNoMeio()
{
    SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2 , GetSystemMetrics(SM_CYSCREEN) / 2);
}
void darZoom(int a)
{
    keybd_event ( VK_LCONTROL, 0x36, 0, 0 );

    for(int i = 0; i < a; i++)
    {
        posicionarCursorNoMeio();
        mouse_event(MOUSEEVENTF_WHEEL, MOUSEEVENTF_ABSOLUTE, MOUSEEVENTF_ABSOLUTE, WHEEL_DELTA, NULL );
    }
    keybd_event ( VK_LCONTROL, 0x1C, KEYEVENTF_KEYUP, 0 );
}

/**
    vezDoProximo
    recebe o jogador da vez e o vetor de jogadores
    retorna o pr�ximo a jogar
*/
int vezDoProximo(int vezAtual, Player p[])
{
    int resultado;
    if(vezAtual == VERMELHO)
        vezAtual = -1;

    for(int i = vezAtual + 1; i < 4; i++)
    {
        if(i == 2)
        {
            if(p[AZUL].vaiJogar)
                return AZUL;
            else
                continue;
        }

        else if(i == 3)
        {
            if(p[VERMELHO].vaiJogar)
                return VERMELHO;
            else
                i = -1;
        }
        else
        {
            if(p[i].vaiJogar)
                return i;
        }


    }

    return -1;

}

int main()
{

    darZoom(7);


    system("chcp 65001");
    system("MODE con cols=80 lines=22");
    clrscr();

    char tabuleiro[LINHAS][COLUNAS];
    Player players[4];

    iniciarTabuleiro(tabuleiro);

    ///Cria��o dos jogares. Isso n�o pode sair do programa
    ///Passa o jogador que vc quer criar, o nome dele, o tabuleiro e se ele vai ou n�o jogar;
    ///A� vc faz um jeito de perguntar quantos v�o jogar e atribui o ultimo elemento com true ou false
    criarJogador(players[VERDE], "VERDE", tabuleiro, VERDE, true);
    criarJogador(players[AZUL], "AZUL", tabuleiro, AZUL, false);
    criarJogador(players[AMARELO], "AMARELO", tabuleiro, AMARELO, false);
    criarJogador(players[VERMELHO], "VERMELHO", tabuleiro, VERMELHO, true);

    printTabuleiro(tabuleiro);

    int dado = 1;
    char opcao;

    /**
        IMPORTANTE, a primeria atribui��o da jogador da vez � feita manualmente, mas dps, usa a fun��o vezDoProximo
    */
    int vezDe = VERDE;

    while(true)
    {
        gotoxy(50, 10);
        cout << "          ";
                    gotoxy(50, 3);
        cout << "          ";

        gotoxy(50, 1);

        cout << "       ";

        gotoxy(50, 1);

        cout << players[vezDe].nome << ": ";


        gotoxy(50, 2);

        cout << "       ";

        gotoxy(50, 2);
        cin >> opcao;
        int jogador = getPlayer(opcao); ///Pega o jogador que tem essa letra;
        int pos = posicaoPeca(players[jogador], opcao); ///retorna a poci��o da pe�a no vetor de pe�as do jogador com base na letra;

        ///Verifica��o r�pida de jogada v�lida ou inv�lida
        if(jogador == -1 || players[jogador].piece[pos].estaEmJogo == false || jogador != vezDe)
        {
            gotoxy(50, 10);
            cout << "INVALIDO";
            system("pause");
            continue;
        }


        gotoxy(50, 3);
        cin >> dado;

        ///Faz o movimento e atribui o retorno em temp
        int temp = andarCasas(tabuleiro, dado, tolower(opcao), players);

        if(temp == 1)
        {
            if(players[getPlayer(opcao)].pecasEmJogo == 0)
            {
                cout << "GANHOUkkkkkk";
                break;
            }
        }

        ///Atualiza��o do jogador da vez
        vezDe = vezDoProximo(vezDe, players);
    }

    printTabuleiro(tabuleiro);

    return 0;
}
