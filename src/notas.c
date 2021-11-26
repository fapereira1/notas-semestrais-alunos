#include <stdio.h>
#include <string.h>
#include "notas.h"

Notas NewNotas(char nome[50], float notaB1, float notaB2, float notaB3, float notaB4)
{
    Notas initialized;

    strcpy(initialized.nome, nome);
    initialized.notas[0] = notaB1;
    initialized.notas[1] = notaB2;
    initialized.notas[2] = notaB3;
    initialized.notas[3] = notaB4;

    return initialized;
}
