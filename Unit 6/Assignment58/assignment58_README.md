# Assignment58

#  Employee Database Using Hash Table (Mid-Square Hash, Linear Probing)

## Simulating an Employee Database with Mid-Square Hash Function

This program simulates an employee database (can be adapted for faculty records as well) using a hash table. It uses the Mid-Square hash function to compute indices and uses linear probing for collision resolution.

### Operations Implemented
- **Insert Employee Record:**  
  - Compute a hash index by squaring the key (employee ID), extracting the middle digits, and then taking modulo by the table size (Mid-Square method).  
  - If the computed index is free, store the record there.  
  - If occupied, apply linear probing to scan sequential slots (wrapping around) until a free slot is found.
- **Search Employee Record:**  
  - Recompute the same Mid-Square hash index for the employee ID.  
  - Check the slot; if not found, linearly probe further until the record is found or an empty slot is encountered (indicating absence).  
- **Display Hash Table:**  
  - List all indices along with stored employee IDs, names, and departments for verification.

### Key Concepts
- **Mid-Square Hash Function:**  
  - Square the key value (e.g., \(key^2\)).  
  - Extract a suitable number of middle digits from the square.  
  - Reduce it using modulo table size if needed to get a valid index.  
- **Linear Probing:** Sequentially checks the next indices to resolve collisions, wrapping around at the end of the table.  
- **Employee Record Fields:** Typically store ID, name, department, and possibly salary or designation.

### Example Scenario
- Table size: 10  
- Employee ID: 123 → \(123^2 = 15129\); middle digits (e.g., “12”) → `12 % 10 = 2`, so index 2.  
- If index 2 is occupied by another employee, linear probing attempts indices 3, 4, 5, etc., until a free one is found.  
- Searching follows the same computed index and probe order.


## Code
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

struct Employee {
    int id;
    char name[50];
    bool occupied;
};

class HashTable {
public:
    Employee table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i].occupied = false;
        }
    }

    int midSquare(int key) {
        long long sq = (long long)key * key;
        sq = (sq / 10) % 1000;
        return sq % SIZE;
    }

    void insertRecord(int id, const char nm[]) {
        int index = midSquare(id);
        int start = index;

        while (table[index].occupied) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "Hash table full.\n";
                return;
            }
        }

        table[index].id = id;
        strcpy(table[index].name, nm);
        table[index].occupied = true;

        cout << "Record inserted.\n";
    }

    void searchRecord(int id) {
        int index = midSquare(id);
        int start = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Employee not found.\n";
    }

    void displayTable() {
        cout << "\nIndex  :  Data\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << " : " << table[i].id << " " << table[i].name << endl;
            else
                cout << i << " : ---\n";
        }
    }
};

int main() {
    HashTable ht;
    int ch, id;
    char name[50];

    while (true) {
        cout << "\n1.Insert  2.Search  3.Display  4.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            ht.insertRecord(id, name);
        }
        else if (ch == 2) {
            cout << "Enter ID to search: ";
            cin >> id;
            ht.searchRecord(id);
        }
        else if (ch == 3) {
            ht.displayTable();
        }
        else break;
    }
    return 0;
}

```

## output
<img width="361" height="530" alt="image" src="https://github.com/user-attachments/assets/221c0903-a7a2-4123-9278-5e54f9d872da" />
