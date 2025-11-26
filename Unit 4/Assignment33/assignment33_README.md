# Assignment 33 - Creating Binary Search Tree (BST) and Finding Minimum & Maximum

## Constructing BST and Finding Minimum and Maximum Elements

This program implements basic BST creation along with functions to find the minimum and maximum values stored in the BST. The BST property ensures that minimum is the leftmost node and maximum is the rightmost node in the tree.

### Operations Implemented
- **Create BST:** Insert nodes maintaining BST order (left subtree smaller, right subtree larger).  
- **Find Minimum:** Traverse the left children until the leftmost leaf node is reached, which contains the minimum value.  
- **Find Maximum:** Traverse the right children till the rightmost leaf node is found, containing the maximum value.

### Key Concept: BST Structure and Extremes

- The binary search tree organizes elements in a manner that facilitates efficient searching.  
- Minimum and maximum values correspond to the boundary nodes in the leftmost and rightmost branches respectively, allowing quick access without exhaustive search.

### Time Complexity
- Insertion, minimum, and maximum operations run in average $$O(\log n)$$, worst-case $$O(n)$$ time depending on tree balance, where $$n$$ is the number of nodes.

### Example

For the BST constructed with values in order: 50, 30, 70, 20, 40, 60, 80

- Minimum value → 20 (leftmost node)  
- Maximum value → 80 (rightmost node)

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

node* insertNode(node* root, int value) {
    if (!root) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

int findMinimum(node* root) {
    if (!root) {
        return -1;
    }
    
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

int findMaximum(node* root) {
    if (!root) {
        return -1;
    }
    
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

void displayInorder(node* root) {
    if (root) {
        displayInorder(root->left);
        cout << root->data << " ";
        displayInorder(root->right);
    }
}

int main() {
    node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\n1. Insert node\n";
        cout << "2. Find minimum\n";
        cout << "3. Find maximum\n";
        cout << "4. Display tree\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted!\n";
                break;
                
            case 2:
                if (root) {
                    cout << "Minimum value: " << findMinimum(root) << "\n";
                } else {
                    cout << "Tree is empty!\n";
                }
                break;
                
            case 3:
                if (root) {
                    cout << "Maximum value: " << findMaximum(root) << "\n";
                } else {
                    cout << "Tree is empty!\n";
                }
                break;
                
            case 4:
                if (root) {
                    cout << "Tree elements: ";
                    displayInorder(root);
                    cout << "\n";
                } else {
                    cout << "Tree is empty!\n";
                }
                break;
                
            case 0:
                cout << "Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    
    return 0;
}
```
<img width="269" height="766" alt="image" src="https://github.com/user-attachments/assets/86871e17-c7ba-4f3e-9a23-979fa5e3fa66" />

### Applications
- Finding range boundaries in sorted data effectively.  
- Support operations in databases and indexing structures.  
- Core functionality in binary search and ordered data management.

