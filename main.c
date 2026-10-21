#include <stdio.h>
#include <string.h>
#include "corretor.h"
#include "dicionario.h"

int main()
{

    char palavra[TAM_PALAVRA];
    Palavra dicionario[MAX_PALAVRAS];
    Resultado resultados[MAX_PALAVRAS];

    int quantidadePalavras = carregarDicionario(dicionario);

    printf("=====================================\n");
    printf("=====   CORRETOR ORTOGRAFICO    =====\n");
    printf("=====================================\n\n\n");
    printf("\nDIGITE A PALAVRA QUE DESEJA CORRIGIR: ");
    fgets(palavra, TAM_PALAVRA, stdin);

    palavra[strcspn(palavra, "\n")] = '\0';

    if (!entradaValida(palavra)){
        printf("Erro: nenhuma palavra digitada.\n");
        return 1;
    }

    converterMinusculas (palavra);

    calcularResultados(
        palavra,
        dicionario,
        resultados,
        quantidadePalavras);

    exibirResultados (resultados, TOP_RESULTADOS);

    return 0;
}