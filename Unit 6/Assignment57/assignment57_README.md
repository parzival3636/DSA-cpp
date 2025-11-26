# Assignment57

# Faculty Database Using Hash Table (MOD Hash, Linear Probing + Chaining With Replacement)

## Simulating a Faculty Database with Chaining and Record Replacement

This program also simulates a faculty database using a hash table, but employs the MOD hash function and collision resolution via linear probing with chaining and replacement. In this method, if a record occupying a slot does not belong to that slot’s hash index, it can be moved (replaced) to optimize access for newly inserted keys.

### Operations Implemented
- **Insert Faculty Record:**  
  - Compute index using `facultyID % TABLE_SIZE`.  
  - If slot is empty, insert the record.  
  - If slot is occupied:
    - If the existing record is not in its home position (its hash index differs from the current index), move it to a suitable probed location and place the new key in its correct hashed position (replacement).
    - Otherwise, use linear probing to find the next free slot and update the chain from the home slot.
- **Search Faculty Record:**  
  - Start at the faculty ID’s home position (computed by MOD).  
  - Follow the chain or probe sequence to find the matching record.  
- **Display Database:**  
  - Show each slot with faculty data and link indices, highlighting where replacement and chaining occurred.

### Key Concepts
- **MOD Hash Function:** The same divide/modulo idea, explicitly noted as MOD for hashing.  
- **Chaining With Replacement:** Allows re-positioning of existing records to keep each key as close as possible to its home slot, improving average search performance.  
- **Improved Locality:** Searching often starts exactly at or very near the home position of each key.

### Example Scenario
- Table size: 10  
- Insert IDs such that some keys initially occupy non-home positions.  
- When inserting a new faculty whose home slot is occupied by a key that doesn’t belong there, the existing key is moved to another suitable location, and the new key is placed at its true home index, updating chains accordingly.

---


## code
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

struct Faculty {
    int id;
    char name[50];
    char dept[50];
};

class HashTable {
public:
    Faculty table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    int chain[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            occupied[i] = false;
            chain[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insertRecord(int id, const char nm[], const char dp[]) {
        int index = hashFunction(id);

        if (!occupied[index]) {
            table[index].id = id;
            strcpy(table[index].name, nm);
            strcpy(table[index].dept, dp);
            occupied[index] = true;
        }
        else {
            int existingKey = table[index].id;
            int existingIndex = hashFunction(existingKey);

            if (existingIndex != index) {
                Faculty temp = table[index];
                table[index].id = id;
                strcpy(table[index].name, nm);
                strcpy(table[index].dept, dp);

                int newIndex = (index + 1) % TABLE_SIZE;
                while (occupied[newIndex])
                    newIndex = (newIndex + 1) % TABLE_SIZE;

                table[newIndex] = temp;
                occupied[newIndex] = true;

                int head = existingIndex;
                while (chain[head] != index && chain[head] != -1)
                    head = chain[head];

                chain[head] = newIndex;
            }
            else {
                int newIndex = (index + 1) % TABLE_SIZE;
                while (occupied[newIndex])
                    newIndex = (newIndex + 1) % TABLE_SIZE;

                table[newIndex].id = id;
                strcpy(table[newIndex].name, nm);
                strcpy(table[newIndex].dept, dp);
                occupied[newIndex] = true;

                int head = index;
                while (chain[head] != -1)
                    head = chain[head];
                chain[head] = newIndex;
            }
        }

        cout << "Record inserted.\n";
    }

    void searchRecord(int id) {
        int index = hashFunction(id);

        while (index != -1) {
            if (occupied[index] && table[index].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Department: " << table[index].dept << endl;
                return;
            }
            index = chain[index];
        }
        cout << "Faculty not found.\n";
    }

    void displayTable() {
        cout << "\nIndex | ID  Chain\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            if (occupied[i])
                cout << table[i].id << " | " << chain[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, id;
    char name[50], dept[50];

    while (true) {
        cout << "\n1.Insert  2.Search  3.Display  4.Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            ht.insertRecord(id, name, dept);
        }
        else if (choice == 2) {
            cout << "Enter ID to search: ";
            cin >> id;
            ht.searchRecord(id);
        }
        else if (choice == 3) {
            ht.displayTable();
        }
        else break;
    }
    return 0;
}

```

## output
<img width="406" height="561" alt="image" src="https://github.com/user-attachments/assets/5d77de43-d61a-4c75-a6f1-a95a98395aa9" />

