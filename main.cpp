#include <iostream>
#include "gconio.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define DELAY 0

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
