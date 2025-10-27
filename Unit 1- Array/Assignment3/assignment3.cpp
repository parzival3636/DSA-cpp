#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int** allocateMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    return mat;
}

void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;
}

void fillMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = rand() % 100;
}

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

void multiplyColumnMajor(int** A, int** B, int** C, int m, int n, int p) {
    for (int j = 0; j < p; j++) {
        for (int k = 0; k < n; k++) {
            int temp = B[k][j];
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

    int** A = allocateMatrix(m, n);
    int** B = allocateMatrix(n, p);
    int** C = allocateMatrix(m, p);

    fillMatrix(A, m, n);
    fillMatrix(B, n, p);

    auto start = high_resolution_clock::now();
    multiplyRowMajor(A, B, C, m, n, p);
    auto end = high_resolution_clock::now();
    auto rowMajorTime = duration_cast<milliseconds>(end - start).count();
    cout << "Row-major multiplication time: " << rowMajorTime << " ms" << endl;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;

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