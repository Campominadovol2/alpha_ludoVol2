#ifndef POS__H
#define POS__H

#include "tabuleiro.h"
#include "jogo.h"

int coord[52][2] = {{1, 7},
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
                     {2, 7}};
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

    for(int i = 0; i < 4; i++)
    {
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
    }
}

void printarQuadrado(int x, int y, int cor)
{
    textcolor(cor);
    gotoxy(x, y);
    cout << "██";
}

COLORS getColor(Cor p)
{
    if(p == AMARELO)
        return BROWN;
    if(p == AZUL)
        return BLUE;
    if(p == VERDE)
        return GREEN;
    return RED;
}

void atualizarPosicao(int linha, int coluna, int newLinha, int newColuna, char tabuleiro[LINHAS][COLUNAS], Player players[])
{

    char temp = tabuleiro[linha][coluna];
    int p = getPlayer(temp);

    tabuleiro[linha][coluna] = '-';

    if(linha == 6 && coluna == 2)
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

}


void andarCasas(char tabuleiro[LINHAS][COLUNAS], int numDeCasas, char letra, Player players[])
{
    int player = getPlayer(letra);
    int peca = posicaoPeca(players[player], letra);

    int linha, coluna, coordenada, novaLinha, novaColuna;

    if(players[player].piece[peca].estaNaPosicaoInicial == true)
    {
        if(numDeCasas != 6)
            return;

        coordenada = players[player].piece[peca].coordenadaDeSaida;
        players[player].piece[peca].coordenada = coordenada;

        linha = players[player].piece[peca].posicao_linha;
        coluna = players[player].piece[peca].posicao_coluna;

        novaLinha  = coord[coordenada][0];
        novaColuna = coord[coordenada][1];

        atualizarPosicao(linha, coluna, novaLinha, novaColuna, tabuleiro, players);
        delay(500);
        return;
    }

    linha  = coord[coordenada][0];
    coluna = coord[coordenada][1];

    novaLinha  = coord[coordenada + 1][0];
    novaColuna = coord[coordenada + 1][1];


    atualizarPosicao(linha, coluna, novaLinha, novaColuna, tabuleiro, players);
    delay(500);

    for(int i = 1; i <= numDeCasas; i++)
    {
        players[player].piece[peca].coordenada = coordenada + i;

        linha =  coord[coordenada + i - 1][0];
        coluna = coord[coordenada + i - 1][1];

        novaLinha  = coord[coordenada + i][0];
        novaColuna = coord[coordenada + i][1];

        atualizarPosicao(linha, coluna, novaLinha, novaColuna, tabuleiro, players);
        delay(500);

    }
}



#endif // POS__H
