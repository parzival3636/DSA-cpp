# Assignment56

# – Faculty Database Using Hash Table (Divide Hash, Linear Probing + Chaining Without Replacement)

## Simulating a Faculty Database with Hybrid Collision Handling

This program simulates a faculty database using a hash table where each record stores information such as Faculty ID, Name, and Department. The hash function uses the Divide method (`key % table_size`), and collisions are handled using a combination of linear probing and chaining without replacement. Existing keys remain in their original hashed positions, while collided keys are linked via a chain.

### Operations Implemented
- **Insert Faculty Record:**  
  - Compute index using `facultyID % TABLE_SIZE`.  
  - If slot is empty, insert the record there.  
  - If occupied, find the next free slot using linear probing and insert the new record.  
  - Maintain a chain (using a link field or index) from the original hashed position to the new position, without moving the original record.
- **Search Faculty Record:**  
  - Compute the hash index using the same divide function.  
  - Traverse the chain starting from the primary index, following links to locate the faculty ID.  
- **Display Database:**  
  - Show each hash table slot with the stored faculty data and its chain link (if any), visualizing collision resolution.

### Key Concepts
- **Divide Hash Function:** Uses modulo operation for index calculation.  
- **Linear Probing with Chaining Without Replacement:** Linear probing finds free slots, while chaining connects collided records logically without relocating originals.  
- **Faculty Record Structure:** Typically includes ID, name, department, and possibly designation.

### Example Scenario
- Table size: 10  
- Insert IDs: 21, 31, 41 (all hash to 1 using `% 10`).  
- 21 stored at index 1; 31 and 41 placed in other free slots, linked from index 1 using chaining without replacement.  
- Search for 41 follows the chain from index 1 to its actual storage index.



## Code
```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

struct Faculty {
    int id;
    char name[50];
    char dept[50];
    Faculty *next;
};

class HashTable {
public:
    Faculty *table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
            occupied[i] = false;
        }
    }

    int hashFunction(int key) {
        return key / TABLE_SIZE;
    }

    void insertRecord(int id, const char n[], const char d[]) {
        int index = hashFunction(id);

        Faculty *node = new Faculty;
        node->id = id;
        strcpy(node->name, n);
        strcpy(node->dept, d);
        node->next = NULL;

        if (!occupied[index]) {
            table[index] = node;
            occupied[index] = true;
        } else {
            Faculty *temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = node;
        }

        cout << "Record inserted.\n";
    }

    void searchRecord(int id) {
        int index = hashFunction(id);

        Faculty *temp = table[index];
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Department: " << temp->dept << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Faculty not found.\n";
    }

    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            Faculty *temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->id << "," << temp->name << "," << temp->dept << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
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
<img width="334" height="545" alt="image" src="https://github.com/user-attachments/assets/3e58baf0-f6f6-4735-8d8b-5ac7efda119c" />

