# Sparse Matrix Representation and Operations

## 📘 Description
A **sparse matrix** is a matrix that contains a large number of zero elements.  
Storing all the zero elements in memory is inefficient, so we use a **compact representation** that stores only the **non-zero elements**.  
This approach reduces memory usage and improves computational efficiency.

---

## 🔹 Compact Representation (Triplet Form)
In this method, only the non-zero elements of the matrix are stored in the form of **triplets**:
- **Row index**
- **Column index**
- **Value**

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

```

##**Output**:


<img width="480" height="614" alt="image" src="https://github.com/user-attachments/assets/a834f56d-933b-4eb3-b178-dead24666939" />




This form saves storage space and is ideal for large, sparse data sets.

---

## ⚙️ Operations Performed

### 1. Display
- The display operation prints the **triplet representation** of the sparse matrix.
- It helps visualize which elements are non-zero and their positions.

### 2. Simple Transpose
- The transpose of a matrix is obtained by interchanging its rows and columns.  
- For each element `(row, col, value)` in the sparse matrix, the transposed matrix will contain `(col, row, value)`.
- This operation is performed efficiently on the compact representation without reconstructing the full matrix.

---

## 💡 Advantages of Sparse Matrix Representation
- **Efficient Memory Usage:** Only non-zero elements are stored, reducing memory consumption.  
- **Faster Computations:** Operations skip over zero elements, improving speed.  
- **Easy Transposition:** Swapping indices is simple and efficient in triplet form.  
- **Useful in Applications:** Especially beneficial in fields like scientific computing, graph theory, and machine learning.

---

## 📊 Applications
- Representing large systems of linear equations.  
- Storing **graph adjacency matrices**.  
- Handling **image data**, **neural networks**, and **optimization problems**.  
- Used in **computer simulations**, **data mining**, and **machine learning algorithms** where most data values are zero.
