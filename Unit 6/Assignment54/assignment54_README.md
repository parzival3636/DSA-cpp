
# Assignment 54 - Hash Table Implementation for Storing and Retrieving Student Records Using Linear Probing

## Implementing Student Record Management Using Hash Table with Linear Probing Collision Resolution

This program demonstrates how to store and retrieve student records (including roll number, name, and marks) using a hash table. Collisions in the hash table are resolved using linear probing, where the program searches sequentially for an empty slot when the initially hashed index is occupied.

### Operations Implemented
- **Insert Record:**  
  The hash function computes the initial index from the student roll number using modulo operation. If the slot is occupied, linear probing checks subsequent slots cyclically until an empty slot is found for insertion.  
- **Search Record:**  
  Searches for a student by roll number starting from the hashed index and linearly probes through subsequent slots until the record is found or an empty slot indicates absence.  
- **Display Table:**  
  Shows the contents of the hash table, listing all stored student records with their roll numbers, names, and marks for verification.

### Key Concepts: Hashing and Linear Probing for Student Data
- **Hash Function:** Uses modulo arithmetic (`roll % TABLE_SIZE`) to map student roll numbers to hash table indices.  
- **Linear Probing:** On collision, sequential scan of the table wraps around to find the next available slot, avoiding insertion failure when the table has space elsewhere.  
- **Fixed Size Table:** The table size limits possible entries; full capacity results in insertion failure.  
- **Handling Records:** Records stored directly in the table array, with a parallel boolean array marking occupied slots to manage probing.

### Time Complexity
- **Average Case:** \(O(1)\) for insert and search with low load factor, as probing sequences are short.  
- **Worst Case:** \(O(n)\) when the table is nearly full and long probe sequences are needed.

### Example Scenario
| Operation       | Description                                              |
|-----------------|----------------------------------------------------------|
| Table size      | 10                                                       |
| Records inserted| Roll: 101, Name: Alice, Marks: 85                          |
|                 | Roll: 111, Name: Bob, Marks: 78                            |
|                 | Roll: 121, Name: Carol, Marks: 92                          |
| Search          | Roll 111 found at linear probe position 1                  |
| Search          | Roll 130 not found after checking all relevant slots       |
| Display         | Lists slots with stored roll, name, and marks details      |


```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

class Student {
public:
    int roll;
    char name[50];
    float marks;

    Student() {
        roll = -1;
        strcpy(name, "");
        marks = 0;
    }
};

class HashTableLP {
public:
    Student table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    HashTableLP() {
        for (int i = 0; i < TABLE_SIZE; i++)
            occupied[i] = false;
    }

    int hashFunction(int roll) {
        return roll % TABLE_SIZE;
    }

    void insertRecord(Student s) {
        int index = hashFunction(s.roll);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (!occupied[tryIndex]) {
                table[tryIndex] = s;
                occupied[tryIndex] = true;
                cout << "Record inserted!\n";
                return;
            }
        }
        cout << "Hash table full!\n";
    }

    void searchRecord(int roll) {
        int index = hashFunction(roll);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (occupied[tryIndex] && table[tryIndex].roll == roll) {
                cout << "Record Found:\n";
                cout << "Roll: " << table[tryIndex].roll << endl;
                cout << "Name: " << table[tryIndex].name << endl;
                cout << "Marks: " << table[tryIndex].marks << endl;
                return;
            }
        }
        cout << "Record Not Found!\n";
    }

    void displayTable() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            if (occupied[i])
                cout << table[i].roll << " | " << table[i].name 
                     << " | " << table[i].marks;
            cout << endl;
        }
    }
};

int main() {
    HashTableLP ht;
    int choice;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter Roll: ";
            cin >> s.roll;
            cout << "Enter Name: ";
            cin >> s.name;
            cout << "Enter Marks: ";
            cin >> s.marks;
            ht.insertRecord(s);
        }
        else if (choice == 2) {
            int r;
            cout << "Enter Roll to Search: ";
            cin >> r;
            ht.searchRecord(r);
        }
        else if (choice == 3) {
            ht.displayTable();
        }
        else {
            break;
        }
    }
    return 0;
}

```
### Applications
- Efficient and fast storage and retrieval of student records in educational management systems.  
- Situations requiring average constant-time lookup in fixed-size data tables.  
- Basis for more advanced hash table designs in database indexing and caching.

