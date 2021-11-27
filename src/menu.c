#include <stdio.h>
#include "menu.h"
#include <windows.h>

void desenhaLinha();
void linhaBranco(int amount);
void centralizaTexto(char *text, int fieldWidth);
void textoEsquerda(char *text);
void header();

void desenhaMenuPrincipal()
{
    header();
    centralizaTexto("Menu de Opcoes", 80);
    desenhaLinha();
    textoEsquerda("1 - Cadastrar Notas de Aluno(s)");
    textoEsquerda("2 - Resultados");
    textoEsquerda("3 - Escrever Resultado para Arquivo");
    textoEsquerda("0 - Encerrar Aplicacao");

    linhaBranco(2);

    textoEsquerda("[Menu Principal] Entre com a Opcao Desejada : ");
}

void desenhaMenuCadastro()
{
    header();
    centralizaTexto("Cadastro de Notas por Aluno", 80);
    desenhaLinha();
}

void desenharMenuResultados()
{

    header();
    centralizaTexto("Exbir Resultado de Notas", 80);
    desenhaLinha();
    textoEsquerda("1 - Media Aritmetica");
    textoEsquerda("2 - Media Ponderada");
    textoEsquerda("3 - Media Geometrica");
    textoEsquerda("8 - Voltar Menu Principal");
    linhaBranco(1);

    textoEsquerda("Entre com a Opcao Desejada de Resultado: ");
}

void desenhaLinha()
{
    printf("\n");
    for(int i = 0; i < 80; i++)
    {
        printf("=");
    }
    printf("\n");
}

void linhaBranco(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("\n");
    }

}

void centralizaTexto(char *text, int fieldWidth)
{
    int padlen = (fieldWidth - strlen(text)) / 2;
    printf("%*s%s%*s", padlen, "", text, padlen, "");
}

void textoEsquerda(char *text)
{
    printf("%s\n", text);
}

void header()
{
    system("cls");
    textoEsquerda("\nDesenvolvido por: ");
    textoEsquerda("Data: Nov/2021");
    textoEsquerda("Versao: 1.0.0");
    desenhaLinha();
    centralizaTexto("Cadastro de Notas Alunos", 80);
    desenhaLinha();
    linhaBranco(1);
}
