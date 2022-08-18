#ifndef MATRIX
#define MATRIX

typedef struct {
    float** entries;
    int N;
} Matrix ;

Matrix* create(const int N);
Matrix* randmat(const int N);
Matrix* eye(const int N);
Matrix* load(float** new, const int N);


Matrix* transpose(Matrix* A);
Matrix* naive_transpose(Matrix* A);
Matrix* matmul(Matrix* A, Matrix* B);
Matrix* naive_matmul(Matrix* A, Matrix* B);
Matrix* floatmul(Matrix* A, float B);
Matrix* matadd(Matrix* A, Matrix* B);
Matrix* floatadd(Matrix* A, float B);

int getn(Matrix* A);
float at(Matrix* A, int i, int j);
void set(Matrix* A, int i, int j, float val);
void print(Matrix* A);


#endif