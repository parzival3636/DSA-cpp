
# Assignment 52 - Hash Table Implementation with Collision Resolution Using Separate Chaining

## Implementing a Hash Table with Separate Chaining for Collision Handling

This program demonstrates how to implement a hash table data structure to store integer keys and resolve collisions using separate chaining, where each index of the hash table array points to a linked list that stores all keys hashing to that slot.

### Operations Implemented
- **Insert:** Add a new key into the hash table. If the calculated hash index is empty, the key is inserted as the first node. If the index already contains nodes (collision), the key is appended at the end of the linked list.
- **Search:** Look for a key by computing its hash index and traversing the linked list at that index to find the key if it exists.
- **Delete:** Remove a key by locating it in the linked list at the appropriate hash index and deleting the corresponding node while maintaining the integrity of the linked list.

### Key Concepts: Hashing and Separate Chaining
- **Hash Function:** A modulo operation often determines the array index corresponding to a key.
- **Separate Chaining:** Each slot of the hash array stores pointers to linked lists, accumulating all keys mapping to that index, allowing multiple keys per slot.
- **Dynamic Size:** The linked lists can dynamically grow, reducing the likelihood of overflow in any part of the hash table.
- **Collision Handling:** Separates keys colliding at the same index without overwriting or probing.

### Time Complexity
- **Average Case:** \(O(1 + \alpha)\), where \(\alpha\) is the load factor (average linked list length), typically close to constant time insertion, search, and deletion under uniform hashing.
- **Worst Case:** \(O(n)\) if many keys hash to the same slot resulting in long chains.

### Example Scenario
| Operation | Description                                       |
|-----------|-------------------------------------------------|
| Hash table size | 10                                        |
| Insert keys | 10, 22, 31, 4, 15, 28                         |
| - 10 hashes to index 0 | Inserted as the first node             |
| - 22 hashes to index 2 | Inserted as the first node             |
| - 31 hashes to index 1 | Inserted as the first node             |
| - 4 hashes to index 4  | Inserted as the first node             |
| - 15 hashes to index 5 | Inserted as the first node             |
| - 28 hashes to index 8 | Inserted as the first node             |
| Search for 31 | Found in the linked list at index 1           |
| Delete 15 | Node removed from the linked list at index 5     |

### Applications
- Fast data retrieval in databases, caches, and symbol tables.
- Widely used in programming language runtimes and interpreters for key-value storage.
- Real-time search systems requiring average constant time complexity.


```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
public:
    int size;
    Node* table[20];

    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int idx = hashFunc(key);

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        if (table[idx] == NULL) {
            table[idx] = newNode;
        } else {
            Node* temp = table[idx];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        cout << "Hash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter hash table size: ";
    cin >> n;

    HashTable h(n);

    int keys;
    cout << "Enter number of keys: ";
    cin >> keys;

    cout << "Enter keys:\n";
    for (int i = 0; i < keys; i++) {
        int k;
        cin >> k;
        h.insertKey(k);
    }

    h.display();
    return 0;
}

```

<img width="330" height="281" alt="image" src="https://github.com/user-attachments/assets/7333c116-6697-424c-bb85-16d8b7b0a2b5" />

