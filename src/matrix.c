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

/////////////////////////////
////    Constructors    ////
///////////////////////////


Matrix* create(int N)
{
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->N = N;
    matrix->entries = malloc(N * sizeof(float) * N);
    return matrix;
}


Matrix* randmat(const int N)
{
    Matrix* A = create(N);
    for (int i = 0; i < N*N; i++)
    {
        A->entries[i] = ((double)rand()/(double)(RAND_MAX/10));
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
                A->entries[i * N + j] = 1.;
            }
            else 
            {
                A->entries[i * N + j] = 0.;
            }
        }
    }
    return A;
}

Matrix* load(float* new, const int N)
{
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->N = N;
    matrix->entries = new;
    return matrix;
}


/////////////////////////////
////   Math Functions   ////
///////////////////////////


float* transpose(float* A, int n, int N)
{
    if (n <= 32)
    {
        return naive_transpose(A, n);
    }
    else 
    {
        int k = n / 2;
        transpose(A, k, N);
        transpose(A + k, k, N);
        transpose(A + k * N, k, N);
        transpose(A + k * N + k, k, N);


        float temp;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                temp = A[(i + k) * N + j];
                A[(i + k) * N + j] = A[i * N + (j + k)];
                A[i * N + (j + k)] = temp;               
            }
        }
        if (n % 1){
            for (int i = 0; i < n; i++)
            {
                temp = A[i * N + n - 1];
                A[i * N + n - 1] = A[(n-1) * N + i];
                A[(n-1) * N + i] = temp;
            }
        }
    }
    return A;
}

float* naive_transpose(float* A, int N)
{
    float temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = A[i * N + j];
            A[i * N + j] = A[j * N + i];
            A[j * N + i] = temp; 
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
    int N = A->N;
    Matrix* C = create(A->N);

    for (int i = 0; i < C->N; i++)
    {
        for (int j = 0; j < C->N; j++)
        {
            for (int k = 0; k < C->N; k++)
            {
                C->entries[j * N + i] += A->entries[j * N + k] * B->entries[k * N + i];
            }
        }
    }
    return C;
 }


 Matrix* matmul(Matrix* A, Matrix* B) 
 {
    B->entries = transpose(B->entries, B->N, B->N);
    if (A->N != B->N)
    {
        return NULL;
    }
    int N = A->N;
    Matrix* C = create(A->N);

    for (int i = 0; i < C->N; i++)
    {
        for (int j = 0; j < C->N; j++)
        {
            for (int k = 0; k < C->N; k++)
            {
                C->entries[j * N + i] += A->entries[j * N + k] * B->entries[i * N + k];
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
            C->entries[i * C->N + j] = 
            A->entries[i * A->N + j] * B;
        }
    }
    return C;
 }


 Matrix* matadd(Matrix* A, Matrix* B)
 {
    Matrix* C = create(A->N);
    int N = A->N;
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            C->entries[i * N + j] = 
            A->entries[i * N + j] + 
            B->entries[i * N + j];
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
            C->entries[i * A->N + j] = 
            A->entries[i * A->N + j] + B;
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
    return A->entries[i * A->N + j] ;
}

void set(Matrix* A, int i, int j, float val)
{
    printf("%f", val);
    if (i >= A->N || j >= A->N)
    {
        return;
    }
    A->entries[i * A->N + j] = val;
}

 void print(Matrix* A)
 {
    for (int i = 0; i < A->N; i++)
    {
        for (int j = 0; j < A->N; j++)
        {
            printf("%.2f ", A->entries[i * A->N + j]);
        }
        printf("\n");
    }
 }
