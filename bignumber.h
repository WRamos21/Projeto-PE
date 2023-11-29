#ifndef BIGNUMBER_H
#define BIGNUMBER_H

// ????? tentar explicar depois
#define MAX_SIZE __SIZE_MAX__ / 5

typedef struct {
    int *elements;
    unsigned isNegative;
    unsigned int size;
} *BigNumber;

BigNumber getBigNumber();

void printBigNumber(BigNumber a);

void destroyBigNumber(BigNumber a);

void sumBigNumber(BigNumber a, BigNumber c);

#endif
