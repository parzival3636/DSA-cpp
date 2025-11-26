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
