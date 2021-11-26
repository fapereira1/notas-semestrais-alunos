#include <stdio.h>
#include "menu.h"
#include <windows.h>

void drawLine();
void whiteLine(int amount);
void centerText(char *text, int fieldWidth);
void leftText(char *text);
void header();

void drawMainMenu()
{
    header();
    centerText("Menu de Opcoes", 80);
    drawLine();
    leftText("1 - Cadastrar Notas de Aluno(s)");
    leftText("2 - Cadastrar Disciplina");
    leftText("3 - Cadastrar Notas");
    leftText("4 - Listar Alunos");
    leftText("5 - Listar Disciplinas");
    leftText("0 - Encerrar Aplicacao");

    whiteLine(2);
    leftText("Entre com a Opcao Desejada: ");

}

void drawCadastroMenu()
{
    header();
    centerText("Cadastro de Notas por Aluno", 80);
    drawLine();
}

void drawLine()
{
    printf("\n");
    for(int i = 0; i < 80; i++)
    {
        printf("=");
    }
    printf("\n");
}

void whiteLine(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("\n");
    }

}

void centerText(char *text, int fieldWidth)
{
    int padlen = (fieldWidth - strlen(text)) / 2;
    printf("%*s%s%*s", padlen, "", text, padlen, "");
}

void leftText(char *text)
{
    printf("%s\n", text);
}

void header()
{
    system("cls");
    leftText("\nDesenvolvido por: <seuNome>");
    leftText("Data: Nov/2021");
    leftText("Versao: 1.0.0");
    drawLine();
    centerText("Cadastro de Notas Alunos", 80);
    drawLine();
    whiteLine(1);
}
