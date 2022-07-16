#include <iostream>
#include <conio2.h>
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




    //Percorre todas as peças de um jogador e retorna a posição da peça
    cout << players[VERDE].nome <<  ", digite a peça que deseja mexer: ";
    char opcao;
    cin >> opcao;


    int x = posicaoPeca(players[VERDE], opcao);

    //Na struct Pieces, cada peça tem sua posição de linha e coluna
    //Para obter, é só seguir os seguintes passos:
    //Vc chama o vetor players na posiçao q vc quer, no exemplo é verde,
    //e pega o atributo piece[x].linha, onde esse x é o indice da peça que vc quer a posição
    int y = players[VERDE].piece[x].posicao_linha;
    int z = players[VERDE].piece[x].posicao_coluna;

    //Atualizaar posição é assim:
    //vc passa os seguintes argumentos em ordem:
    //A posicao atual de linha
    //A posicao atual da coluna
    //A Nova posicao da Linha
    //A nova posicao da coluna
    //A matriz do tabuleiro
    //O vetor de players

    atualizarPosicao(y, z, y, z + 1, tabuleiro, players);
    printTabuleiro(tabuleiro);




    return 0;
}
