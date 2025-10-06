 2. Searching for a Student Record

### 📖 Problem Scenario
In the **Computer Engineering Department of VIT**, there are students from S.Y., T.Y., and B.Tech.  
We need to **identify a student** from **S.Y. Division X** whose:
- **Name:** XYZ  
- **Roll Number:** 17  

The goal is to use an appropriate **searching algorithm** to efficiently locate this student’s record.

### ⚙️ Searching Methods
There are two main types of searching algorithms:

#### 1. Linear Search
- Sequentially checks each record one by one.  
- Works well for **unsorted data**.  
- **Time Complexity:** O(n)

#### 2. Binary Search
- Works on **sorted data** only.  
- Compares the middle element with the target and eliminates half of the remaining elements in each step.  
- **Time Complexity:** O(log n)

### 🧩 Algorithm Steps (Binary Search)
1. Sort student records by roll number (if not already sorted).  
2. Compare the middle element’s roll number with the target (17).  
3. If matched, check the name and division.  
4. If not matched:
   - If target < middle → search left half.  
   - If target > middle → search right half.  

### 💡 Advantages
- **Linear Search:** Simple to implement for small data sets.  
- **Binary Search:** Very efficient for large, sorted data sets.  

### 📊 Applications
- Used in **student databases**, **attendance systems**, and **record management systems**.  
- Searching is a fundamental concept for **information retrieval**, **data analysis**, and **database indexing**.

---

## ⚙️ Compilation and Execution
```bash
g++ fast_transpose.cpp -o fast_transpose
./fast_transpose

g++ student_search.cpp -o student_search
./student_search
```

Program:

```cpp
#include <iostream>
#include <string>
using namespace std;

struct student_rrl {
    int roll_rrl;
    string name_rrl;
    string year_rrl;
    string div_rrl;
};

int main() {
    int n_rrl;
    cout << "Enter number of students: ";
    cin >> n_rrl;
    cin.ignore(); 

    student_rrl *arr = new student_rrl[n_rrl];

    cout << "Enter roll number, name, year, division for each student:\n";
    for (int i = 0; i < n_rrl; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> arr[i].roll_rrl;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, arr[i].name_rrl);
        cout << "Year (S.Y., T.Y., B.Tech.): ";
        getline(cin, arr[i].year_rrl);
        cout << "Division: ";
        getline(cin, arr[i].div_rrl);
    }

    int target_roll;
    cout << "\nEnter roll number you want to search: ";
    cin >> target_roll;

    bool found = false;
    for (int i = 0; i < n_rrl; i++) {
        if (arr[i].roll_rrl == target_roll) {
            cout << "\nStudent found!\n";
            cout << "Roll No: " << arr[i].roll_rrl << endl;
            cout << "Name: " << arr[i].name_rrl << endl;
            cout << "Year: " << arr[i].year_rrl << endl;
            cout << "Division: " << arr[i].div_rrl << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "\nStudent not found!";
    }

    delete[] arr;
    return 0;
}


```

Output:


<img width="673" height="397" alt="image" src="https://github.com/user-attachments/assets/c2b33cc3-3bde-4bf0-b0c5-e34ff0c783eb" />
