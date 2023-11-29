#include "bignumber.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateBigNumber(char *elements) {
    int size = strlen(elements);
    for (int i = 0; i < size; i++) {
        if (elements[i] == '\0') continue;
        if (elements[i] == '\n') continue;

        if ((elements[i] < 48 || elements[i] > 57) && elements[i] != 45) {

            return 0;
        }
    }

    return 1;
}

void copyElementsToBigNumber(BigNumber a, char *elements) {
    printf("%u", a->size);
    for (int i = 0; i < a->size; i++) {
        if (elements[i] == '-') continue;

        if (a->isNegative) {
            a->elements[i - 1] = elements[i] - '0';
            printf("%d", a->elements[i-1]);
        } else {
            a->elements[i] = elements[i] - '0';
            printf("%d", a->elements[i]);
        }
    }
}

void reverseBigNumber(BigNumber a) {
    for (int i = 0; i < a->size / 2; i++) {
        int temp = a->elements[i];
        a->elements[i] = a->elements[a->size - i - 1];
        a->elements[a->size - i - 1] = temp;
    }
}

BigNumber getBigNumber() {
    BigNumber a = malloc(sizeof(BigNumber));
    char *elements = malloc(MAX_SIZE);

    if (a == NULL || elements == NULL) {
        printf("Erro: Limite de memoria excedido!");
        exit(1);
    }

    do {
        printf("Digite o numero:\n");
        printf("Exemplo de formatacao - positivo: 54658\n");
        printf("Exemplo de formatacao - negativo: -145793\n");
        fgets(elements, MAX_SIZE, stdin);
        printf("%u\n", strlen(elements));
        if (!validateBigNumber(elements)) {
            system("cls");
            printf("***Digite um numero nos formatos validos...***\n");
        }
    } while (!validateBigNumber(elements));

    a->size = strlen(elements) - 1;
    if (elements[a->size - 1] == '\n') {
        a->size = a->size - 1;
    }
    elements = realloc(elements, strlen(elements) * sizeof(char));
    a->elements = calloc(a->size, sizeof(int));
    if (a->elements == NULL) {
        printf("Erro: Limite de memoria excedido!");
        exit(1);
    }
    if (elements[0] == '-') a->isNegative = 1;

    copyElementsToBigNumber(a, elements);
    free(elements);

    reverseBigNumber(a);

    system("cls");
    return a;
}

void printBigNumber(BigNumber a) {
    reverseBigNumber(a);
    for (int i = 0; i < a->size; i++) {
        printf("%d", a->elements[i]);
    }
    reverseBigNumber(a);
}
