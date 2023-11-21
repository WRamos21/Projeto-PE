#ifndef BIGNUMBER_H
#define BIGNUMBER_H

// ????? tentar explicar depois
#define MAX_SIZE __SIZE_MAX__ / 5

typedef struct {
    char *elements;
    int size;
} *BigNumber;

BigNumber getBigNumber();

void printBigNumber(BigNumber a);

#endif
