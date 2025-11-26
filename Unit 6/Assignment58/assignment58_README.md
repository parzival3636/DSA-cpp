# Assignment58

## 📘 Description
This program implements **assignment58** in C++.

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
