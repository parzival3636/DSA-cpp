#include <iostream>
#include <cstdlib>  // for exit()
using namespace std;

int main() {
    int n;

    // 1. Read n and validate
    cout << "Enter the value of n (odd number > 0): ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << "Error: n must be a positive odd number." << endl;
        exit(-1);
    }

    // 2. Dynamically allocate n x n matrix
    int** magic_square = new int*[n];
    for (int i = 0; i < n; i++)
        magic_square[i] = new int[n];

    // Initialize all cells to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic_square[i][j] = 0;

    // 3. Start at row = 0, col = n / 2
    int row = 0;
    int col = n / 2;

    // 4. Fill numbers from 1 to n*n
    for (int num = 1; num <= n * n; num++) {
        magic_square[row][col] = num;

        // Tentative next position
        int next_row = row - 1;
        int next_col = col + 1;

        // Wrap around edges
        if (next_row < 0) next_row = n - 1;
        if (next_col == n) next_col = 0;

        // If next cell is occupied, move down from current
        if (magic_square[next_row][next_col] != 0) {
            next_row = (row + 1) % n;
            next_col = col;
        }

        // Update row and col
        row = next_row;
        col = next_col;
    }

    // 5. Print magic square and magic sum
    cout << "\nMagic Square of order " << n << ":\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << magic_square[i][j] << "\t";
        cout << endl;
    }

    cout << "\nMagic Sum: " << n * (n * n + 1) / 2 << endl;

    // 6. Free dynamically allocated memory
    for (int i = 0; i < n; i++)
        delete[] magic_square[i];
    delete[] magic_square;

    return 0;
}