
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
    bool estaEmJogo;
    int posicao_linha;
    int posicao_coluna;
    bool ehTorre;
    Cor cor;
    char letra;

}Piece; //Peça

typedef struct
{
    int pecasEmJogo;
    bool vaiJogar;
    Piece piece[4];
    char nome[20];
    Cor cor;

}Player;

static void atualizarLetrasPieces(Player & p, char tabuleiro[LINHAS][COLUNAS])
{
    for(int j = 0; j < 4; j++)
    {
        if(p.vaiJogar)
            p.piece[j].letra = tabuleiro[p.piece[j].posicao_linha][p.piece[j].posicao_coluna];
        else
        {
            tabuleiro[p.piece[j].posicao_linha][p.piece[j].posicao_coluna] = '-';
            p.piece[j].letra = '-';
        }

    }


}

static void iniciarVerde(Player & p, char tabuleiro[LINHAS][COLUNAS])
{
    int j = 0;
    p.piece[j++].posicao_linha = 3;
    p.piece[j++].posicao_linha = 3;
    p.piece[j++].posicao_linha = 4;
    p.piece[j++].posicao_linha = 4;

    j = 0;
    p.piece[j++].posicao_coluna = 3;
    p.piece[j++].posicao_coluna = 4;
    p.piece[j++].posicao_coluna = 3;
    p.piece[j++].posicao_coluna = 4;

    for(j = 0; j < 4; j++)
    {
        p.piece[j].estaNaPosicaoInicial = true;
        p.piece[j].coordenadaDeSaida = 42;
        p.piece[j].coordenadaDeEntrada = 40;
        p.piece[j].primeiraCasaDeCor = 73;
        p.piece[j].estaEmJogo = p.vaiJogar;

    }

    atualizarLetrasPieces(p, tabuleiro);
}

static void iniciarAmarelo(Player & p, char tabuleiro[LINHAS][COLUNAS])
{
    int j = 0;
    p.piece[j++].posicao_linha = 3;
    p.piece[j++].posicao_linha = 3;
    p.piece[j++].posicao_linha = 4;
    p.piece[j++].posicao_linha = 4;

    j = 0;
    p.piece[j++].posicao_coluna = 12;
    p.piece[j++].posicao_coluna = 13;
    p.piece[j++].posicao_coluna = 12;
    p.piece[j++].posicao_coluna = 13;

    for(j = 0; j < 4; ++j)
    {
        p.piece[j].estaNaPosicaoInicial = true;
        p.piece[j].coordenadaDeSaida = 3;
        p.piece[j].coordenadaDeEntrada = 1;
        p.piece[j].primeiraCasaDeCor = 52;
        p.piece[j].estaEmJogo = p.vaiJogar;


    }

    atualizarLetrasPieces(p, tabuleiro);
}

static void iniciarAzul(Player & p, char tabuleiro[LINHAS][COLUNAS])
{
    int j = 0;
    p.piece[j++].posicao_linha = 12;
    p.piece[j++].posicao_linha = 12;
    p.piece[j++].posicao_linha = 13;
    p.piece[j++].posicao_linha = 13;

    j = 0;
    p.piece[j++].posicao_coluna = 12;
    p.piece[j++].posicao_coluna = 13;
    p.piece[j++].posicao_coluna = 12;
    p.piece[j++].posicao_coluna = 13;

    for(j = 0; j < 4; j++)
    {

        p.piece[j].estaNaPosicaoInicial = true;
        p.piece[j].coordenadaDeSaida = 16;
        p.piece[j].coordenadaDeEntrada = 14;
        p.piece[j].primeiraCasaDeCor = 59;
        p.piece[j].estaEmJogo = p.vaiJogar;

    }

    atualizarLetrasPieces(p, tabuleiro);

}

static void iniciarVermelho(Player & p, char tabuleiro[LINHAS][COLUNAS])
{
    int j = 0;

    p.piece[j++].posicao_linha = 12;
    p.piece[j++].posicao_linha = 12;
    p.piece[j++].posicao_linha = 13;
    p.piece[j++].posicao_linha = 13;

    j = 0;
    p.piece[j++].posicao_coluna = 3;
    p.piece[j++].posicao_coluna = 4;
    p.piece[j++].posicao_coluna = 3;
    p.piece[j++].posicao_coluna = 4;

    for(j = 0; j < 4; j++)
    {
        p.piece[j].estaNaPosicaoInicial = true;
        p.piece[j].coordenadaDeSaida = 29;
        p.piece[j].coordenadaDeEntrada = 27;
        p.piece[j].primeiraCasaDeCor = 66;
        p.piece[j].estaEmJogo = p.vaiJogar;

    }

    atualizarLetrasPieces(p, tabuleiro);
}

void criarJogador(Player & p, char nome[], char tabuleiro[LINHAS][COLUNAS], int pn, bool vaiJogar)
{
    strcpy(p.nome, nome);
    p.pecasEmJogo = 4;
    p.vaiJogar = vaiJogar;

    for(int j = 0; j < 4; j++)
    {
           p.piece[j].ehTorre = 0;
           p.piece[j].cor = (Cor) pn;
           p.piece[j].coordenada = -1;

    }

    if(pn == VERDE)
        iniciarVerde(p, tabuleiro);
    else if(pn == AMARELO)
        iniciarAmarelo(p, tabuleiro);
    else if(pn == VERMELHO)
        iniciarVermelho(p, tabuleiro);
    else if(pn == AZUL)
        iniciarAzul(p, tabuleiro);

}



#endif // JOGO__H
