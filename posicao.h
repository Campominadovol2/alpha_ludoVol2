#ifndef POS__H
#define POS__H


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

void atualizarPosicao(int linha, int coluna, int newLinha, int newColuna, char tabuleiro[LINHAS][COLUNAS], Player players[])
{

    char temp = tabuleiro[linha][coluna];
    int p = (getPlayer(temp));

    players[p].piece[posicaoPeca(players[p], temp)].posicao_coluna = newColuna;
    players[p].piece[posicaoPeca(players[p], temp)].posicao_linha = newLinha;

    tabuleiro[linha][coluna] = '-';

    if(linha == 6 && coluna == 2)
    {
        tabuleiro[linha][coluna] = '2';
    }
    else if(linha == 9 && coluna == 14)
    {
        tabuleiro[linha][coluna] = '1';
    }
    else if(linha == 14 && coluna == 7)
    {
        tabuleiro[linha][coluna] = '4';
    }
    else if(linha == 2 && coluna == 9)
    {
        tabuleiro[linha][coluna] = '6';
    }

    tabuleiro[newLinha][newColuna] = temp;


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



#endif // POS__H
