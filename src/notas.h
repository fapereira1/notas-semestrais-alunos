#ifndef NOTAS_H
#define NOTAS_H

typedef struct Notas
{
    char nome[50];
    float notas[4];
    float media;
    float mediaPonderada;
    float mediaGeometrica;
    int statusAprovacao;
} Notas;

/**
 * @brief Retorna uma instancia de Notas
 * @param
 * @return
 */
Notas novaNota(char nome[50], float notaB1, float notaB2, float notaB3, float notaB4);

void calculaMedia(Notas *nota);

void calculaMediaPonderada(Notas *nota);

void calculaMediaGeometrica(Notas *nota);

#endif // NOTAS_H
