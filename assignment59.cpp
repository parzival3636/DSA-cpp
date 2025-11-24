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
