#include <iostream>
#include <iomanip>
using namespace std;

int passCount = 0; // To count passes during Quick Sort

// Swap two integers
void swap_marks(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                passCount++;
                cout << "Pass " << passCount << ": Swapped " << arr[i] << " and " << arr[j] << " -> ";
                swap_marks(arr[i], arr[j]);
                printArray(arr, n);
            }
        }
    }

    if (i + 1 != high) {
        passCount++;
        cout << "Pass " << passCount << ": Swapped " << arr[i + 1] << " and " << arr[high] << " -> ";
        swap_marks(arr[i + 1], arr[high]);
        printArray(arr, n);
    }

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

// Divide & Conquer to find minimum
int findMin(int arr[], int low, int high) {
    if (low == high) return arr[low]; // Only one element
    int mid = (low + high) / 2;
    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);
    return (leftMin < rightMin) ? leftMin : rightMin;
}

// Divide & Conquer to find maximum
int findMax(int arr[], int low, int high) {
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int* marks = new int[n];
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    cout << "\nOriginal Marks: ";
    printArray(marks, n);

    cout << "\n--- Quick Sort Analysis ---\n";
    quickSort(marks, 0, n - 1, n);

    cout << "\nFinal Sorted Marks: ";
    printArray(marks, n);
    cout << "Total passes required: " << passCount << endl;

    int minMark = findMin(marks, 0, n - 1);
    int maxMark = findMax(marks, 0, n - 1);

    cout << "\nMinimum Mark: " << minMark << endl;
    cout << "Maximum Mark: " << maxMark << endl;

    delete[] marks;
    return 0;
}
