#include <stdio.h>
#include <string.h>
#include <math.h>
#include "notas.h"

#define NOTA_APROVACAO 7
#define APROVADO 1
#define REPROVADO 0

Notas novaNota(char nome[50], float notaB1, float notaB2, float notaB3, float notaB4)
{
    Notas initialized;

    strcpy(initialized.nome, nome);
    initialized.notas[0] = notaB1;
    initialized.notas[1] = notaB2;
    initialized.notas[2] = notaB3;
    initialized.notas[3] = notaB4;

    return initialized;
}

void calculaMedia(Notas *nota)
{
    float soma = 0;
    size_t n = sizeof(nota->notas)/sizeof(nota->notas[0]);

    for (int i = 0; i < n; i++)
    {
        soma += nota->notas[i];
    }

    nota->media = soma / n;

    if(nota->media >= NOTA_APROVACAO)
    {
        nota->statusAprovacao = APROVADO;
    }
    else
    {
        nota->statusAprovacao = REPROVADO;
    }
}

void calculaMediaPonderada(Notas *nota)
{

    float pesos[4] = {3.0,3.0,4.0,4.0};
    float soma = 0.0;
    float mediaPonderada = 0.0;
    float somaNotas = 0.0;
    size_t n = sizeof(nota->notas)/sizeof(nota->notas[0]);

    for (int i = 0; i < n; i++)
    {
        somaNotas = somaNotas + nota->notas[i];
        soma += nota->notas[i] * pesos[i];
    }

    mediaPonderada = soma / somaNotas;
    nota->mediaPonderada = mediaPonderada;
}

void calculaMediaGeometrica(Notas *nota)
{

    float produto = 0.0;
    float expoente = 0.0;
    float mediaGeometrica = 0.0;
    size_t n = sizeof(nota->notas)/sizeof(nota->notas[0]);

    expoente = 1 / n;

    for (int i = 0; i < n; i++)
    {
        produto = produto * nota->notas[i];
    }

    mediaGeometrica = pow(produto, expoente);
    nota->mediaGeometrica = mediaGeometrica;
}
