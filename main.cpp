#include <iostream>
#include "gconio.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <windows.h>

#define DELAY 150

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
    iniciarPieces(players, tabuleiro);

    /*removerJogador(players[VERDE], tabuleiro);
    removerJogador(players[AZUL], tabuleiro);*/

    printTabuleiro(tabuleiro);

    char opcao;
    cin >> opcao;

    int dado;
    cin >> dado;

    andarCasas(tabuleiro, dado, opcao, players);

    while(dado != 0)
    {
        gotoxy(1, 20);

        cin >> opcao;
        cin >> dado;

        andarCasas(tabuleiro, dado, opcao, players);

    }

    return 0;
}
