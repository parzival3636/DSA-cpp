# Assignment 51 - Hash Table Implementation with Collision Resolution Using Linear Probing

## Implementing a Hash Table with Linear Probing for Collision Handling

This program demonstrates how to implement a hash table data structure to store integer keys and resolve collisions using linear probing, where collisions are handled by sequentially probing the next slot until an empty slot is found.

### Operations Implemented
- **Insert:** Add a new key into the hash table. If the calculated hash index is occupied, move linearly to the next available index.  
- **Search:** Look for a key by checking its hash index and, if collision occurred, continue linearly probing until the key is found or an empty slot is reached (indicating absence).  
- **Delete:** Remove a key by marking the slot as deleted without breaking the probing chain (often using a special marker).

### Key Concepts: Hashing and Linear Probing

- **Hash Function:** Often a modulo operation on the key to find the initial slot index.  
- **Linear Probing:** Resolves collisions by checking subsequent slots sequentially, wrapping around at the array boundary (circular).  
- **Load Factor & Clustering:** Performance degrades with higher load factors due to primary clustering in linear probing.

### Time Complexity
- Average $$O(1)$$ for insert, search, and delete under low load factor conditions.  
- Worst case $$O(n)$$ if many collisions cause long probe sequences.

### Example Scenario

- Hash table size: 10  
- Insert keys: 10, 20, 30, 40  
  - 10 hashes to index 0 → inserted at 0  
  - 20 hashes to index 0 → collision, inserted at 1  
  - 30 hashes to index 0 → collision, inserted at 2  
  - 40 hashes to index 0 → collision, inserted at 3  
- Search 30 → found at index 2  
- Delete 20 → slot at index 1 marked deleted  
- Insert 50 → hashes to index 0 → probes index 1 (deleted), inserted at 1

```cpp
#include <iostream>
using namespace std;

class HashTable {
public:
    int size;
    int table[20];

    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (table[idx] != -1) {
            idx = (idx + 1) % size;
            if (idx == start) {
                cout << "Hash Table Full\n";
                return;
            }
        }
        table[idx] = key;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++)
            cout << i << " -> " << table[i] << endl;
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
<img width="226" height="294" alt="image" src="https://github.com/user-attachments/assets/71aa73b9-9470-4fb5-86fe-d491696c7254" />

### Applications
- Fast data retrieval in databases, caches, and symbol tables.  
- Real-time search systems requiring average constant time complexity.  
- Key-value storage in programming language runtimes and interpreters.

