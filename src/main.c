#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "notas.h"

void cadastrarNotas();
void pressEnterToContinue();
int opcao;

Notas* memStorage;

int main()
{
    drawMainMenu();

    do
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                cadastrarNotas();
                break;
            case 2:
                printf("\n");
                break;
            case 0:
                printf("Saindo da Aplicacao....");
                break;
            default:
                printf("\nOpcao Invalida!\n");
                pressEnterToContinue();
                break;
        }
    } while (opcao != 0);
}

void cadastrarNotas()
{
    char nome[50];
    float n1,n2,n3,n4;
    int qtdeAlunos = 0;

    drawCadastroMenu();

    printf("Qual a quantidade de Notas que serao lancadas: ");
    scanf("%d", &qtdeAlunos);

    memStorage = (Notas*) malloc(sizeof(Notas) * qtdeAlunos);

    for(int i = 0; i < qtdeAlunos; i++)
    {
        printf("\n\nAluno %d de %d\n ", i + 1, qtdeAlunos);

        printf("\n\nDigite o nome do aluno: ");
        scanf("%s", &nome);

        printf("Digite a nota do Bimestre 1: ");
        scanf("%f", &n1);

        printf("Digite a nota do Bimestre 2: ");
        scanf("%f", &n2);

        printf("Digite a nota do Bimestre 3: ");
        scanf("%f", &n3);

        printf("Digite a nota do Bimestre 4: ");
        scanf("%f", &n4);

        Notas newNota = NewNotas(nome, n1, n2, n3, n4);
        memStorage[i] = newNota;

        printf("Notas do Aluno %s cadastradas com sucesso\n\n !!!", memStorage[i].nome);
        pressEnterToContinue();
        drawCadastroMenu();
    }

    drawMainMenu();
}

void pressEnterToContinue()
{
    char ch;
    printf("\nPressione ENTER para continuar...");
    scanf("%c",&ch);
    getchar();
    drawMainMenu();
}
