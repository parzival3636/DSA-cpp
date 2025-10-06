Selection Sort and Merge Sort – Arranging Employees by Average of Height and Weight

### 📖 Problem Definition
Develop a program to:
- Store data for employees (e.g., `employee_name`, `height`, `weight`).  
- Calculate the **average = (height + weight) / 2** for each employee.  
- Sort the list in ascending order of average using:
  - **Selection Sort**
  - **Merge Sort**
- Compare their **time complexities** and conclude which one is more efficient.

---

### ⚙️ Algorithm Overview

#### 🔸 Selection Sort
- Finds the smallest element from the unsorted part and places it at the beginning.
- Repeats this process for all elements.

**Characteristics:**
- **Time Complexity:** O(n²)  
- **Space Complexity:** O(1)  
- **Stable:** No  
- **In-place:** Yes  
- **Best suited for:** Small datasets

---

#### 🔸 Merge Sort
- A **Divide and Conquer** algorithm that:
  1. Divides the array into halves recursively.
  2. Sorts each half.
  3. Merges the sorted halves into one.

**Characteristics:**
- **Time Complexity:** O(n log n)  
- **Space Complexity:** O(n)  
- **Stable:** Yes  
- **In-place:** No (uses temporary arrays)  
- **Best suited for:** Large datasets requiring efficient sorting.

---

### ⚖️ Comparison Table

| Feature             | Selection Sort | Merge Sort |
|---------------------|----------------|-------------|
| Approach            | Iterative      | Recursive   |
| Complexity (Avg.)   | O(n²)          | O(n log n)  |
| Space Requirement   | O(1)           | O(n)        |
| Stability           | No             | Yes         |
| Efficiency (Large n)| Low            | High        |

---


Program:
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printAverages(float avg[], int n) {
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(2) << avg[i] << " ";
    cout << endl;
}

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
        height[i] = rand() % 61 + 140;
        weight[i] = rand() % 71 + 40;
        avg[i] = (height[i] + weight[i]) / 2.0;
        avgCopy[i] = avg[i];
        cout << "Emp" << i + 1 << ": " << height[i] << "cm, "
             << weight[i] << "kg -> Avg = " << fixed << setprecision(2) << avg[i] << endl;
    }

    selectionSort(avg, n);

    cout << "\n--- Merge Sort Process ---\n";
    int pass = 1;
    mergeSort(avgCopy, 0, n - 1, pass);
    cout << "Time Complexity: O(n log n)\n";

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

```

Output:



<img width="632" height="427" alt="image" src="https://github.com/user-attachments/assets/336415ab-d8e8-4731-a1f6-68547c472547" />



### 🧠 Conclusion
- **Selection Sort** is simple but inefficient for large data due to its quadratic time complexity.  
- **Merge Sort** is faster for large datasets because of its **O(n log n)** complexity.  
- In practical scenarios like arranging employee records, **Merge Sort** significantly reduces computation time.

---

## ⚙️ Compilation and Execution
```bash
g++ bubble_sort_students.cpp -o bubble_sort_students
./bubble_sort_students

g++ employee_sort.cpp -o employee_sort
./employee_sort
