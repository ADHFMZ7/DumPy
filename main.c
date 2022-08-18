#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t t;
    srand(time(NULL));
    Matrix* A = create(2);
    A->entries[0][0] = 1;
    A->entries[0][1] = 2;
    A->entries[1][0] = 3;
    A->entries[1][1] = 4;

    Matrix* B = create(2);
    B->entries[0][0] = 5;
    B->entries[0][1] = 6;
    B->entries[1][0] = 7;
    B->entries[1][1] = 8;


    Matrix* D = randmat(2048);

    randmat(1000);

    Matrix* E = randmat(2048);

    t = clock();
    naive_matmul(D, E);
    t = clock() - t;
    printf("naive done in %f\n", ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    matmul(D, naive_transpose(E));
    t = clock() - t; 
    printf("fast done in %f\n", ((double)t)/CLOCKS_PER_SEC);

}