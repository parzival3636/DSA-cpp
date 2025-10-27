# Assignment9

## 📘 Description
Bubble Sort – Assigning Roll Numbers to Students

### 📖 Problem Definition
Develop a program to:
- Input students’ marks or total scores from the previous year.  
- Sort them in **descending order** using the **Bubble Sort algorithm** so that the **topper gets roll number 1**, the second-highest gets roll number 2, and so on.  
- Display the sorting process **pass by pass** to visualize how the algorithm gradually arranges the data.

---

### ⚙️ Algorithm Overview
**Bubble Sort** repeatedly compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest (or smallest) element “bubbles up” to its correct position.

**Pass-by-pass Analysis Example:**


<img width="325" height="141" alt="image" src="https://github.com/user-attachments/assets/799caa3a-2a1f-469c-b3ef-3b6ea51a2ca9" />




Program:
```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

void printOrder(Student arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << "(" << arr[i].marks << ")";
        if (i != n-1) cout << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    Student *cls = new (nothrow) Student[n];
    if (!cls) {
        cout << "Memory allocation failed!\n";
        return 1;
    }

    cout << "\nEnter name and marks for each student:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << " Name: ";
        getline(cin, cls[i].name);
        cout << "Student " << i + 1 << " Marks: ";
        cin >> cls[i].marks;
        cin.ignore();
        cls[i].roll = 0;
    }

    cout << "\nOriginal order (Name(Marks)):\n";
    printOrder(cls, n);

    cout << "\n--- Bubble Sort (assign topper roll 1) ---\n";
    int totalSwaps = 0;
    int passesUsed = 0;

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        cout << "\nPass " << pass + 1 << ":\n";

        for (int j = 0; j < n - 1 - pass; ++j) {
            if (cls[j].marks < cls[j + 1].marks) {
                ++totalSwaps;
                swapped = true;
                cout << "  Swap " << totalSwaps << ": swapping "
                     << cls[j].name << "(" << cls[j].marks << ") and "
                     << cls[j + 1].name << "(" << cls[j + 1].marks << ") -> ";

                Student temp = cls[j];
                cls[j] = cls[j + 1];
                cls[j + 1] = temp;

                printOrder(cls, n);
            }
        }

        ++passesUsed;
        if (!swapped) {
            cout << "  No swaps in this pass — array is already sorted.\n";
            break;
        } else {
            cout << "  After pass " << pass + 1 << ": ";
            printOrder(cls, n);
        }
    }

    for (int i = 0; i < n; ++i) {
        cls[i].roll = i + 1;
    }

    cout << "\n--- Final Roll Assignment (Topper = Roll 1) ---\n";
    cout << left << setw(6) << "Roll" << setw(25) << "Name" << "Marks\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << left << setw(6) << cls[i].roll
             << setw(25) << cls[i].name
             << cls[i].marks << '\n';
    }

    cout << "\nTotal passes used: " << passesUsed << endl;
    cout << "Total swaps made: " << totalSwaps << endl;

    delete[] cls;
    return 0;
}


```


Output:



<img width="734" height="632" alt="image" src="https://github.com/user-attachments/assets/c72f224a-4da1-483f-a5a3-36d21a623125" />


**Characteristics:**
- **Best Case:** O(n) (if already sorted)
- **Worst Case:** O(n²)
- **Stable:** Yes  
- **Space Complexity:** O(1)

---

### 💡 Significance
- Helps visualize **how sorting works step-by-step**.  
- Demonstrates how performance ranking can be used to assign identifiers such as roll numbers.  
- Reinforces the concept of **stability** in sorting (equal marks retain their original order).

