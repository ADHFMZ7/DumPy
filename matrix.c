#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// TODO: 
// 1) Implement blocking to speed up matrix operations
// 2) Implement cache oblivious transpose

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


Matrix* randmat(const int N)
{
    Matrix* A = create(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0 ; j < N; j++)
        {
            A->entries[i][j] = ((double)rand()/(double)(RAND_MAX/10));
        }
    }
    return A;
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

Matrix* load(float** new, const int N)
{
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->N = N;
    matrix->entries = new;
    return matrix;
}


/////////////////////////////
////   Math Functions   ////
///////////////////////////


Matrix* transpose(Matrix* A)
{
    if (A->N <= 32)
    {

    }

}

Matrix* naive_transpose(Matrix* A)
{
    float temp;
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = A->entries[i][j];
            A->entries[i][j] = A->entries[j][i];
            A->entries[j][i] = temp;
        }
    }
    return A;
}


 Matrix* naive_matmul(Matrix* A, Matrix* B) 
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


 Matrix* matmul(Matrix* A, Matrix* B) 
 {
    // TODO: CHANGE THIS TO EFFICIENT TRANSPOSE
    B = naive_transpose(B);
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
                C->entries[j][i] += A->entries[j][k] * B->entries[i][k];
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




int getn(Matrix* A)
{
    return A->N;
}

float at(Matrix* A, int i, int j)
{
    return A->entries[i][j] ;
}

void set(Matrix* A, int i, int j, float val)
{
    printf("%f", val);
    if (i >= A->N || j >= A->N)
    {
        return;
    }
    A->entries[i][j] = val;
}

 void print(Matrix* A)
 {
    printf("this is the c print: \n");
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            printf("%.2f ", A->entries[i][j]);
        }
        printf("\n");
    }
 }