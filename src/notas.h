#ifndef NOTAS_H
#define NOTAS_H

typedef struct Notas {
    char nome[50];
    float notas[4];
} Notas;

/**
 * @brief Retorna uma instancia de Notas
 * @param
 * @return
 */
Notas NewNotas(char nome[50], float notaB1, float notaB2, float notaB3, float notaB4);

#endif // POINT_H
