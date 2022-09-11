#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 2048
int main()
{
    clock_t t;
    srand(time(NULL));
    Matrix* A = create(2);
    A->entries[0 * A->N + 0] = 1;
    A->entries[0 * A->N + 1] = 2;
    A->entries[1 * A->N + 0] = 3;
    A->entries[1 * A->N + 1] = 4;


    Matrix* B = create(2);
    B->entries[0 * B->N + 0] = 5;
    B->entries[0 * B->N + 1] = 6;
    B->entries[1 * B->N + 0] = 7;
    B->entries[1 * B->N + 1] = 8;


    Matrix* D = randmat(SIZE);

    Matrix* E = randmat(SIZE);


    t = clock();
    matmul(D, E);
    t = clock() - t; 
    printf("fast done in %f\n", ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    naive_matmul(D, eye(SIZE));
    t = clock() - t;
    printf("naive done in %f\n", ((double)t)/CLOCKS_PER_SEC);
}
