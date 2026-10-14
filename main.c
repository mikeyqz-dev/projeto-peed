#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "corretor.h"

int main () {
    
    char palavra[50];

    printf("=====================================\n");
    printf("=====   CORRETOR ORTOGRAFICO    =====\n");
    printf("=====================================\n\n\n");
    printf("\nDIGITE A PALAVRA QUE DESEJA CORRIGIR: ");
    fgets(palavra, 50, stdin);

    palavra[strcspn(palavra, "\n" )] = '\0';

    printf("Palavra Digitada: %s\n", palavra);

    return 0;


}