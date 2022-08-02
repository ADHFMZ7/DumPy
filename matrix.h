#ifndef MATRIX
#define MATRIX

typedef struct {
    float** entries;
    int N;
} Matrix ;

Matrix* create(const int N);
Matrix* eye(const int N);


Matrix* matmul(Matrix* A, Matrix* B);
Matrix* floatmul(Matrix* A, float B);
Matrix* matadd(Matrix* A, Matrix* B);
Matrix* floatadd(Matrix* A, float B);


void print(Matrix* A);


#endif