# Assignment 37 - Operations on Binary Search Tree Holding Numeric Keys

## Illustrating Insert, Delete, Find, and Show Operations on BST

This program implements a Binary Search Tree (BST) with numeric keys and supports the following interactive operations through a menu-driven interface:
- **Insert:** Add a new key to the BST, preserving BST properties.  
- **Delete:** Remove a key from the BST, properly handling leaf nodes, nodes with one child, and nodes with two children.  
- **Find:** Search for a given key in the BST and report if found or not.  
- **Show:** Display the BST visually using inorder traversal to provide sorted output.

### Key Concepts

- **Insert:** Place nodes such that left children are smaller and right children are larger than the current node.  
- **Delete:** Replace nodes with appropriate successor/predecessor if necessary to maintain BST structure.  
- **Find:** Traverse following BST search logic to locate keys efficiently.  
- **Inorder Show:** Displays nodes in sorted order, aiding verification.

### Time Complexity
- Insert, Delete, Find operations run in average $$O(\log n)$$, worst case $$O(n)$$ depending on tree balance.  
- Show operation traverses entire tree in $$O(n)$$ time.

### Example Interactive Session

- Insert 50  
- Insert 30  
- Insert 70  
- Find 30 → Found  
- Show → Displays: 30 50 70  
- Delete 30  
- Find 30 → Not found  
- Show → Displays: 50 70

### Applications
- Dynamic sorted data storage and retrieval in databases and indexing systems.  
- Foundation for advanced data structures like balanced trees and sets.  
- Practical use in search engines, file systems, and compiler implementations.


```cpp
#include <iostream>
using namespace std;

struct Node_sak {
    int data_sak;
    Node_sak *left_sak, *right_sak;
};

Node_sak* createNode_sak(int value_sak) {
    Node_sak* newNode_sak = new Node_sak;
    newNode_sak->data_sak = value_sak;
    newNode_sak->left_sak = newNode_sak->right_sak = NULL;
    return newNode_sak;
}

Node_sak* insertNode_sak(Node_sak* root_sak, int value_sak) {
    if (root_sak == NULL)
        return createNode_sak(value_sak);
    if (value_sak < root_sak->data_sak)
        root_sak->left_sak = insertNode_sak(root_sak->left_sak, value_sak);
    else if (value_sak > root_sak->data_sak)
        root_sak->right_sak = insertNode_sak(root_sak->right_sak, value_sak);
    return root_sak;
}

Node_sak* findMin_sak(Node_sak* root_sak) {
    while (root_sak && root_sak->left_sak != NULL)
        root_sak = root_sak->left_sak;
    return root_sak;
}

Node_sak* deleteNode_sak(Node_sak* root_sak, int key_sak) {
    if (root_sak == NULL)
        return root_sak;

    if (key_sak < root_sak->data_sak)
        root_sak->left_sak = deleteNode_sak(root_sak->left_sak, key_sak);
    else if (key_sak > root_sak->data_sak)
        root_sak->right_sak = deleteNode_sak(root_sak->right_sak, key_sak);
    else {
        if (root_sak->left_sak == NULL) {
            Node_sak* temp_sak = root_sak->right_sak;
            delete root_sak;
            return temp_sak;
        } else if (root_sak->right_sak == NULL) {
            Node_sak* temp_sak = root_sak->left_sak;
            delete root_sak;
            return temp_sak;
        }
        Node_sak* temp_sak = findMin_sak(root_sak->right_sak);
        root_sak->data_sak = temp_sak->data_sak;
        root_sak->right_sak = deleteNode_sak(root_sak->right_sak, temp_sak->data_sak);
    }
    return root_sak;
}

bool findNode_sak(Node_sak* root_sak, int key_sak) {
    if (root_sak == NULL)
        return false;
    if (root_sak->data_sak == key_sak)
        return true;
    else if (key_sak < root_sak->data_sak)
        return findNode_sak(root_sak->left_sak, key_sak);
    else
        return findNode_sak(root_sak->right_sak, key_sak);
}

void inorder_sak(Node_sak* root_sak) {
    if (root_sak == NULL)
        return;
    inorder_sak(root_sak->left_sak);
    cout << root_sak->data_sak << " ";
    inorder_sak(root_sak->right_sak);
}

int main() {
    Node_sak* root_sak = NULL;
    int choice_sak, value_sak;

    while (true) {
        cout << "\n--- BST Operations ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Find";
        cout << "\n4. Show (Inorder Traversal)";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice_sak;

        switch (choice_sak) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value_sak;
                root_sak = insertNode_sak(root_sak, value_sak);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value_sak;
                root_sak = deleteNode_sak(root_sak, value_sak);
                break;

            case 3:
                cout << "Enter value to find: ";
                cin >> value_sak;
                if (findNode_sak(root_sak, value_sak))
                    cout << "Value found in BST.";
                else
                    cout << "Value not found.";
                break;

            case 4:
                cout << "BST Inorder Traversal: ";
                inorder_sak(root_sak);
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice.";
        }
    }
}
```
