#ifndef CORRETOR_H
#define CORRETOR_H

#define TAM_PALAVRA 50
#define TAM_SIGNIFICADO 200
#define MAX_PALAVRAS 100
#define TOP_RESULTADOS 5

typedef struct {
    char palavra[TAM_PALAVRA];
    char significado[TAM_SIGNIFICADO];
} Palavra;

typedef struct {
    char palavra[TAM_PALAVRA];
    char significado[TAM_SIGNIFICADO];
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

void converterMinusculas(char *palavra);

int entradaValida(char *palavra);

#endif