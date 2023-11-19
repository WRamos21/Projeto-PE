#include <stdio.h>
#include "bignumber.h"

int main (void) {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", add(a, b));

    return 0;
}
