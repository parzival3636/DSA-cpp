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
