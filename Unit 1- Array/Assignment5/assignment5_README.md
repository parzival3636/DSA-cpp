# Fast Transpose of Sparse Matrix and Searching Techniques

## 📘 Description
This project implements two core concepts in data structures and algorithms:
1. **Fast Transpose of Sparse Matrix using Compact Representation**
2. **Searching a Student Record using an Appropriate Searching Method**

Both programs focus on efficiency in data access and memory utilization.

---

## 🔹 1. Fast Transpose of Sparse Matrix

### 📖 Theory
A **sparse matrix** contains mostly zero elements.  
Instead of storing all elements, we store only non-zero values using the **compact (triplet) representation**, where each non-zero element is represented as:


For a 4×5 matrix:
0 0 3 0 4
0 0 5 7 0
0 0 0 0 0
0 2 6 0 0


The triplet representation is:
Row | Col | Value
0 | 2 | 3
0 | 4 | 4
1 | 2 | 5
1 | 3 | 7
3 | 1 | 2
3 | 2 | 6



Program:


```cpp
#include <iostream>
#include <iomanip>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

void fastTranspose(Element a[], Element b[], int rows, int cols, int nonZero) {
    int colCount[cols] = {0};
    int startPos[cols] = {0};

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
}

void printMatrix(int rows, int cols, Element arr[], int nonZero) {
    int k = 0;
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

    Element a[nonZero];
    Element b[nonZero];

    cout << "Enter row, col, value of each non-zero element:\n";
    for (int i = 0; i < nonZero; i++)
        cin >> a[i].row >> a[i].col >> a[i].value;

    cout << "\nOriginal Matrix:\n";
    printMatrix(rows, cols, a, nonZero);

    fastTranspose(a, b, rows, cols, nonZero);

    cout << "\nFast Transposed Matrix:\n";
    printMatrix(cols, rows, b, nonZero);

    return 0;
}

```


Outputs:

<img width="501" height="473" alt="image" src="https://github.com/user-attachments/assets/bc7e58d4-5e88-477c-9039-0d3b3ad35135" />






### ⚙️ Fast Transpose Concept
The **simple transpose** swaps the row and column indices but may take longer if done inefficiently.  
The **fast transpose** algorithm improves efficiency by directly computing the position of each transposed element.

#### 🔸 Steps of Fast Transpose
1. **Count elements** in each column of the original matrix.  
2. **Determine starting positions** of each column in the transposed matrix.  
3. **Place elements directly** in their new transposed positions using precomputed indices.

This avoids multiple passes through the data, making it faster than the simple transpose method.

### 💡 Advantages
- Faster than the simple transpose (single-pass method).  
- Requires no extra loops for sorting.  
- Memory-efficient for large, sparse matrices.

### 📊 Applications
- Used in matrix operations for **scientific computing**.  
- Essential in **image processing**, **machine learning**, and **graph algorithms**.  
- Efficient for large **data compression** and **storage optimization** tasks.


