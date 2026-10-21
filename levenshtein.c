#include "levenshtein.h"

#define MAX_TAM 50

static int menorDeTres(int a, int b, int c)
{
    int menor = a;

    if (menor > b)
    {
        menor = b;
    }

    if (menor > c)
    {
        menor = c;
    }

    return menor;
}

static int levenshteinRecursivo(
    char *palavra1,
    char *palavra2,
    int tamanho1,
    int tamanho2,
    int memo[MAX_TAM][MAX_TAM])
{
    if (tamanho1 == 0)
    {
        return tamanho2;
    }

    if (tamanho2 == 0)
    {
        return tamanho1;
    }

    if (memo[tamanho1][tamanho2] != -1)
    {
        return memo[tamanho1][tamanho2];
    }

    if (palavra1[tamanho1 - 1] == palavra2[tamanho2 - 1])
    {
        memo[tamanho1][tamanho2] = levenshteinRecursivo(
            palavra1,
            palavra2,
            tamanho1 - 1,
            tamanho2 - 1,
            memo);

        return memo[tamanho1][tamanho2];
    }

    int insercao = levenshteinRecursivo(
        palavra1,
        palavra2,
        tamanho1,
        tamanho2 - 1,
        memo);

    int remocao = levenshteinRecursivo(
        palavra1,
        palavra2,
        tamanho1 - 1,
        tamanho2,
        memo);

    int substituicao = levenshteinRecursivo(
        palavra1,
        palavra2,
        tamanho1 - 1,
        tamanho2 - 1,
        memo);

    memo[tamanho1][tamanho2] =
        1 + menorDeTres(insercao, remocao, substituicao);

    return memo[tamanho1][tamanho2];
}

int levenshtein(
    char *palavra1,
    char *palavra2,
    int tamanho1,
    int tamanho2
){
    int memo[MAX_TAM][MAX_TAM];

    for (int i = 0; i < MAX_TAM; i++){
        for (int j = 0; j < MAX_TAM; j++){
            memo[i][j] = -1;
        }
    }

    return levenshteinRecursivo(
        palavra1,
        palavra2,
        tamanho1,
        tamanho2,
        memo
    );
}