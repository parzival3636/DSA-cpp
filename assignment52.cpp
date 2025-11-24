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
