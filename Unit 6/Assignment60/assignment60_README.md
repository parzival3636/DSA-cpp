# Assignment60

# Smart College Placement Portal Using Advanced Hashing Techniques

## Designing a Placement Portal with High-Performance Hash-Based Record Management

This project designs and implements a smart college placement portal that uses advanced hashing techniques to efficiently manage student placement records. Each record may contain fields like Student ID, Name, Branch, Company, Package, and Status. The focus is on achieving high performance with low collision probability, even as data grows dynamically.

### Operations Implemented
- **Dynamic Insertion of Placement Records:**  
  New placement records are inserted using robust hash functions (e.g., double hashing, universal hashing, or Mid-Square combined with secondary hashing) to reduce clustering and collisions.
- **Fast Search and Filtering:**  
  Allows rapid lookup of records by Student ID or other hashable keys. Hash indices enable near-constant-time retrieval of a student’s placement status or company details.
- **Efficient Updates and Deletions:**  
  Supports modification and removal of records while maintaining hash table structure, using lazy deletion markers or rehashing as needed.
- **Collision-Minimized Storage:**  
  Employs advanced techniques such as double hashing, rehashing on high load factor, or separate chaining with balanced lists to sustain performance as the number of records increases.

### Key Concepts: Advanced Hashing in Placement Portals
- **Advanced Hash Functions:** Reduce collision probability by distributing keys more uniformly across the table.
- **Load Factor Control & Rehashing:** Monitors the ratio of stored entries to table size and triggers rehashing into a larger table when the load becomes high.
- **Scalability:** The design supports continuous addition of new batches and companies without degrading query performance.

### Time Complexity
- **Average Case:** Still approximately \(O(1)\) for insertion, search, and deletion due to improved collision handling and rehashing strategies.
- **Worst Case:** \(O(n)\), but significantly less frequent due to advanced techniques and balanced load management.

### Example Scenario
| Feature                  | Description                                                      |
|--------------------------|------------------------------------------------------------------|
| Insert Placement Record  | Add


## code:
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    int id;
    char name[30];
    char company[30];
    bool occupied;

    Student() {
        id = -1;
        occupied = false;
        strcpy(name, "");
        strcpy(company, "");
    }
};

class HashTable {
    Student table[50];
    int size;

public:
    HashTable(int s) {
        size = s;
    }

    int hash(int key) {
        return key % size;
    }

    void insertRecord(int id, const char n[], const char comp[]) {
        int index = hash(id);
        int start = index;

        while (table[index].occupied) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Table Full\n";
                return;
            }
        }

        table[index].id = id;
        strcpy(table[index].name, n);
        strcpy(table[index].company, comp);
        table[index].occupied = true;

        cout << "Record Inserted\n";
    }

    void searchRecord(int id) {
        int index = hash(id);
        int start = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                cout << "Student Found:\n";
                cout << "Roll: " << table[index].id << "\n";
                cout << "Name: " << table[index].name << "\n";
                cout << "Company: " << table[index].company << "\n";
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "Student Not Found\n";
    }

    void display() {
        cout << "\n--- Placement Records ---\n";
        for (int i = 0; i < size; i++) {
            if (table[i].occupied) {
                cout << i << " => " << table[i].id << " | "
                     << table[i].name << " | "
                     << table[i].company << "\n";
            } else {
                cout << i << " => Empty\n";
            }
        }
    }
};

int main() {
    HashTable h(10);
    int choice, id;
    char name[30], comp[30];

    do {
        cout << "\n1. Insert Student\n2. Search Student\n3. Display Records\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID, Name, Company: ";
            cin >> id >> name >> comp;
            h.insertRecord(id, name, comp);
        }

        else if (choice == 2) {
            cout << "Enter ID to Search: ";
            cin >> id;
            h.searchRecord(id);
        }

        else if (choice == 3) {
            h.display();
        }

    } while (choice != 4);

    return 0;
}

```

## output:
<img width="355" height="458" alt="image" src="https://github.com/user-attachments/assets/eaf54772-4e92-4f49-98df-a0c59ec93581" />
<img width="281" height="265" alt="image" src="https://github.com/user-attachments/assets/ed2ae2e3-3cab-4477-93e8-6d2cd9d18f54" />
