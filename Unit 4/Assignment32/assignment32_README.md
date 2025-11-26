# Assignment 32 - Advanced Binary Search Tree (BST) Operations

## Performing Advanced BST Operations: Count Nodes, Height, and Mirror Image

This program extends the functionality of a Binary Search Tree (BST) with operations to:
- Count the total number of nodes,
- Compute the tree’s height,
- Generate the mirror image of the BST.

### Operations Implemented
- **Count Nodes:** Recursively traverse the BST to count all nodes.  
- **Compute Height:** Recursively determine the maximum depth from root to leaf to find tree height.  
- **Mirror Image:** Create a mirror BST by swapping left and right children of all nodes recursively.

### Key Concepts

- **Node Count:** The sum of nodes in the left and right subtrees plus the current node.  
- **Height:** Defined as the longest path from the root node down to the farthest leaf node.  
- **Mirror Image:** The tree where each node’s left and right children are swapped, transforming the tree into its symmetrical form along the root.

### Time Complexity
- All three operations perform a full traversal of the BST, with time complexity $$O(n)$$, where $$n$$ is the number of nodes.

### Example

Consider the BST:

```
       50
      /  \
    30    70
   /  \  /  \
 20  40 60  80
```

- **Count Nodes:** 7  
- **Height:** 3 (levels)  
- **Mirror Image:** 

```
       50
      /  \
    70    30
   /  \  /  \
 80  60 40  20
```


```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    int countNodes(Node* node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) {
        if (node == NULL)
            return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh, rh);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    Node* mirror(Node* node) {
        if (node == NULL)
            return NULL;
        Node* temp = node->left;
        node->left = mirror(node->right);
        node->right = mirror(temp);
        return node;
    }

public:
    BST() { root = NULL; }

    void insertNode(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void countTotalNodes() {
        cout << "Total number of nodes: " << countNodes(root) << endl;
    }

    void computeHeight() {
        cout << "Height of BST: " << height(root) << endl;
    }

    void mirrorImage() {
        mirror(root);
        cout << "Mirror Image created.\n";
        displayInorder();
    }
};

int main() {
    BST bst;
    int ch, val;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert Node\n2. Display Inorder\n3. Count Nodes\n4. Compute Height\n5. Mirror Image\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insertNode(val);
                break;
            case 2:
                bst.displayInorder();
                break;
            case 3:
                bst.countTotalNodes();
                break;
            case 4:
                bst.computeHeight();
                break;
            case 5:
                bst.mirrorImage();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

```

### Output
<img width="364" height="755" alt="image" src="https://github.com/user-attachments/assets/95311703-99f0-489f-9517-5fe4e7a706a0" />

<img width="433" height="465" alt="image" src="https://github.com/user-attachments/assets/8064c919-428b-4a66-9bec-9c9f4534c66c" />

### Applications
- Counting and height calculation aid in assessing tree balance and performance.  
- Mirror image is used in graphical transformations and symmetry operations.  
- Such advanced BST operations are important in tree manipulations within database indexing and binary tree algorithms.

