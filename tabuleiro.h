#ifndef TABULEIRO__H
#define TABULEIRO__H

#define LINHAS 17
#define COLUNAS 18

#define VERDE1 'g'
#define VERDE2 'h'
#define VERDE3 'j'
#define VERDE4 'k'

#define AMARELO1 'y'
#define AMALERO2 'u'
#define AMARELO3 'i'
#define AMALERO4 'o'

#define VERMELHO1 'r'
#define VERMELHO2 't'
#define VERMELHO3 'w'
#define VERMELHO4 'q'

#define AZUL1 'b'
#define AZUL2 'n'
#define AZUL3 'x'
#define AZUL4 'v'

#include "posicao.h"
#include "jogo.h"
/*
void criarJogador(char nome[], Player players, int jogador, char tabuleiro[LINHAS][COLUNAS])
{
    for(int i = 0; i < 4; i++)
    {
        players[jogador].piece[j].letra = '-';
        int x = players[jogador].piece[i].posicao_linha
        tabuleiro[]



    }
}
*/

void iniciarTabuleiro(char tabuleiro[LINHAS][COLUNAS]){


    FILE * file = fopen("tabuleiro.txt", "r");


    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = fgetc(file);
        }
    }

    fclose(file);




}
void printTabuleiro(char tabuleiro[LINHAS][COLUNAS]){
    cout << " ";
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){


            char temp = tabuleiro[i][j];

            if(temp == '1' || temp == '2' || temp == '6' || temp == '4')
            {

                textcolor((int) temp);
                cout << "██";

            }
            else
            {
                char verde[] = "ghjkGHJK";
                char amarelo[] = "yuioYUIO";
                char vermelho[] = "rtqwRTQW";
                char azul[] = "bnxvNBXV";

                textbackground(0);
                textcolor(WHITE);
                if(temp == 'e')
                    cout << "┌─";
                else if(temp == 'a')
                    cout << "┘ ";
                else if(temp == 'm')
                    cout << "└─";
                else if(temp == 'd')
                    cout << "┐ ";
                else if(temp == '*')
                    cout << "──";
                else if(temp == '+')
                    cout << "│ ";
                else if(indexOf(amarelo, temp) != -1)
                {
                    textcolor(BROWN);
                    cout << temp << " ";
                }
                else if(indexOf(azul, temp) != -1)
                {
                    textcolor(BLUE);
                    cout << temp << " ";
                }
                else if(indexOf(vermelho, temp) != -1)
                {
                    textcolor(RED);
                    cout << temp << " ";
                }
                else if(indexOf(verde, temp) != -1)
                {
                    textcolor(GREEN);
                    cout << temp << " ";
                }
                else
                    cout << temp << " ";

            }

        }
    }
    cout << endl;


}



#endif // TABULEIRO__H
