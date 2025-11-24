
# Assignment 55 - Faculty Database Simulation Using Hash Table with Linear Probing

## Implementing a Faculty Database with Linear Probing Collision Resolution Using Modulo Hash Function

This program simulates a faculty database where each faculty record (including faculty ID, name, and department) is stored in a hash table. Collisions are resolved using linear probing, and the hash function uses the modulo operation on faculty IDs to compute the index.

### Operations Implemented
- **Insert Faculty Record:**  
  Calculate the initial hash index using `facultyID % TABLE_SIZE`. If the slot is occupied, linear probing is used to find the next available slot to insert the record.  
- **Search Faculty Record:**  
  Using the same hash function, search for the faculty by their ID. If a collision occurs, probe sequentially until the record is found or an empty slot indicates absence.  
- **Display Database:**  
  Show all records stored in the hash table with their ID, name, and department.

### Key Concepts: Hashing and Linear Probing for Faculty Records
- **Hash Function:** A modulo operation (`facultyID % TABLE_SIZE`) to map faculty IDs into the hash table.  
- **Linear Probing:** Handles collisions by checking slots sequentially, wrapping around at the end of the table, to resolve clashes robustly.  
- **Fixed Table Size:** The hash table has limited capacity; excessive entries may lead to insertion failure if no empty slot exists.  
- **Direct Storage:** Faculty records stored directly in an array, with tracking of occupied slots to manage probing.

### Time Complexity
- **Average Case:** \(O(1)\) for insertion and search in low load factor scenarios due to minimal collisions.  
- **Worst Case:** \(O(n)\) when many collisions cause long probe sequences or table nearing full capacity.

### Example Scenario
| Operation        | Description                                            |
|------------------|--------------------------------------------------------|
| Table Size       | 10                                                     |
| Inserted Records | ID: 201, Name: Dr. Smith, Dept: Computer Science       |
|                  | ID: 211, Name: Dr. Lee, Dept: Electrical Engineering    |
|                  | ID: 221, Name: Dr. Patel, Dept: Mechanical Engineering  |
| Search           | ID 211 found at linear probe index 1                   |
| Search           | ID 230 not found after checking the probe sequence     |
| Display          | Lists all filled slots with faculty details             |


```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

class Faculty {
public:
    int id;
    char name[50];
    char dept[50];

    Faculty() {
        id = -1;
        strcpy(name, "");
        strcpy(dept, "");
    }
};

class HashTable {
public:
    Faculty table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            occupied[i] = false;
    }

    // MOD hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert faculty record
    void insertRecord(Faculty f) {
        int index = hashFunction(f.id);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (!occupied[tryIndex]) {
                table[tryIndex] = f;
                occupied[tryIndex] = true;
                cout << "Faculty inserted successfully!\n";
                return;
            }
        }
        cout << "Hash table is full! Cannot insert.\n";
    }

    // Search faculty by ID
    void searchRecord(int id) {
        int index = hashFunction(id);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (occupied[tryIndex] && table[tryIndex].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[tryIndex].id << endl;
                cout << "Name: " << table[tryIndex].name << endl;
                cout << "Department: " << table[tryIndex].dept << endl;
                return;
            }
        }
        cout << "Faculty not found!\n";
    }

    // Display entire hash table
    void displayTable() {
        cout << "\n--- Faculty Hash Table ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            if (occupied[i]) {
                cout << table[i].id << " | " << table[i].name 
                     << " | " << table[i].dept;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Faculty f;
            cout << "Enter Faculty ID: ";
            cin >> f.id;
            cout << "Enter Faculty Name: ";
            cin >> f.name;
            cout << "Enter Department: ";
            cin >> f.dept;

            ht.insertRecord(f);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            ht.searchRecord(id);
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
- Maintaining faculty or employee databases with quick retrievals.  
- Useful in scenarios where average constant-time data access is required.  
- Foundational for hashing techniques in database indexing and memory management.

