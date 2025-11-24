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
