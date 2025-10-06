# Sorting and Divide & Conquer Techniques in C++

## 📘 Description
This project demonstrates two key applications of **sorting algorithms** and **divide-and-conquer techniques** in C++:

1. **Bubble Sort and Quick Sort** on a structure containing student records.  
2. **Quick Sort Analysis (Pass by Pass)** and **finding minimum and maximum marks** using a **Divide and Conquer** approach.

Both programs highlight algorithmic efficiency, data organization, and recursive problem-solving.

---

## 🔹 1. Bubble Sort and Quick Sort on Student Records

### 📖 Problem Definition
Write a program to implement **Bubble Sort** and **Quick Sort** on a **1D array of structures**, where each structure contains:
- `student_name`
- `student_roll_no`
- `total_marks`

The sorting should be performed based on **student_roll_no** as the key.  
Additionally, count and display the **number of swaps** performed by each sorting algorithm.

---

### ⚙️ Algorithm Overview

#### 🔸 Bubble Sort
- A simple, comparison-based sorting algorithm.  
- Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
- After every pass, the largest unsorted element “bubbles up” to its correct position.

**Characteristics:**
- **Time Complexity:** O(n²)  
- **Stable:** Yes  
- **Best suited for:** Small datasets  
- **Swap Count:** Indicates algorithm efficiency (fewer swaps = faster performance)

#### 🔸 Quick Sort
- A **divide-and-conquer** algorithm.  
- Selects a **pivot** element, partitions the array around it so that elements less than the pivot come before it, and greater ones come after.
- Recursively applies the same logic to the subarrays.

**Characteristics:**
- **Time Complexity:** O(n log n) on average  
- **Unstable:** Yes  
- **Efficient for large datasets**

---

### 💡 Comparison
| Feature           | Bubble Sort | Quick Sort |
|-------------------|--------------|-------------|
| Approach          | Iterative    | Recursive   |
| Complexity (Avg.) | O(n²)        | O(n log n)  |
| Stability         | Stable       | Unstable    |
| Efficiency        | Low          | High        |
| Swaps Count       | High         | Low          |

---
Bubble sort:

Program:
```cpp
#include<iostream>
#include<string>
using namespace std;

struct student_rrl
{
    int roll_no_rrl;
    string name_rrl;
    int marks_rrl;
};

int main(){
    int n_rrl;
    cout << " Enter number of student";
    cin >> n_rrl;

    student_rrl *arr_rrl = new student_rrl[n_rrl];

    if (arr_rrl == NULL){
        cout << "Memory not allocated";
    }

    cout << "Enter student details (roll,name,marks) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cin >> arr_rrl[i_rrl].roll_no_rrl >> arr_rrl[i_rrl].name_rrl >> arr_rrl[i_rrl].marks_rrl;
    }

    cout << "Student Details (before sort) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cout <<"Roll number :"<<arr_rrl[i_rrl].roll_no_rrl <<" "<< "Name :" << arr_rrl[i_rrl].name_rrl <<" "<< "Marks : " << arr_rrl[i_rrl].marks_rrl << endl;
    }

    for(int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        for (int j_rrl = i_rrl + 1; j_rrl < n_rrl; j_rrl++){
            if (arr_rrl[i_rrl].roll_no_rrl > arr_rrl[j_rrl].roll_no_rrl){
                student_rrl temp_rrl = arr_rrl[i_rrl];
                arr_rrl[i_rrl] = arr_rrl[j_rrl];
                arr_rrl[j_rrl] = temp_rrl;
            }
        }
    }

    cout << "Student Details (after sort) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cout <<"Roll number :"<<arr_rrl[i_rrl].roll_no_rrl <<" "<< "Name :" << arr_rrl[i_rrl].name_rrl <<" "<< "Marks : " << arr_rrl[i_rrl].marks_rrl << endl;
    }

    return 0;
}
```

Output:


<img width="540" height="350" alt="image" src="https://github.com/user-attachments/assets/204bd016-4281-4028-a851-a8fd27806152" />

### 📊 Applications
- Sorting student data by roll numbers, marks, or names.  
- Useful in **database management**, **ranking systems**, and **result analysis**.
