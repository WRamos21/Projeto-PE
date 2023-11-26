#include "bignumber.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateBigNumber(BigNumber a) {
    for (int i = 0; i < a->size; i++) {
        if (a->elements[i] == '\0') continue;
        if (a->elements[i] == '\n') continue;

        if ((a->elements[i] < 48 || a->elements[i] > 57) && a->elements[i] != 45) {

            return 0;
        }
    }

    return 1;
}

void reverse(BigNumber a) {
    for (int i = a->elements[0] == '-' ? 1 : 0; i < a->size / 2; i++) {
        if (a->elements[i] == '\0') continue;

        char temp = a->elements[i];
        a->elements[i] = a->elements[a->size - i - 1];
        a->elements[a->size - i - 1] = temp;
    }
}

BigNumber getBigNumber() {
    BigNumber a = malloc(sizeof(BigNumber));
    a->elements = malloc(MAX_SIZE * sizeof(char));

    if (a == NULL || a->elements == NULL) {
        printf("Erro: Limite de memoria excedido!");
        exit(1);
    }

    do {
        printf("Digite o numero:\n");
        printf("Exemplo de formatacao - positivo: 54658\n");
        printf("Exemplo de formatacao - negativo: -145793\n");
        fgets(a->elements, MAX_SIZE, stdin);
        a->size = strlen(a->elements);
        if (!validateBigNumber(a)) {
            system("cls");
            printf("Digite um numero nos formatos validos...\n");
        }
    } while (!validateBigNumber(a));

    reverse(a);

    return a;
}

void printBigNumber(BigNumber a) {
    for (int i = 0; i < a->size; i++) {
        printf("%c", a->elements[i]);
    }
}
