#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "tabuleiro.h"
#include "posicao.h"
#include "jogo.h"


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



int indexOf(char str[], char ch)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ch)
            return i;
    }
    return -1;
}

int getPlayer(char letra)
{
    char verde[] = "ghjkGHJK";
    char amarelo[] = "yuioYUIO";
    char vermelho[] = "rtqwRTQW";
    char azul[] = "bncvNBCV";

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



#endif // AUXILIARES_H
