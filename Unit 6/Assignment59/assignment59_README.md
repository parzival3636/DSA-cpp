# Assignment59

# Student Database Management Using Hash Table

## Simulating Student Databases with Hashing for Efficient Operations

This program implements a student database management system using a hash table to support efficient insertion, search, and deletion of student records. Each record typically stores fields such as Roll Number, Name, Division, and CGPA. Hashing is used to map roll numbers (or any unique key) to indices in a fixed-size table, minimizing access time.

### Operations Implemented
- **Insert Student Record:**  
  Uses a hash function (e.g., MOD or Mid-Square) on the roll number to compute the index. If a collision occurs, a collision-resolution strategy like linear probing or separate chaining is applied to find an appropriate slot.
- **Search Student Record:**  
  Recomputes the hash index from the key and searches along the probe sequence or within the chain to quickly locate the student's record, if present.
- **Delete Student Record:**  
  Locates the record via hashing and then removes or marks the slot as deleted, ensuring subsequent searches are still correct under the chosen collision-handling method.

### Key Concepts: Hashing for Student Databases
- **Hash Function:** Transforms a roll number into an array index for near-constant-time access.
- **Collision Handling:** Techniques such as linear probing, quadratic probing, or separate chaining minimize performance degradation when multiple keys map to the same index.
- **Efficiency:** Hashing enables average-case \(O(1)\) time for insert, search, and delete operations, making it suitable for large student datasets.

### Time Complexity
- **Average Case:** \(O(1)\) for insertion, search, and deletion with a good hash function and low load factor.
- **Worst Case:** \(O(n)\) when collisions are excessive or the table is nearly full.

### Example Scenario
| Operation        | Description                                                  |
|------------------|--------------------------------------------------------------|
| Insert           | Add students with roll numbers 101, 115, 129 to the table.  |
| Search           | Quickly retrieve record of roll 115 using hashing.          |
| Delete           | Remove record of roll 129 and mark its slot as deleted.     |

### Applications
- Academic record management for colleges and schools.  
- Fast lookup of student details in portals, ERP systems, and exam management tools.  
- Foundation for more sophisticated database indexing mechanisms.


## code
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

struct Student {
    int roll;
    char name[50];
    bool occupied;
    bool deleted;
};

class HashTable {
public:
    Student table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i].occupied = false;
            table[i].deleted = false;
        }
    }

    int hashFunc(int key) {
        return key % SIZE;
    }

    void insertRecord(int roll, const char nm[]) {
        int index = hashFunc(roll);
        int start = index;

        while (table[index].occupied && !table[index].deleted) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "Hash table full.\n";
                return;
            }
        }

        table[index].roll = roll;
        strcpy(table[index].name, nm);
        table[index].occupied = true;
        table[index].deleted = false;

        cout << "Record inserted.\n";
    }

    void searchRecord(int roll) {
        int index = hashFunc(roll);
        int start = index;

        while (table[index].occupied || table[index].deleted) {
            if (table[index].occupied && table[index].roll == roll) {
                cout << "\nStudent Found:\n";
                cout << "Roll: " << table[index].roll << endl;
                cout << "Name: " << table[index].name << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        cout << "Student not found.\n";
    }

    void deleteRecord(int roll) {
        int index = hashFunc(roll);
        int start = index;

        while (table[index].occupied || table[index].deleted) {
            if (table[index].occupied && table[index].roll == roll) {
                table[index].occupied = false;
                table[index].deleted = true;
                cout << "Record deleted.\n";
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Record not found.\n";
    }

    void displayTable() {
        cout << "\nIndex : Roll  Name\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << " : " << table[i].roll << "  " << table[i].name << endl;
            else
                cout << i << " : ---\n";
        }
    }
};

int main() {
    HashTable ht;
    int ch, roll;
    char name[50];

    while (true) {
        cout << "\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter Roll: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            ht.insertRecord(roll, name);
        }
        else if (ch == 2) {
            cout << "Enter Roll to search: ";
            cin >> roll;
            ht.searchRecord(roll);
        }
        else if (ch == 3) {
            cout << "Enter Roll to delete: ";
            cin >> roll;
            ht.deleteRecord(roll);
        }
        else if (ch == 4) {
            ht.displayTable();
        }
        else break;
    }
    return 0;
}

```

## output 

<img width="339" height="689" alt="image" src="https://github.com/user-attachments/assets/40fefd80-ec36-4894-9320-e84f94c2c5a7" />

