#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/*  This matrix library implements a square
    matrix struct and basic operations to
    later be wrapped in a python class.

    Matrix interface:
        int     : N 
            the size of the matrix

        float** : entries
            an array that holds the 

    The matrix structure holds an int called
    N that holds the 
*/


/////////////////////////////
////    Constructors    ////
///////////////////////////


Matrix* create(int N)
{
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->N = N;
    matrix->entries = malloc(sizeof(float*) * N);
    for (int i = 0; i < N; i++)
    {
        matrix->entries[i] = malloc(sizeof(float) * N);
    }
    return matrix;
}


Matrix* eye(const int N)
{
    Matrix* A = create(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0 ; j < N; j++)
        {
            if (j == i) 
            {
                A->entries[i][j] = 1.;
            }
            else 
            {
                A->entries[i][j] = 0.;
            }
        }
    }
    return A;
}


/////////////////////////////
////   Math Functions   ////
///////////////////////////


 Matrix* matmul(Matrix* A, Matrix* B) 
 {
    if (A->N != B->N)
    {
        return NULL;
    }
    Matrix* C = create(A->N);

    for (int i = 0; i < C->N; i++)
    {
        for (int j = 0; j < C->N; j++)
        {
            for (int k = 0; k < C->N; k++)
            {
                C->entries[j][i] += A->entries[j][k] * B->entries[k][i];
            }
        }
    }
    return C;
 }


 Matrix* floatmul(Matrix* A, float B)
 {
    Matrix* C = create(A->N);
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            C->entries[i][j] = 
            A->entries[i][j] * B;
        }
    }
    return C;
 }


 Matrix* matadd(Matrix* A, Matrix* B)
 {
    Matrix* C = create(A->N);
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            C->entries[i][j] = 
            A->entries[i][j] + 
            B->entries[i][j];
        }
    }
    return C;
 }


 Matrix* floatadd(Matrix* A, float B)
 {
    Matrix* C = create(A->N);
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            C->entries[i][j] = 
            A->entries[i][j] + B;
        }
    }
    return C;
 }









 void print(Matrix* A)
 {
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            printf("%.1f ", A->entries[i][j]);
        }
        printf("\n");
    }
 }