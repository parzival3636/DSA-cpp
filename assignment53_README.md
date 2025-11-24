
# Assignment 53 - Hash Table Implementation with Collision Resolution Using Linked Lists (Separate Chaining)

## Implementing a Hash Table with Collision Handling via Linked Lists

This program demonstrates the implementation of a hash table that stores integer keys and resolves collisions using linked lists, a technique known as separate chaining. Each slot in the hash table array points to the head of a linked list that contains all keys hashing to that index.

### Operations Implemented
- **Insert:** Compute the hash index using a hash function. If the slot is empty, initialize it with a new linked list node containing the key. In case of a collision, append the new key to the end of the linked list at that slot.
- **Search:** Calculate the index from the hash function and traverse the linked list at the corresponding slot to find the key.
- **Delete:** Locate the key within the linked list at the hash index and remove it by adjusting pointers while maintaining linked list structure.

### Key Concepts: Hashing and Linked List Collision Resolution
- **Hash Function:** Usually a modulo operation that maps a key to a specific slot index in the hash table.
- **Separate Chaining:** Handles collisions by storing multiple keys in a linked list at a single hash index.
- **Dynamic Data Structure:** Linked lists grow dynamically to accommodate as many keys as needed at each slot.
- **Efficient Collision Handling:** Avoids clustering and long probe sequences typical of linear probing.

### Time Complexity
- **Average Case:** Approximately \(O(1 + \alpha)\) per operation, where \(\alpha\) is the load factor indicating average keys per linked list.
- **Worst Case:** \(O(n)\) when all keys hash to the same slot, creating a long linked list.

### Example Scenario
| Step               | Description                                        |
|--------------------|--------------------------------------------------|
| Hash table size    | 10                                               |
| Insert keys        | 10, 22, 31, 4, 15, 28                            |
| Key 10             | Hashes to index 0, inserted at head              |
| Key 22             | Hashes to index 2, inserted at head              |
| Key 31             | Hashes to index 1, inserted at head              |
| Key 4              | Hashes to index 4, inserted at head              |
| Key 15             | Hashes to index 5, inserted at head              |
| Key 28             | Hashes to index 8, inserted at head              |
| Search key 31      | Found in linked list at index 1                   |
| Delete key 15      | Removed from linked list at index 5               |

### Applications
- Widely used in database indexing and caching systems for efficient data retrieval.
- Fundamental in implementing symbol tables in language compilers and interpreters.
- Useful in real-time systems requiring average constant time operations.

```cpp
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

```
