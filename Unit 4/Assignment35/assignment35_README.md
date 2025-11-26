# Assignment 35- Recursive Operations on Binary Tree

## Implementing Recursive Traversals and Operations on Binary Tree

This program creates a binary tree and performs recursive operations including inorder traversal, preorder traversal, counting leaf nodes, and generating the mirror image of the tree. Recursion leverages the natural hierarchical structure of binary trees for elegant and straightforward implementations.

### Operations Implemented
- **Recursive Inorder Traversal:** Visit left subtree, node, then right subtree recursively, displaying the nodes in sorted order for BSTs.  
- **Recursive Preorder Traversal:** Visit node first, then left subtree, followed by right subtree recursively.  
- **Count Leaf Nodes:** Recursively count nodes that have no left or right child, indicating leaf nodes.  
- **Mirror Image:** Recursively swap left and right children of every node to produce the tree’s mirror image.

### Key Concepts: Recursion in Binary Trees

- Recursion fits naturally with tree traversal due to the repeated pattern of subtree processing.  
- Each operation decomposes the problem into smaller subproblems on subtrees until reaching base cases (null nodes).  
- Mirror image via recursion swaps children at every level elegantly and concisely.

### Time Complexity
- All recursive operations visit each node once, resulting in $$O(n)$$ time complexity for trees with $$n$$ nodes.

### Example

Consider the binary tree:

```
       1
      / \
     2   3
    / \    
   4   5
```

- **Inorder Traversal:** 4 2 5 1 3  
- **Preorder Traversal:** 1 2 4 5 3  
- **Number of Leaf Nodes:** 3 (nodes 4, 5, 3)  
- **Mirror Image:**

```
       1
      / \
     3   2
        / \
       5   4
```

### Applications
- Recursive tree traversals are commonly used for expression tree evaluation, syntax tree processing, and BST operations.  
- Counting leaves helps in assessing tree structure and balance.  
- Mirror image operations find use in graphical transformations and symmetry-based algorithms.



```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
    Node* root;

    Node* createNode() {
        int val;
        cout << "Enter data (-1 for no node): ";
        cin >> val;
        if (val == -1) return NULL;

        Node* newNode = new Node(val);
        cout << "Enter left child of " << val << ":\n";
        newNode->left = createNode();
        cout << "Enter right child of " << val << ":\n";
        newNode->right = createNode();
        return newNode;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    int countLeaf(Node* node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        return countLeaf(node->left) + countLeaf(node->right);
    }

    void mirror(Node* node) {
        if (node == NULL)
            return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }

public:
    BinaryTree() { root = NULL; }

    void createTree() {
        cout << "Create Binary Tree:\n";
        root = createNode();
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void showLeafCount() {
        cout << "Total Leaf Nodes: " << countLeaf(root) << endl;
    }

    void mirrorImage() {
        mirror(root);
        cout << "Mirror Image created.\n";
        cout << "Inorder of Mirror Tree: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice;

    while (true) {
        cout << "\n--- Binary Tree Recursive Operations ---\n";
        cout << "1. Create Tree\n2. Inorder Traversal\n3. Preorder Traversal\n4. Count Leaf Nodes\n5. Mirror Image\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: tree.createTree(); break;
            case 2: tree.displayInorder(); break;
            case 3: tree.displayPreorder(); break;
            case 4: tree.showLeafCount(); break;
            case 5: tree.mirrorImage(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

```
