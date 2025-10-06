# Assignment2

# Magic Square and Matrix Multiplication in C++

## 📘 Description

This program implements **two important numerical concepts** in C++:

### 1. Magic Square
- A **magic square** is a square matrix in which the sum of every row, column, and both main diagonals is the same.  
- This program can construct magic squares for both **odd and even orders**:
  - **Odd order (Siamese method)**: Fill numbers 1 to n² in a specific diagonal pattern.  
  - **Even order**: Use appropriate algorithms depending on whether `n` is doubly-even or singly-even.
- After constructing the square, the program **verifies** its correctness by summing all rows, columns, and diagonals.  

**Applications:** Magic squares have applications in combinatorial mathematics, cryptography, and puzzle design.

---

### 2. Matrix Multiplication
- Multiplies two matrices using **row-major** and **column-major** memory access patterns.  
- **Row-major order:** Consecutive elements of a row are stored in contiguous memory.  
- **Column-major order:** Consecutive elements of a column are stored in contiguous memory.  
- The program measures execution time for both approaches to **analyze cache performance** and how memory layout affects computation speed.  

**Key Concept:** Modern CPUs use caching to speed up memory access. Accessing memory in the order it is laid out improves cache hits, which reduces execution time.

---

## ⚙️ How to Compile and Run
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of n (odd number > 0): ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << "Error: n must be a positive odd number." << endl;
        exit(-1);
    }

    int** magic_square = new int*[n];
    for (int i = 0; i < n; i++)
        magic_square[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic_square[i][j] = 0;

    int row = 0;
    int col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magic_square[row][col] = num;

        int next_row = row - 1;
        int next_col = col + 1;

        if (next_row < 0) next_row = n - 1;
        if (next_col == n) next_col = 0;

        if (magic_square[next_row][next_col] != 0) {
            next_row = (row + 1) % n;
            next_col = col;
        }

        row = next_row;
        col = next_col;
    }

    cout << "\nMagic Square of order " << n << ":\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << magic_square[i][j] << "\t";
        cout << endl;
    }

    cout << "\nMagic Sum: " << n * (n * n + 1) / 2 << endl;

    for (int i = 0; i < n; i++)
        delete[] magic_square[i];
    delete[] magic_square;

    return 0;
}
```


##**Output:**


<img width="438" height="165" alt="image" src="https://github.com/user-attachments/assets/70943164-8e02-42e0-bbef-0d21c0fc09f5" />
