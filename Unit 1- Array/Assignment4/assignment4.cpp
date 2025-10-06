/*
Title: Sparse Matrix using Compact Representation
Author: ChatGPT
Notes:
- Identifies a sparse matrix
- Stores non-zero elements in triplet form
- Supports display and simple transpose
- Uses arrays (no vector)
*/

#include <iostream>
#include <iomanip> // for setw
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Allocate matrix dynamically
    int **mat = new int*[rows];
    for(int i = 0; i < rows; i++)
        mat[i] = new int[cols];

    // Input matrix
    cout << "Enter matrix elements:\n";
    int zeroCount = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 0) zeroCount++;
        }
    }

    // Check if sparse
    if(zeroCount <= (rows * cols) / 2) {
        cout << "The matrix is not sparse.\n";
    } else {
        cout << "The matrix is sparse.\n";

        // Count non-zero elements
        int nonZeroCount = rows * cols - zeroCount;

        // Allocate compact representation (triplet)
        Element *compact = new Element[nonZeroCount];
        int k = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] != 0){
                    compact[k].row = i;
                    compact[k].col = j;
                    compact[k].value = mat[i][j];
                    k++;
                }
            }
        }

        // Display original matrix using compact representation
        cout << "\nOriginal Matrix:\n";
        k = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(k < nonZeroCount && compact[k].row == i && compact[k].col == j){
                    cout << setw(4) << compact[k].value;
                    k++;
                } else {
                    cout << setw(4) << 0;
                }
            }
            cout << endl;
        }

        // Transpose
        Element *transposed = new Element[nonZeroCount];
        for(int i = 0; i < nonZeroCount; i++){
            transposed[i].row = compact[i].col;
            transposed[i].col = compact[i].row;
            transposed[i].value = compact[i].value;
        }

        // Display transposed matrix
        cout << "\nTransposed Matrix:\n";
        k = 0;
        for(int i = 0; i < cols; i++){        // rows of transposed = cols of original
    for(int j = 0; j < rows; j++){    // cols of transposed = rows of original
        bool found = false;
        for(int t = 0; t < nonZeroCount; t++){
            if(transposed[t].row == i && transposed[t].col == j){
                cout << setw(4) << transposed[t].value;
                found = true;
                break;
            }
        }
        if(!found)
            cout << setw(4) << 0;
    }
    cout << endl;
}


        // Free memory for compact arrays
        delete[] compact;
        delete[] transposed;
    }

    // Free matrix memory
    for(int i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}
