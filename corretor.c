#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"
#include "corretor.h"
#include "levenshtein.h"

void calcularResultados(
    char *entrada,
    Palavra dicionario[],
    Resultado resultados[],
    int quantidade
){
    for (int i = 0; i < quantidade; i++){
        strcpy (resultados[i].palavra, dicionario[i].palavra);
        strcpy (resultados[i].significado, dicionario[i].significado);

        resultados[i].distancia = levenshtein(
            entrada,
            dicionario[i].palavra,
            strlen(entrada),
            strlen(dicionario[i].palavra)
        );
    }

    ordenarResultados (resultados, quantidade);
}

void ordenarResultados (
    Resultado resultados[],
    int quantidade
){
    int i, j, menor;
    Resultado temp;

    for(i = 0; i < quantidade - 1; i++){
        menor = i;

        for (j = i + 1; j < quantidade; j++){
            if (resultados[j].distancia < resultados[menor].distancia){
                menor = j;
            }
        }

        if (menor != i){
            temp = resultados[i];
            resultados[i] = resultados[menor];
            resultados[menor] = temp;
        }
    }
}

void exibirResultados (
    Resultado resultados[],
    int quantidade
){
    printf("\nAs %d palavras mais semelhantes:\n", quantidade);
    printf("====================================================\n");

    for (int i = 0; i < quantidade; i++){
        printf("%d. %s\n", i + 1, resultados[i].palavra);
        printf("    Distancia: %d\n", resultados[i].distancia);
        printf("    Significado: %s\n", resultados[i].significado);
        printf("====================================================\n");

    }
}

void converterMinusculas (char *palavra){
    for (int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = tolower((unsigned char) palavra[i]); 
    }
}

int entradaValida (char *palavra){
    if (strlen(palavra) == 0){
        return 0;
    }

    for (int i = 0;palavra[i] != '\0'; i++){
        if (!isalpha((unsigned char) palavra[i])){
            return 0;
        }
    }

    return 1;
}