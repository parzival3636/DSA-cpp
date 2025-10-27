#include <iostream>
#include <iomanip>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

void fastTranspose(Element a[], Element b[], int rows, int cols, int nonZero) {
    int* colCount = new int[cols]();
    int* startPos = new int[cols]();

    for (int i = 0; i < nonZero; i++)
        colCount[a[i].col]++;

    startPos[0] = 0;
    for (int i = 1; i < cols; i++)
        startPos[i] = startPos[i - 1] + colCount[i - 1];

    for (int i = 0; i < nonZero; i++) {
        int pos = startPos[a[i].col];
        b[pos].row = a[i].col;
        b[pos].col = a[i].row;
        b[pos].value = a[i].value;
        startPos[a[i].col]++;
    }

    delete[] colCount;
    delete[] startPos;
}

void printMatrix(int rows, int cols, Element arr[], int nonZero) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool found = false;
            for (int t = 0; t < nonZero; t++) {
                if (arr[t].row == i && arr[t].col == j) {
                    cout << setw(4) << arr[t].value;
                    found = true;
                    break;
                }
            }
            if (!found) cout << setw(4) << 0;
        }
        cout << endl;
    }
}

int main() {
    int rows, cols, nonZero;
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    Element* a = new Element[nonZero];
    Element* b = new Element[nonZero];

    cout << "Enter row, col, value of each non-zero element:\n";
    for (int i = 0; i < nonZero; i++)
        cin >> a[i].row >> a[i].col >> a[i].value;

    cout << "\nOriginal Matrix:\n";
    printMatrix(rows, cols, a, nonZero);

    fastTranspose(a, b, rows, cols, nonZero);

    cout << "\nFast Transposed Matrix:\n";
    printMatrix(cols, rows, b, nonZero);

    delete[] a;
    delete[] b;

    return 0;
}