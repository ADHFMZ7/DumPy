#ifndef MATRIX
#define MATRIX



typedef struct {
    float* entries;
    int N;
} Matrix ;

// Matrix Constructors
Matrix* create(const int N);
Matrix* randmat(const int N);
Matrix* eye(const int N);
Matrix* load(float* new, const int N);


// Math operation
float* transpose(float* A, int n, int N);
float* naive_transpose(float* A, int N);
Matrix* matmul(Matrix* A, Matrix* B);
Matrix* naive_matmul(Matrix* A, Matrix* B);
Matrix* floatmul(Matrix* A, float B);
Matrix* matadd(Matrix* A, Matrix* B);
Matrix* floatadd(Matrix* A, float B);

// getters/setters
int getn(Matrix* A);
float at(Matrix* A, int i, int j);
void set(Matrix* A, int i, int j, float val);
void print(Matrix* A);


#endif
