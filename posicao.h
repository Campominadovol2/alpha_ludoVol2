#ifndef POS__H
#define POS__H

#include "tabuleiro.h"
#include "jogo.h"

const int coord[][2] = {{1, 7},
                     {1, 8},
                     {1, 9},
                     //linha de cima

                     {2, 9},
                     {3, 9},
                     {4, 9},
                     {5, 9},
                     {6, 9},
                     //primeira coluna

                     {7, 10},
                     {7, 11},
                     {7, 12},
                     {7, 13},
                     {7, 14},
                     {7, 15},
                     //primeira linha direira

                     {8, 15},
                     {9, 15},
                     //segunda coluna direita

                     {9, 14},
                     {9, 13},
                     {9, 12},
                     {9, 11},
                     {9, 10},
                     //segunda linha direita

                     {10, 9},
                     {11, 9},
                     {12, 9},
                     {13, 9},
                     {14, 9},
                     {15, 9},
                     //terceira coluna direira

                     {15, 8},
                     {15, 7},
                     //linha inferior

                     {14, 7},
                     {13, 7},
                     {12, 7},
                     {11, 7},
                     {10, 7},
                     //terceira coluna esquerda

                     {9, 6},
                     {9, 5},
                     {9, 4},
                     {9, 3},
                     {9, 2},
                     {9, 1},
                     //segunda linha esquerda

                     {8, 1},
                     {7, 1},
                     //segunda coluna esquerda

                     {7, 2},
                     {7, 3},
                     {7, 4},
                     {7, 5},
                     {7, 6},
                     //primeira linha esquerda

                     {6, 7},
                     {5, 7},
                     {4, 7},
                     {3, 7},
                     {2, 7},

                    { 2, 8 }, {3, 8}, {4, 8}, {5, 8}, {6 , 8}, {7, 8}, {8, 8},
                    { 8, 14}, {8, 13}, {8, 12}, {8, 11}, {8, 10}, {8, 9}, {8 , 8},
                    { 14, 8}, {13, 8}, {12, 8}, {11, 8}, {10 , 8}, {9, 8}, {8, 8},
                    { 8, 2}, { 8, 3}, {8, 4}, {8 , 5}, {8 , 6}, {8 , 7}, {8, 8}

};
                     //primeira coluna esquerda};

char getLetra(Player p, int posicao)
{
    return p.piece[posicao].letra;
}

int indexOf(char str[], char ch)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ch)
            return i;
    }
    return -1;
}

int posicaoPeca(Player p, char l)
{
    for(int i = 0; i < 4; i++)
    {
        if(p.piece[i].letra == l)
        {
            return i;
        }
    }
    return -1;
}


int getPlayer(char letra)
{
    char verde[] = "ghjkGHJK";
    char amarelo[] = "yuioYUIO";
    char vermelho[] = "rtqwRTQW";
    char azul[] = "bnxvNBXV";

        if(indexOf(verde, letra) != -1)
        {
            return 0;
        }
        if(indexOf(amarelo, letra) != -1)
        {
            return 1;
        }
        if(indexOf(vermelho, letra) != -1)
        {
            return 2;
        }
        if(indexOf(azul, letra) != -1)
        {
            return 3;
        }
    return -1;

}

void printarQuadrado(int x, int y, int cor)
{
    textcolor(cor);
    gotoxy(x, y);
    cout << "██";
}

int getColor(Cor p)
{
    if(p == AMARELO)
        return BROWN;
    if(p == AZUL)
        return BLUE;
    if(p == VERDE)
        return GREEN;
    return RED;
}

void atualizarPosicao(int linha, int coluna, int newLinha, int newColuna, char tabuleiro[LINHAS][COLUNAS], Player players[], bool ehUltimaVolta)
{

    char temp = tabuleiro[linha][coluna];
    int p = getPlayer(temp);
    char temp2 = tabuleiro[newLinha][newColuna];
    if(ehUltimaVolta)
    {

        int corDoProximo = getPlayer(temp2);

        if(corDoProximo != -1)
        {
            if(corDoProximo != getPlayer(temp))
            {
                int p2 = posicaoPeca(players[corDoProximo], temp2);
                int x = players[corDoProximo].piece[p2].posicao_linha;
                int y = players[corDoProximo].piece[p2].posicao_coluna;
                players[corDoProximo].piece[p2].estaNaPosicaoInicial = true;

                players[corDoProximo].piece[p2].coordenada = -1;
                tabuleiro[x][y] = temp2;

                textcolor( (int) getColor( (Cor)getPlayer(tabuleiro[x][y])));

                gotoxy(y * 2 + 1, x);
                cout << tabuleiro[x][y] << " ";
            }



        }
    }


    /*if(players[p].piece[posicaoPeca(players[p], temp2)].ehTorre)
    {
        return;
    }*/

    tabuleiro[linha][coluna] = '-';

    if(linha == 7 && coluna == 2)
    {
        tabuleiro[linha][coluna] = '2';
        printarQuadrado(coluna * 2 + 1, linha, 2);
    }
    else if(linha == 9 && coluna == 14)
    {
        tabuleiro[linha][coluna] = '1';
        printarQuadrado(coluna * 2 + 1, linha, 1);
    }
    else if(linha == 14 && coluna == 7)
    {
        tabuleiro[linha][coluna] = '4';
        printarQuadrado(coluna * 2+ 1, linha, 4);
    }
    else if(linha == 2 && coluna == 9)
    {
        tabuleiro[linha][coluna] = '6';
        printarQuadrado(coluna * 2 + 1, linha, 6);
    }
    else
    {
        textcolor(WHITE);
        gotoxy(coluna * 2 + 1, linha);
        cout << "- ";

        textcolor(getColor( (Cor) p));
        gotoxy(newColuna * 2 + 1, newLinha);
        cout << temp << " ";
    }

    tabuleiro[newLinha][newColuna] = temp;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(players[i].piece[j].coordenada != -1)
            {
                int x = coord[players[i].piece[j].coordenada][0];
                int y = coord[players[i].piece[j].coordenada][1];

                tabuleiro[x][y] = players[i].piece[j].letra;
                textcolor( (int) getColor( (Cor)getPlayer(tabuleiro[x][y])));

                gotoxy(y * 2 + 1, x);
                cout << tabuleiro[x][y] << " ";

            }

        }
    }

}


int andarCasas(char tabuleiro[LINHAS][COLUNAS], int numDeCasas, char letra, Player players[])
{
    int player = getPlayer(letra);
    int peca = posicaoPeca(players[player], letra);

    int coordenada, linha, coluna, novaLinha, novaColuna;

    if(players[player].piece[peca].estaNaPosicaoInicial)
    {
        if(numDeCasas != 6)
            return -1;

        coordenada = players[player].piece[peca].coordenadaDeSaida;
        players[player].piece[peca].coordenada = coordenada;

        linha = players[player].piece[peca].posicao_linha;
        coluna = players[player].piece[peca].posicao_coluna;

        novaLinha  = coord[coordenada][0];
        novaColuna = coord[coordenada][1];

        atualizarPosicao(linha, coluna, novaLinha, novaColuna, tabuleiro, players, false);
        players[player].piece[peca].estaNaPosicaoInicial = false;
        return - 1;
    }

    for(int i = 0; i < numDeCasas; i++)
    {
        coordenada = players[player].piece[peca].coordenada;

        if(coordenada == players[player].piece[peca].coordenadaDeEntrada)
        {

            linha  = coord[coordenada][0];
            coluna = coord[coordenada][1];

            coordenada = players[player].piece[peca].primeiraCasaDeCor;

            novaLinha  = coord[coordenada][0];
            novaColuna = coord[coordenada][1];

            players[player].piece[peca].coordenada = coordenada;

        }

        else if(coordenada == 51)
        {

            linha  = coord[coordenada][0];
            coluna = coord[coordenada][1];

            coordenada = 0;

            novaLinha  = coord[coordenada][0];
            novaColuna = coord[coordenada][1];

            players[player].piece[peca].coordenada = coordenada;
        }
        else
        {
            linha  = coord[coordenada][0];
            coluna = coord[coordenada][1];

            novaLinha  = coord[coordenada + 1][0];
            novaColuna = coord[coordenada + 1][1];

            players[player].piece[peca].coordenada = coordenada + 1;

        }

        atualizarPosicao(linha, coluna, novaLinha, novaColuna, tabuleiro, players, i + 1 == numDeCasas);

        if(novaColuna == 8 && novaLinha == 8)
        {
            return 1;
        }
        delay(100);
    }

    return 0;

}



#endif // POS__H
