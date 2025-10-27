#include <iostream>
#include <iomanip>
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

    int **mat = new int*[rows];
    for(int i = 0; i < rows; i++)
        mat[i] = new int[cols];

    cout << "Enter matrix elements:\n";
    int zeroCount = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 0) zeroCount++;
        }
    }

    if(zeroCount <= (rows * cols) / 2) {
        cout << "The matrix is not sparse.\n";
    } else {
        cout << "The matrix is sparse.\n";

        int nonZeroCount = rows * cols - zeroCount;

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

        Element *transposed = new Element[nonZeroCount];
        for(int i = 0; i < nonZeroCount; i++){
            transposed[i].row = compact[i].col;
            transposed[i].col = compact[i].row;
            transposed[i].value = compact[i].value;
        }

        cout << "\nTransposed Matrix:\n";
        k = 0;
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows; j++){
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

        delete[] compact;
        delete[] transposed;
    }

    for(int i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}