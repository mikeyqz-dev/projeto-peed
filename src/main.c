#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "corretor.h"

int main () {
    
    Palavra *palavra[50];

    printf("=====================================");
    printf("=====   CORRETOR ORTOGRÁFICO    =====");
    printf("=====================================\n\n\n");
    printf("\nDIGITE A PALAVRA QUE DESEJA CORRIGIR: ");
    fgets(*palavra, 50, stdin);

    palavra[strcspn(palavra, "\n" )] = '\0';

    printf("Palavra Digitada: %s\n", palavra);

    return 0;


}