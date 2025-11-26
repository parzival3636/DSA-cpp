#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

class Student {
public:
    int roll;
    char name[50];
    float marks;

    Student() {
        roll = -1;
        strcpy(name, "");
        marks = 0;
    }
};

class HashTableLP {
public:
    Student table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    HashTableLP() {
        for (int i = 0; i < TABLE_SIZE; i++)
            occupied[i] = false;
    }

    int hashFunction(int roll) {
        return roll % TABLE_SIZE;
    }

    void insertRecord(Student s) {
        int index = hashFunction(s.roll);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (!occupied[tryIndex]) {
                table[tryIndex] = s;
                occupied[tryIndex] = true;
                cout << "Record inserted!\n";
                return;
            }
        }
        cout << "Hash table full!\n";
    }

    void searchRecord(int roll) {
        int index = hashFunction(roll);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int tryIndex = (index + i) % TABLE_SIZE;

            if (occupied[tryIndex] && table[tryIndex].roll == roll) {
                cout << "Record Found:\n";
                cout << "Roll: " << table[tryIndex].roll << endl;
                cout << "Name: " << table[tryIndex].name << endl;
                cout << "Marks: " << table[tryIndex].marks << endl;
                return;
            }
        }
        cout << "Record Not Found!\n";
    }

    void displayTable() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            if (occupied[i])
                cout << table[i].roll << " | " << table[i].name 
                     << " | " << table[i].marks;
            cout << endl;
        }
    }
};

int main() {
    HashTableLP ht;
    int choice;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter Roll: ";
            cin >> s.roll;
            cout << "Enter Name: ";
            cin >> s.name;
            cout << "Enter Marks: ";
            cin >> s.marks;
            ht.insertRecord(s);
        }
        else if (choice == 2) {
            int r;
            cout << "Enter Roll to Search: ";
            cin >> r;
            ht.searchRecord(r);
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
