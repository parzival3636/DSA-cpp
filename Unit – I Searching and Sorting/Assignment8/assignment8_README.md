# Assignment8

## 📘 Description
 Quick Sort (Marks Sorting) and Divide & Conquer (Min–Max Finder)

### 📖 Problem Definition
Develop a program to:
1. Input marks of **n students**.  
2. Sort the marks in **ascending order using Quick Sort** (without using built-in functions).  
3. Analyze the sorting **pass by pass** to understand recursive division.  
4. Use a **Divide and Conquer** approach to find the **minimum and maximum marks** recursively.

---

### ⚙️ Algorithm Overview

#### 🔸 Quick Sort (Stepwise Analysis)
1. Choose a **pivot** element (e.g., first or last element).  
2. Partition the array so elements smaller than the pivot go to the left, and greater ones to the right.  
3. Recursively apply the same procedure to subarrays.  
4. Display array after each **pass** to show progress.

**Analysis Example (Pass by Pass):**


<img width="362" height="149" alt="image" src="https://github.com/user-attachments/assets/895f68cd-e205-4610-a99d-6dfa92023555" />




---

#### 🔸 Divide and Conquer (Finding Min and Max)
- The array is divided into two halves recursively.  
- The **minimum** and **maximum** of each half are found.  
- Results are combined to determine the overall min and max.

**Steps:**
1. If the array has one element → it is both min and max.  
2. If it has two elements → compare and assign min/max.  
3. Otherwise, divide into halves, find min and max in each half recursively, then combine results.

**Time Complexity:** O(n)

---

### 💡 Key Concepts
- **Divide and Conquer:** Breaks a large problem into smaller subproblems and merges their results.  
- **Recursive Sorting:** Enhances understanding of data partitioning.  
- **Pass Analysis:** Demonstrates how sorting progresses internally.

---

### 📊 Applications
- Ranking students by marks.  
- Performance benchmarking of sorting algorithms.  
- Real-world applications in **data analytics**, **report generation**, and **result computation systems**.

---

## ⚙️ Compilation and Execution
```bash
g++ student_sort.cpp -o student_sort
./student_sort

g++ quicksort_minmax.cpp -o quicksort_minmax
./quicksort_minmax

```


Program:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int passCount = 0;

void swap_marks(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int findMin(int arr[], int low, int high) {
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);
    return (leftMin < rightMin) ? leftMin : rightMin;
}

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


```

Output:


<img width="481" height="398" alt="image" src="https://github.com/user-attachments/assets/69b5d3b0-57cf-4cb6-9a7e-5bd487804461" />
