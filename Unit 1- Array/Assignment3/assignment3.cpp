
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to allocate dynamic 2D array
int** allocateMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    return mat;
}

// Function to deallocate dynamic 2D array
void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;
}

// Fill matrix with random integers (0..99)
void fillMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = rand() % 100;
}

// Row-Major multiplication (cache friendly)
void multiplyRowMajor(int** A, int** B, int** C, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Column-Major access simulation (strided access)
void multiplyColumnMajor(int** A, int** B, int** C, int m, int n, int p) {
    for (int j = 0; j < p; j++) {         // outer loop on columns of C
        for (int k = 0; k < n; k++) {
            int temp = B[k][j];           // strided access in row-major
            for (int i = 0; i < m; i++) {
                C[i][j] += A[i][k] * temp;
            }
        }
    }
}

int main() {
    int m, n, p;

    cout << "Enter dimensions of matrix A (m x n): ";
    cin >> m >> n;
    cout << "Enter number of columns of matrix B (p): ";
    cin >> p;

    // Allocate matrices dynamically
    int** A = allocateMatrix(m, n);
    int** B = allocateMatrix(n, p);
    int** C = allocateMatrix(m, p);

    // Fill A and B with random values
    fillMatrix(A, m, n);
    fillMatrix(B, n, p);

    // Row-major multiplication
    auto start = high_resolution_clock::now();
    multiplyRowMajor(A, B, C, m, n, p);
    auto end = high_resolution_clock::now();
    auto rowMajorTime = duration_cast<milliseconds>(end - start).count();
    cout << "Row-major multiplication time: " << rowMajorTime << " ms" << endl;

    // Reset C to 0
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;

    // Column-major multiplication
    start = high_resolution_clock::now();
    multiplyColumnMajor(A, B, C, m, n, p);
    end = high_resolution_clock::now();
    auto colMajorTime = duration_cast<milliseconds>(end - start).count();
    cout << "Column-major (simulated) multiplication time: " << colMajorTime << " ms" << endl;
    cout << "Result Matrix C:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }

    
    freeMatrix(A, m);
    freeMatrix(B, n);
    freeMatrix(C, m);

    return 0;
}
