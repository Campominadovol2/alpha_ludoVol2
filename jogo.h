
#ifndef JOGO__H
#define JOGO__H

#include "tabuleiro.h"
#include "posicao.h"


typedef enum Cor
{
    VERDE,
    AMARELO,
    VERMELHO,
    AZUL
} Cor;

typedef struct
{
    int coordenada;
    int coordenadaDeSaida;
    int coordenadaDeEntrada;
    int primeiraCasaDeCor;
    bool estaNaPosicaoInicial;
    int posicao_linha;
    int posicao_coluna;
    bool ehTorre;
    Cor cor;
    char letra;

}Piece; //Peça

typedef struct
{
    Piece piece[4];
    char nome[20];
    Cor cor;

}Player;

static void atualizarLetrasPieces(Player players[], char tabuleiro[LINHAS][COLUNAS])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            players[i].piece[j].letra = tabuleiro[players[i].piece[j].posicao_linha][players[i].piece[j].posicao_coluna];
        }
    }
}


void iniciarPieces(Player players[], char tabuleiro[LINHAS][COLUNAS])
{

    strcpy_s(players[0].nome, "VERDE");
    strcpy_s(players[1].nome, "AMARELO");
    strcpy_s(players[2].nome, "VERMELHO");
    strcpy_s(players[3].nome, "AZUL");

    for(int i = 0; i < 4; i++)
    {

       for(int j = 0; j < 4; j++)
       {
           players[i].piece[j].ehTorre = 0;
           players[i].piece[j].cor = (Cor) i;
           players[i].piece[j].coordenada = -1;

       }
    }
    int j;
    Cor cor;

    j = 0;

    cor = VERDE;
    players[cor].piece[j++].posicao_linha = 3;
    players[cor].piece[j++].posicao_linha = 3;
    players[cor].piece[j++].posicao_linha = 4;
    players[cor].piece[j++].posicao_linha = 4;

    j = 0;
    players[cor].piece[j++].posicao_coluna = 3;
    players[cor].piece[j++].posicao_coluna = 4;
    players[cor].piece[j++].posicao_coluna = 3;
    players[cor].piece[j++].posicao_coluna = 4;

    j = 0;
    cor = AMARELO;

    players[cor].piece[j++].posicao_linha = 3;
    players[cor].piece[j++].posicao_linha = 3;
    players[cor].piece[j++].posicao_linha = 4;
    players[cor].piece[j++].posicao_linha = 4;

    j = 0;
    players[cor].piece[j++].posicao_coluna = 12;
    players[cor].piece[j++].posicao_coluna = 13;
    players[cor].piece[j++].posicao_coluna = 12;
    players[cor].piece[j++].posicao_coluna = 13;

    j = 0;
    cor = VERMELHO;

    players[cor].piece[j++].posicao_linha = 12;
    players[cor].piece[j++].posicao_linha = 12;
    players[cor].piece[j++].posicao_linha = 13;
    players[cor].piece[j++].posicao_linha = 13;

    j = 0;
    players[cor].piece[j++].posicao_coluna = 3;
    players[cor].piece[j++].posicao_coluna = 4;
    players[cor].piece[j++].posicao_coluna = 3;
    players[cor].piece[j++].posicao_coluna = 4;


    j = 0;
    cor = AZUL;

    players[cor].piece[j++].posicao_linha = 12;
    players[cor].piece[j++].posicao_linha = 12;
    players[cor].piece[j++].posicao_linha = 13;
    players[cor].piece[j++].posicao_linha = 13;

    j = 0;
    players[cor].piece[j++].posicao_coluna = 12;
    players[cor].piece[j++].posicao_coluna = 13;
    players[cor].piece[j++].posicao_coluna = 12;
    players[cor].piece[j++].posicao_coluna = 13;

    atualizarLetrasPieces(players, tabuleiro);

    for(int j = 0; j < 4; j++)
    {
            players[AMARELO].piece[j].estaNaPosicaoInicial = true;
            players[AMARELO].piece[j].coordenadaDeSaida = 3;
            players[AMARELO].piece[j].coordenadaDeEntrada = 1;
            players[AMARELO].piece[j].primeiraCasaDeCor = 52;


            players[AZUL].piece[j].estaNaPosicaoInicial = true;
            players[AZUL].piece[j].coordenadaDeSaida = 16;
            players[AZUL].piece[j].coordenadaDeEntrada = 14;
            players[AZUL].piece[j].primeiraCasaDeCor = 59;

            players[VERMELHO].piece[j].estaNaPosicaoInicial = true;
            players[VERMELHO].piece[j].coordenadaDeSaida = 29;
            players[VERMELHO].piece[j].coordenadaDeEntrada = 27;
            players[VERMELHO].piece[j].primeiraCasaDeCor = 66;

            players[VERDE].piece[j].estaNaPosicaoInicial = true;
            players[VERDE].piece[j].coordenadaDeSaida = 42;
            players[VERDE].piece[j].coordenadaDeEntrada = 40;
            players[VERDE].piece[j].primeiraCasaDeCor = 73;

    }


}



#endif // JOGO__H
