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
