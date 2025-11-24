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

struct Node {
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = NULL;
    }
};

class HashTable {
public:
    Node* table[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int hashFunction(int roll) {
        return roll % TABLE_SIZE;
    }

    void insertRecord(Student s) {
        int index = hashFunction(s.roll);
        Node* newNode = new Node(s);

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
        cout << "Record inserted!\n";
    }

    void searchRecord(int roll) {
        int index = hashFunction(roll);

        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->data.roll == roll) {
                cout << "Record Found:\n";
                cout << "Roll: " << temp->data.roll << endl;
                cout << "Name: " << temp->data.name << endl;
                cout << "Marks: " << temp->data.marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record Not Found!\n";
    }

    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";

            Node* temp = table[i];
            while (temp != NULL) {
                cout << "[" << temp->data.roll << ", " 
                     << temp->data.name << ", " 
                     << temp->data.marks << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
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
