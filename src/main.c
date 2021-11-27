#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "notas.h"

void inicioPrograma();
void cadastrarNotas();
void pressEnterToContinue();
void imprimeResultadoMediaAritmetica();
void imprimeResultadoMediaPonderada();
void imprimeResultadoMediaGeometrica();
void mostrarResultados();
void escreverParaArquivo();
void verificarNotasCadastradas();
int opcao;

Notas* memStorage;
int tamanhoAlunos;
int main()
{
    inicioPrograma();
}

void inicioPrograma()
{
    desenhaMenuPrincipal();

    do
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarNotas();
            break;
        case 2:
            mostrarResultados();
            break;
        case 3:
            escreverParaArquivo();
            break;
        case 0:
            printf("Saindo da Aplicacao....");
            exit(0);
            break;
        default:
            printf("\nOpcao Invalida!\n");
            pressEnterToContinue();
            break;
        }
    }
    while (opcao != 0);
}

void cadastrarNotas()
{
    char nome[50];
    float n1,n2,n3,n4;
    int qtdeAlunos = 0;

    desenhaMenuCadastro();

    printf("Qual a quantidade de Notas que serao lancadas: ");
    scanf("%d", &qtdeAlunos);

    memStorage = (Notas*) malloc(sizeof(Notas) * qtdeAlunos);
    tamanhoAlunos = qtdeAlunos;

    for(int i = 0; i < qtdeAlunos; i++)
    {
        desenhaMenuCadastro();
        printf("\n\nAluno %d de %d\n ", i + 1, qtdeAlunos);

        printf("\n\nDigite o nome do aluno: ");
        scanf(" %[^\t\n]s",&nome);

        printf("Digite a nota do Bimestre 1: ");
        scanf("%f", &n1);

        printf("Digite a nota do Bimestre 2: ");
        scanf("%f", &n2);

        printf("Digite a nota do Bimestre 3: ");
        scanf("%f", &n3);

        printf("Digite a nota do Bimestre 4: ");
        scanf("%f", &n4);

        Notas newNota = novaNota(nome, n1, n2, n3, n4);
        calculaMedia(&newNota);
        calculaMediaPonderada(&newNota);
        calculaMediaGeometrica(&newNota);
        memStorage[i] = newNota;

        printf("Notas do cadastradas com sucesso!!!\n");
    }
    printf("Notas do cadastradas com sucesso!!!\n");
    inicioPrograma();
}

void mostrarResultados()
{

    verificarNotasCadastradas();

    int opcaoResult;
    desenharMenuResultados();

    do
    {
        scanf("%d", &opcaoResult);
        switch (opcaoResult)
        {
        case 1:
            imprimeResultadoMediaAritmetica();
            pressEnterToContinue();
            desenharMenuResultados();
            break;
        case 2:
            imprimeResultadoMediaPonderada();
            pressEnterToContinue();
            desenharMenuResultados();
            break;
        case 3:
            imprimeResultadoMediaGeometrica();
            pressEnterToContinue();
            desenharMenuResultados();
            break;
        case 8:
            pressEnterToContinue();
            inicioPrograma();
        default:
            printf("\nOpcao Invalida!\n");
            pressEnterToContinue();
            desenharMenuResultados();
            break;
        }
    }
    while (opcaoResult != 0);
}

void imprimeResultadoMediaAritmetica()
{
    desenharMenuResultados();
    printf("------------------------------------------------------\n\n");
    for (int i = 0; i < tamanhoAlunos; i++)
    {
        printf("Aluno:%s\n  ", memStorage[i].nome);
        printf("Media:%f\n", memStorage[i].media);

        if ( memStorage[i].statusAprovacao == 1)
        {
            printf("Status: Aprovado");
        }
        else
        {
            printf("Status: Reprovado");
        }

        printf("\n------------------------------------------------------\n");
    }
}

void imprimeResultadoMediaPonderada()
{
    desenharMenuResultados();
    printf("------------------------------------------------------\n\n");
    for (int i = 0; i < tamanhoAlunos; i++)
    {
        printf("Aluno:%s\n  ", memStorage[i].nome);
        printf("Media Ponderada:%f\n", memStorage[i].mediaPonderada);
        if ( memStorage[i].statusAprovacao == 1)
        {
            printf("Status: Aprovado");
        }
        else
        {
            printf("Status: Reprovado");
        }

        printf("\n------------------------------------------------------\n");
    }
    printf("------------------------------------------------------\n");
}

void imprimeResultadoMediaGeometrica()
{
    desenharMenuResultados();
    printf("------------------------------------------------------\n\n");
    for (int i = 0; i < tamanhoAlunos; i++)
    {
        printf("Aluno:%s\n  ", memStorage[i].nome);
        printf("Media Geometrica:%f\n", memStorage[i].mediaGeometrica);
        if ( memStorage[i].statusAprovacao == 1)
        {
            printf("Status: Aprovado");
        }
        else
        {
            printf("Status: Reprovado");
        }

        printf("\n------------------------------------------------------\n");
    }
    printf("------------------------------------------------------\n");
}

void pressEnterToContinue()
{
    char ch;
    printf("\nPressione ENTER para continuar...");
    scanf("%c",&ch);
    getchar();
}

void escreverParaArquivo()
{
    verificarNotasCadastradas();

    FILE *fp;
    fp = fopen("C:\\resultado.csv","w+");

    for (int i = 0; i < tamanhoAlunos; i++)
    {
        char c[50];
        for (int j = 0; j < 4; j++)
        {
            float f = memStorage[i].notas[j];
            char z[50];
            sprintf(z, "%g", f);
            strcat(z, ",");
            strncpy(c, z, 50);
        }
        fprintf(fp,"\n%s,%s%f,%f,%f,%d%", memStorage[i].nome,c,memStorage[i].media,memStorage[i].mediaPonderada,memStorage[i].mediaGeometrica,memStorage[i].statusAprovacao);
    }
    fclose(fp);
    pressEnterToContinue();
}

void verificarNotasCadastradas()
{

    if (tamanhoAlunos <= 0)
    {
        printf("Erro: Nao foram encontradas notas cadastradas, por favor faca o cadastro de notas primeiro");
        pressEnterToContinue();
        inicioPrograma();
    }
}
