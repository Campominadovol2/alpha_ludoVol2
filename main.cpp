#include <iostream>
#include "./Bibliotecas/gconio.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <time.h>

#define DEBUG 0
#define DELAY 0

using namespace std;

#include "./Bibliotecas/tabuleiro.h"
#include "./Bibliotecas/posicao.h"
#include "./Bibliotecas/jogo.h"
#include "./Bibliotecas/auxiliares.h"
#include "./Bibliotecas/random.h"
#include "./Bibliotecas/analisador.h"
#include "./Bibliotecas/desenhos.h"

int pecasNoInicio(Player p);

void posicionarCursorNoMeio();
void darZoom(int a);
int vezDoProximo(int vezAtual, Player p[]);
void sequencial(int num, int vetor[]);
int iniciarJogo(int mode);

void logo();
int menuInicial();
int menuInicial2();
int menuDeAjuda();
int selecionarNumDePlayers();

const int x = 27;

int COR_FUNDO = BLACK;
int COR_LETRA = WHITE;

int main()
{
    // srand(time(NULL));
    darZoom(7);

#ifdef _WIN32
    system("chcp 65001");
    system("MODE con cols=80 lines=22");
#endif
    clrscr();

    while(menuInicial() == 1);


}

int menuInicial()
{
    logo();
    gotoxy(x, 11);
    printf("  Iniciar ludo");
    gotoxy(x, 12);
    printf("  Encerrar");
    int opc = selecionar_opcao(27, 11, 2);

    switch (opc)
    {
    case 1:
        return menuInicial2();
    case 2:
        return 0;
    }
    return -1;
}

int menuInicial2()
{
    logo();
    gotoxy(x, 11);
    printf("  Jogar");
    gotoxy(x, 12);
    printf("  Tutorial");
    gotoxy(x, 13);
    printf("  Retroceder");
    int opc = selecionar_opcao(27, 11, 3);
    int i, temp;

    switch (opc)
    {
    case 1:
        i = selecionarNumDePlayers();
        if(i == 4)
        {
            return menuInicial2();
        }
        temp = iniciarJogo(i + 1);
        return menuInicial2();
    case 2:
        return menuDeAjuda();
    case 3:
        return menuInicial();
    }
    return -1;
}

int selecionarNumDePlayers()
{
    logo();
    gotoxy(x, 11);
    printf("  2 Jogadores");
    gotoxy(x, 12);
    printf("  3 Jogadores");
    gotoxy(x, 13);
    printf("  4 Jogadores");
    gotoxy(x, 14);
    printf("  Retroceder");
    gotoxy(x, 15);
    return selecionar_opcao(27, 11, 4);
}

int menuDeAjuda()
{
    printf("  Dicas e ajuda");
    gotoxy(x, 12);
    printf("  Regras");
    gotoxy(x, 13);
    printf("  Retroceder");
    int opc = selecionar_opcao(27, 11, 3);

    switch (opc)
    {
    case 1:
        clrscr();
        logo();
        gotoxy(x - 10, 11);
        printf("  Apos o primeiro sorteio seja sorteado 3 vezes ");
        gotoxy(x - 10, 12);
        printf("  o numero 6 perde-se a vez.");
        gotoxy(x - 10, 13);
        printf("  Vence o jogo quem por 4 tokiens na casa primeiro.");
        gotoxy(x - 10, 14);
        printf("  Retroceder");
        gotoxy(x, 15);
        break;
    case 2:
        clrscr();
        logo();
        gotoxy(x - 10, 11);
        printf("  1 - 6 e o unico numero capaz de tirar um tokien da casa.");
        gotoxy(x - 10, 12);
        printf("  2 - ");
        gotoxy(x - 10, 13);
        printf("  3 - ");
        gotoxy(x - 10, 14);
        printf("  Retroceder");
        gotoxy(x, 15);
        break;
    case 3:
        return menuInicial2();
    }

    getch();

    return menuDeAjuda();
}


void logo()
{
    textbackground(COR_FUNDO);
    textcolor(COR_LETRA);
    desenhar_quadrado(80, 22, 0, 0);
    //...
    gotoxy(x, 3);
    printf(" _     _    _ _____   ____  ");
    gotoxy(x, 4);
    printf("| |   | |  | |  __ \\ / __ \\ ");
    gotoxy(x, 5);
    printf("| |   | |  | | |  | | |  | |");
    gotoxy(x, 6);
    printf("| |   | |  | | |  | | |  | |");
    gotoxy(x, 7);
    printf("| |___| |__| | |__| | |__| |");
    gotoxy(x, 8);
    printf("|______\\____/|_____/ \\____/");
    gotoxy(56, 20);
    printf("copyright(c) by grupo01");
}

int iniciarJogo(int mode)
{   
    clrscr();

    char tabuleiro[LINHAS][COLUNAS];
    Player players[4];
    iniciarTabuleiro(tabuleiro);

    int numplayers;
    int vezDe;

    if (mode == 2)
    {
        /// Cria��o dos jogares. Isso n�o pode sair do programa
        /// Passa o jogador que vc quer criar, o nome dele, o tabuleiro e se ele vai ou n�o jogar;
        /// A� vc faz um jeito de perguntar quantos v�o jogar e atribui o ultimo elemento com true ou false

        // DOIS PLAYERS
        criarJogador(players[VERDE], "VERDE", tabuleiro, VERDE, false);
        criarJogador(players[AZUL], "AZUL", tabuleiro, AZUL, false);
        criarJogador(players[AMARELO], "AMARELO", tabuleiro, AMARELO, true);
        criarJogador(players[VERMELHO], "VERMELHO", tabuleiro, VERMELHO, true);
        numplayers = 2;
        vezDe = 2;
    }
    else if (mode == 3)
    {
        // TRES PLAYERS
        criarJogador(players[VERDE], "VERDE", tabuleiro, VERDE, true);
        criarJogador(players[AZUL], "AZUL", tabuleiro, AZUL, false);
        criarJogador(players[AMARELO], "AMARELO", tabuleiro, AMARELO, true);
        criarJogador(players[VERMELHO], "VERMELHO", tabuleiro, VERMELHO, true);
        numplayers = 3;
        vezDe = 2;
    }
    else if (mode == 4)
    {
        // QUATRO PLAYERS
        criarJogador(players[VERDE], "VERDE", tabuleiro, VERDE, true);
        criarJogador(players[AZUL], "AZUL", tabuleiro, AZUL, true);
        criarJogador(players[AMARELO], "AMARELO", tabuleiro, AMARELO, true);
        criarJogador(players[VERMELHO], "VERMELHO", tabuleiro, VERMELHO, true);
        numplayers = 4;
        vezDe = 2;
    }

    printTabuleiro(tabuleiro);

    // LACOS DE PARTIDA
    desenhar_quadrado(40, 17, 35, 0);
    while (1)
    {
        size_t size;
        int *vetor = sortearDados(size);

        if (contarNum6(vetor, size) == 3)
        {
            continue;
        }

        for (int i = 0; i < size; i++)
        {
            textcolor(15);
            desenhar_quadrado(40, 17, 35, 0);
            desenhar_quadrado(74, 3, 1, 17);

            // apenas exemplo
            gotoxy(10, 18);
            cout << "Tokens que ja finalizaram: 2    Tokens sobrepostos: ";

            


            atualizarSobreposicao(players);



            gotoxy(42, 1);
            cout << "Vez de " << players[vezDe].nome;
            desenhar_linha_horizontal(37, 2, 36);
            viewvector(vetor, size, 39, 3);

            gotoxy(39, 6);
            cout << "Selecione o token: ";
            char temp = selecionartoken(players[vezDe], vetor, size);
            // desenhar_quadrado(40, 20, 35, 0);
            preencher_com_espacos(38, 10, 36, 5);

            int dado;

            if (qtddDeNumeros(vetor, size) == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    dado = vetor[i];
                    if (dado != 0)
                    {
                        break;
                    }
                }
            }
            else
            {
                gotoxy(39, 6);
                cout << "Selecione o numero: ";
                dado = selecionarNumero(vetor, size, temp, players[vezDe]);
            }

            int r = andarCasas(tabuleiro, dado, temp, players);

            for (int i = 0; i < size; i++)
            {
                if (vetor[i] == dado)
                {
                    vetor[i] = 0;
                    break;
                }
            }

            if (r == -2 || r == 1)
            {
                vetor = sortearDados(size, vetor);
            }

            if (players[vezDe].pecasEmJogo == 0)
            {
                cout << "VITORIA";
                return 0;
            }
        }

        vezDe = vezDoProximo(vezDe, players);
        free(vetor);
    }

    printTabuleiro(tabuleiro);

    return 0;
}

#ifdef _WIN32
void posicionarCursorNoMeio()
{
    SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);
}

void darZoom(int a)
{
    keybd_event(VK_LCONTROL, 0x36, 0, 0);

    for (int i = 0; i < a; i++)
    {
        posicionarCursorNoMeio();
        mouse_event(MOUSEEVENTF_WHEEL, MOUSEEVENTF_ABSOLUTE, MOUSEEVENTF_ABSOLUTE, WHEEL_DELTA, 0);
    }
    keybd_event(VK_LCONTROL, 0x1C, KEYEVENTF_KEYUP, 0);
}

#else

void posicionarCursorNoMeio()
{
}

void darZoom(int a)
{
}

#endif

int pecasNoInicio(Player p)
{
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        if (p.piece[i].estaNaPosicaoInicial)
            temp++;
    }
    return temp;
}

int vezDoProximo(int vezAtual, Player p[])
{
    /*vezDoProximo recebe o jogador da vez e o vetor de jogadores
    retorna o proximo a jogar*/
    int resultado;
    if (vezAtual == VERMELHO)
        vezAtual = -1;

    for (int i = vezAtual + 1; i < 4; i++)
    {
        if (i == 2)
        {
            if (p[AZUL].vaiJogar)
                return AZUL;
            else
                continue;
        }

        else if (i == 3)
        {
            if (p[VERMELHO].vaiJogar)
                return VERMELHO;
            else
                i = -1;
        }
        else
        {
            if (p[i].vaiJogar)
                return i;
        }
    }

    return -1;
}

void sequencial(int num, int vetor[])
{
    if (num == 2)
    {
        vetor[0] = 2;
        vetor[1] = 1;
    }
    else if (num == 3)
    {
        vetor[0] = 2;
        vetor[1] = 0;
        vetor[2] = 1;
    }
    else
    {
        vetor[0] = 2;
        vetor[1] = 0;
        vetor[2] = 1;
        vetor[3] = 3;
    }
}