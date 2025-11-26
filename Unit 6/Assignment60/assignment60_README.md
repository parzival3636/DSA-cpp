# Assignment60

## 📘 Description
This program implements **assignment60** in C++.

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
