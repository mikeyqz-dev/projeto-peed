#ifndef CORRETOR_H
#define CORRETOR_H

#include <stdio.h>
#include <string.h>


typedef struct {
    char palavra[50];
    char significado[200];
} Palavra;

typedef struct {
    char palavra[50];
    char significado[200];
    int distancia;
} Resultado;

void calcularResultados (
    char *entrada,
    Palavra dicionario[],
    Resultado resultados[],
    int quantidade
);

void ordenarResultados(
    Resultado resultados[],
    int quantidade
);

void exibirResultados(
    Resultado resultados[],
    int quantidade
);

#endif