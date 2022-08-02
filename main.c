#include "matrix.h"

int main()
{
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

    Matrix* C = eye(2);
    Matrix* D = matmul(A, B);

    print(A);
    print(B);
    print(C);
    print(D);

    print(matmul(C, D));
}