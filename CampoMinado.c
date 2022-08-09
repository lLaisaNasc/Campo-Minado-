#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

int bombasInseridas = 0;
int linha, coluna;
int linhaUsuario, colunaUsuario;
int highScoresPontos[3] = {3, 2, 1};

char highScoresNomes[3][50] = {{"Laisa"},
                               {"Luis"},
                               {"Eduardo"}};

int m[7][7] = {{0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0}};

int n[7][7] = {{0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0}};

char telaInicio[7][90] = {{" _______ _______ __   __ _______ _______   __   __ ___ __    _ _______ ______  _______ "},
                          {"|       |   _   |  |_|  |       |       | |  |_|  |   |  |  | |   _   |      ||       |"},
                          {"|       |  |_|  |       |    _  |   _   | |       |   |   |_| |  |_|  |  _    |   _   |"},
                          {"|       |       |       |   |_| |  | |  | |       |   |       |       | | |   |  | |  |"},
                          {"|      _|       |       |    ___|  |_|  | |       |   |  _    |       | |_|   |  |_|  |"},
                          {"|     |_|   _   | ||_|| |   |   |       | | ||_|| |   | | |   |   _   |       |       |"},
                          {"|_______|__| |__|_|   |_|___|   |_______| |_|   |_|___|_|  |__|__| |__|______||_______|"}};

char telaFimdejogo[7][80] = {{" _______  _______  __   __  _______    _______  __   __  _______  ______  "},
                             {"|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ | "},
                             {"|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | || "},
                             {"|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_"},
                             {"|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |"},
                             {"|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |"},
                             {"|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|"}};

char telaNextStage[7][90] = {{"  __    _  _______  __   __  _______    _______  _______  _______  _______  _______ "},
                             {" |  |  | ||       ||  |_|  ||       |  |       ||       ||   _   ||       ||       |"},
                             {" |   |_| ||    ___||       ||_     _|  |  _____||_     _||  |_|  ||    ___||    ___|"},
                             {" |       ||   |___ |       |  |   |    | |_____   |   |  |       ||   | __ |   |___ "},
                             {" |  _    ||    ___| |     |   |   |    |_____  |  |   |  |       ||   ||  ||    ___|"},
                             {" | | |   ||   |___ |   _   |  |   |     _____| |  |   |  |   _   ||   |_| ||   |___ "},
                             {" |_|  |__||_______||__| |__|  |___|    |_______|  |___|  |__| |__||_______||_______|"}};

bool semBomba(int a)
{
    bool b = true;
    if (a == 9)
    {
        b = false;
    }
    return b;
}

void imprimePosicao(int x)
{
    if (x == 9)
    {
        printf("%c", 42);
    }
    else if (x == 0)
    {
        printf("%c", 95);
    }
    else
    {
        printf("%d", x);
    }
}

int retornaPosicao(int linha, int coluna)
{
    int aux = m[linha][coluna];
    return aux;
}

void imprimeJogoAtual()
{
    int posicaom;
    int posicaon;
    printf("    1   2   3   4   5   6   7\n");
    for (linha = 0; linha < 7; linha++)
    {
        int i = linha + 1;
        printf("  -----------------------------\n");
        printf("%d", i);
        for (coluna = 0; coluna < 7; coluna++)
        {
            printf(" | ");
            int posicaom = m[linha][coluna];
            int posicaon = n[linha][coluna];
            if (posicaon == 1)
            {
                imprimePosicao(posicaom);
            }
            else
            {
                printf("%c", 63);
            }
        }
        printf(" | ");
        printf("%d\n", i);
    }
    printf("  -----------------------------\n");
    printf("    1   2   3   4   5   6   7\n\n");
}

void placares()
{
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        int colocacao = i + 1;
        printf("[%d] - %s : %d\n\n", colocacao, highScoresNomes[i], highScoresPontos[i]);
    }
    system("pause");
    return;
}

void creditos()
{
    system("cls");

    printf("\n");
    printf("Desenvolvido por:\n");
    printf("Eduardo Lima\n");
    printf("Laisa K. Nascimento\n");
    printf("Luis Davi Kalewski\n");
    printf("\n");

    system("pause");
    return;
}

void gravarPlacar(int placar)
{
    system("cls");
    if (placar > highScoresPontos[0])
    {
        highScoresPontos[0] = placar;
        printf("Digite seu nome:   ");
        scanf("%s", &highScoresNomes[0]);
    }
    else
    {
        if (placar > highScoresPontos[1])
        {
            highScoresPontos[1] = placar;
            printf("Digite seu nome:   ");
            scanf("%s", &highScoresNomes[1]);
        }

        else
        {
            if (placar > highScoresPontos[2])
            {
                highScoresPontos[2] = placar;
                printf("Digite seu nome:   ");
                scanf("%s", &highScoresNomes[2]);
            }
        }
    }
}

int retornaLinha(char linha)
{
    int retorno = -1;
    if (linha == '1')
    {
        retorno = 0;
    }
    if (linha == '2')
    {
        retorno = 1;
    }
    if (linha == '3')
    {
        retorno = 2;
    }
    if (linha == '4')
    {
        retorno = 3;
    }
    if (linha == '5')
    {
        retorno = 4;
    }
    if (linha == '6')
    {
        retorno = 5;
    }
    if (linha == '7')
    {
        retorno = 6;
    }
    return retorno;
}

int retornaColuna(char coluna)
{
    int retorno = -1;
    if (coluna == '1')
    {
        retorno = 0;
    }
    if (coluna == '2')
    {
        retorno = 1;
    }
    if (coluna == '3')
    {
        retorno = 2;
    }
    if (coluna == '4')
    {
        retorno = 3;
    }
    if (coluna == '5')
    {
        retorno = 4;
    }
    if (coluna == '6')
    {
        retorno = 5;
    }
    if (coluna == '7')
    {
        retorno = 6;
    }
    return retorno;
}

void imprimeTelaInicio()
{
    system("cls");
    for (int linha = 0; linha < 7; linha++)
    {
        printf("\n");
        for (int coluna = 0; coluna < 90; coluna++)
        {
            printf("%c", telaInicio[linha][coluna]);
            Sleep(1);
        }
    }
    printf("\n\n\n");
    char iniciar;
    printf("Digite ENTER para continuar...");
    scanf("%c", &iniciar);
    system("cls");
}

void imprimeTelaFim()
{
    for (int linha = 0; linha < 7; linha++)
    {
        printf("\n");
        for (int coluna = 0; coluna < 80; coluna++)
        {
            printf("%c", telaFimdejogo[linha][coluna]);
            Sleep(1);
        }
    }
    printf("\n\n\n");
}

void imprimeNextStage()
{
    system("cls");
    for (int linha = 0; linha < 7; linha++)
    {
        printf("\n");
        for (int coluna = 0; coluna < 90; coluna++)
        {
            printf("%c", telaNextStage[linha][coluna]);
            Sleep(1);
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

bool posicionaBomba()
{
    bool x = false;
    int y = rand() % 4;
    if (y == 1)
    {
        x = true;
    }
    return x;
}

void limparMatriz()
{
    bombasInseridas = 0;
    for (int linha = 0; linha < 7; linha++)
    {
        for (int coluna = 0; coluna < 7; coluna++)
        {
            m[linha][coluna] = 0;
        }
    }
    for (int linha = 0; linha < 7; linha++)
    {
        for (int coluna = 0; coluna < 7; coluna++)
        {
            n[linha][coluna] = 0;
        }
    }
}

void inserirBombas()
{
    while (bombasInseridas != 10)
    {
        for (int linha = 0; linha < 7; linha++)
        {
            for (int coluna = 0; coluna < 7; coluna++)
            {
                int posicaoAtual = m[linha][coluna];
                if (bombasInseridas < 10)
                {
                    if (semBomba(posicaoAtual))
                    {
                        if (posicionaBomba())
                        {
                            m[linha][coluna] = 9;
                            bombasInseridas++;
                        }
                    }
                }
            }
        }
    }
}

void selecionouBomba()
{
    for (int linha = 0; linha < 7; linha++)
    {
        for (int coluna = 0; coluna < 7; coluna++)
        {
            if (m[linha][coluna] == 9)
            {
                n[linha][coluna] = 1;
            }
        }
    }
}

void numerarCasas()
{

    for (int linha = 0; linha < 7; linha++)
    {
        for (int coluna = 0; coluna < 7; coluna++)
        {
            int posicaoAtual = m[linha][coluna];
            if (semBomba(posicaoAtual))
            {
                // Caso 1 quina
                if (linha == 0 && coluna == 0)
                {
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 2 Quina
                if (linha == 0 && coluna == 6)
                {
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 3 Quina
                if (linha == 6 && coluna == 0)
                {
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 4 Quina
                if (linha == 6 && coluna == 6)
                {
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 5 Lado cima
                if (linha == 0 && coluna != 6 && coluna != 0)
                {
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 6 Lado Baixo
                if (linha == 6 && coluna != 0 && coluna != 6)
                {
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 7 Lado Esquerdo
                if (linha != 0 && linha != 6 && coluna == 0)
                {
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }

                // Caso 8 Lado Direito
                if (linha != 0 && linha != 6 && coluna == 6)
                {
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
                // Caso 9 Meio
                if (linha != 0 && linha != 6 && coluna != 0 && coluna != 6)
                {
                    if (m[linha][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha + 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna + 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                    if (m[linha - 1][coluna - 1] == 9)
                    {
                        m[linha][coluna] = m[linha][coluna] + 1;
                    }
                }
            }
        }
    }
}

void novoJogo()
{
    bool gameOver = false;
    int placarAtual = 0;
    int contador;
    system("cls");
    while (gameOver == false)
    {
        limparMatriz();
        inserirBombas();
        numerarCasas();
        contador = 0;
        imprimeNextStage();

        while (true)
        {
            if (contador < 39)
            {
                char l, c;
                int linhaUsuario, colunaUsuario;
                system("cls");
                printf("-------------------------------------\n\n");
                printf("               :)     SCORE:  %d     \n\n", placarAtual);
                imprimeJogoAtual();
                printf("-------------------------------------\n");
                printf("\n\nDigite uma linha:   ");
                scanf("%s", &l);
                linhaUsuario = retornaLinha(l);
                printf("\n\nDigite uma coluna:   ");
                scanf("%s", &c);
                colunaUsuario = retornaColuna(c);
                if (linhaUsuario >= 0 && colunaUsuario >= 0)
                {
                    int posicaoAtual = retornaPosicao(linhaUsuario, colunaUsuario);
                    if (semBomba(posicaoAtual) == true)
                    {
                        if (n[linhaUsuario][colunaUsuario] == 0)
                        {
                            contador++;
                            placarAtual = placarAtual + 5;
                            n[linhaUsuario][colunaUsuario] = 1;
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("-------------------------------------\n\n");
                        printf("               :(     Score:  %d     \n\n", placarAtual);
                        selecionouBomba();
                        imprimeJogoAtual();
                        printf("-------------------------------------\n");
                        imprimeTelaFim();
                        printf("Fim de Jogo.. ");
                        system("pause");
                        gameOver = true;
                        break;
                    }
                }
            }

            else
            {
                break;
            }
        }
    }

    gravarPlacar(placarAtual);
}

int main()
{
    imprimeTelaInicio();
    while (true)
    {
        printf("-------------------------------------\n");
        printf("                 Menu                \n\n");
        printf("0 - Novo Jogo\n\n");
        printf("1 - Placares\n\n");
        printf("2 - Creditos\n\n");
        printf("3 - Sair\n\n");
        printf("-------------------------------------\n");

        char op;
        scanf("%s", &op);

        if (op == '0')
        {
            novoJogo();
        }

        if (op == '1')
        {
            placares();
        }

        if (op == '2')
        {
            creditos();
        }
        if (op == '3')
        {
            break;
        }
        system("cls");
    }
    system("cls");
    printf("Encerrando o jogo..");
}