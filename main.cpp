#include <iostream>
#include "gconio.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

#include "tabuleiro.h"
#include "posicao.h"
#include "jogo.h"


int main()
{
    system("chcp 65001");
    clrscr();

    char tabuleiro[LINHAS][COLUNAS];
    Player players[4];

    iniciarTabuleiro(tabuleiro);
    iniciarPieces(players, tabuleiro);
    printTabuleiro(tabuleiro);

    char opcao;
    cin >> opcao;

    int dado;
    cin >> dado;

    andarCasas(tabuleiro, dado, opcao, players);
    gotoxy(1, 20);

    system("pause");
    clrscr();
    printTabuleiro(tabuleiro);


    gotoxy(1, 25);

    return 0;
}
