#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Function to print employee averages
void printAverages(float avg[], int n) {
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(2) << avg[i] << " ";
    cout << endl;
}

// ---------------------------
// SELECTION SORT
// ---------------------------
void selectionSort(float avg[], int n) {
    cout << "\n--- Selection Sort Process ---\n";
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (avg[j] < avg[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            float temp = avg[i];
            avg[i] = avg[minIndex];
            avg[minIndex] = temp;

            cout << "Pass " << pass++ << ": ";
            printAverages(avg, n);
        }
    }
    cout << "Time Complexity: O(n^2)\n";
}

// ---------------------------
// MERGE SORT
// ---------------------------
void merge(float arr[], int l, int m, int r, int &pass) {
    int n1 = m - l + 1;
    int n2 = r - m;

    float *L = new float[n1];
    float *R = new float[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "Pass " << pass++ << ": ";
    printAverages(arr, r + 1);

    delete[] L;
    delete[] R;
}

void mergeSort(float arr[], int l, int r, int &pass) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, pass);
        mergeSort(arr, m + 1, r, pass);
        merge(arr, l, m, r, pass);
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    srand(time(0));
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    int *height = new int[n];
    int *weight = new int[n];
    float *avg = new float[n];
    float *avgCopy = new float[n];

    cout << "\nGenerated random height and weight:\n";
    for (int i = 0; i < n; i++) {
        height[i] = rand() % 61 + 140;  // 140–200 cm
        weight[i] = rand() % 71 + 40;   // 40–110 kg
        avg[i] = (height[i] + weight[i]) / 2.0;
        avgCopy[i] = avg[i];
        cout << "Emp" << i + 1 << ": " << height[i] << "cm, "
             << weight[i] << "kg -> Avg = " << fixed << setprecision(2) << avg[i] << endl;
    }

    // 1️⃣ Selection Sort
    selectionSort(avg, n);

    // 2️⃣ Merge Sort
    cout << "\n--- Merge Sort Process ---\n";
    int pass = 1;
    mergeSort(avgCopy, 0, n - 1, pass);
    cout << "Time Complexity: O(n log n)\n";

    // 3️⃣ Final Comparison
    cout << "\n--- Final Comparison ---\n";
    cout << "Selection Sort ->O(n^2)-> Slower for large data\n";
    cout << "Merge Sort     -> O(n log n)-> Faster due to divide & conquer\n";
    cout << "\n Conclusion: Merge Sort takes less time for large employee lists.\n";

    delete[] height;
    delete[] weight;
    delete[] avg;
    delete[] avgCopy;
    return 0;
}
