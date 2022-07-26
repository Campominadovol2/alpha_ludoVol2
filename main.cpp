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


int main()
{

    darZoom(7);


    system("chcp 65001");
    system("MODE con cols=80 lines=22");
    clrscr();

    char tabuleiro[LINHAS][COLUNAS];
    Player players[4];

    iniciarTabuleiro(tabuleiro);

    criarJogador(players[VERDE], "VERDE", tabuleiro, VERDE, true);
    criarJogador(players[AZUL], "AZUL", tabuleiro, AZUL, true);
    criarJogador(players[AMARELO], "AMARELO", tabuleiro, AMARELO, true);
    criarJogador(players[VERMELHO], "VERMELHO", tabuleiro, VERMELHO, true);

    printTabuleiro(tabuleiro);

    int dado = 1;
    char opcao;

    int vezDe = VERDE;

    while(dado)
    {
            gotoxy(50, 10);
            cout << "          ";
                    gotoxy(50, 3);
        cout << "          ";

        gotoxy(50, 1);

        cout << "       ";

        gotoxy(50, 1);

        cout << players[0].nome << ": ";


        gotoxy(50, 2);

        cout << "       ";

        gotoxy(50, 2);
        cin >> opcao;

        if(getPlayer(opcao) == -1 || !players[getPlayer(opcao)].piece[posicaoPeca(players[getPlayer(opcao)], opcao)].estaEmJogo)
        {
            gotoxy(50, 10);
            cout << "INVALIDO";
            continue;
        }


        gotoxy(50, 3);
        cin >> dado;

        if(andarCasas(tabuleiro, dado, tolower(opcao), players) == 1)
        {
            if(players[getPlayer(opcao)].pecasEmJogo == 0)
            {
                cout << "GANOUkkkkkk";
                break;
            }
        }


    }

    printTabuleiro(tabuleiro);

    return 0;
}
