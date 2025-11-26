# Assignment 34 - Nonrecursive Operations on Binary Tree

## Implementing Nonrecursive Traversal and Operations on Binary Tree

This program creates a binary tree and performs several nonrecursive operations: inorder traversal, preorder traversal, counting leaf nodes, and generating the mirror image of the tree. Nonrecursive methods use stacks or queues to avoid recursion overhead and can be more suitable in certain system environments.

### Operations Implemented
- **Nonrecursive Inorder Traversal:** Uses a stack to traverse left subtree, visit node, then right subtree, simulating recursion iteratively.  
- **Nonrecursive Preorder Traversal:** Visits the node first, then left, then right subtrees while using a stack for iteration.  
- **Count Leaf Nodes:** Iteratively count nodes with no children using stack or queue traversal.  
- **Mirror Image:** Iteratively transform the tree by swapping left and right children of every node, using a queue or stack for levelwise processing.

### Key Concepts: Iterative Tree Traversals and Manipulation

- Iterative traversals utilize an explicit stack to replace the call stack used in recursion.  
- Mirror image generation replaces recursive swapping with a breadth-first or depth-first iterative approach, allowing nonrecursive tree modification.

### Time Complexity
- All traversals and transformations operate in $$O(n)$$, visiting each node exactly once, where $$n$$ is the number of nodes.

### Example

For the binary tree:

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
- Nonrecursive traversals avoid recursion-related stack overflow issues.  
- Useful in iterative algorithms and environments with limited stack size or real-time constraints.  
- Useful in advanced tree manipulations and graphical transformations.


```cpp
#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
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

void inorderNonRecursive(node* root) {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    
    stack<node*> s;
    node* current = root;
    
    cout << "Inorder: ";
    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }
        
        current = s.top();
        s.pop();
        cout << current->data << " ";
        
        current = current->right;
    }
    cout << "\n";
}

void preorderNonRecursive(node* root) {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    
    stack<node*> s;
    s.push(root);
    
    cout << "Preorder: ";
    while (!s.empty()) {
        node* current = s.top();
        s.pop();
        cout << current->data << " ";
        
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
    cout << "\n";
}

int countLeafNodes(node* root) {
    if (!root) {
        return 0;
    }
    
    stack<node*> s;
    s.push(root);
    int leafCount = 0;
    
    while (!s.empty()) {
        node* current = s.top();
        s.pop();
        
        if (!current->left && !current->right) {
            leafCount++;
        }
        
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
    
    return leafCount;
}

node* createMirror(node* root) {
    if (!root) {
        return nullptr;
    }
    
    stack<node*> s;
    s.push(root);
    
    while (!s.empty()) {
        node* current = s.top();
        s.pop();
        
        node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        
        if (current->left) {
            s.push(current->left);
        }
        if (current->right) {
            s.push(current->right);
        }
    }
    
    return root;
}

void displayTree(node* root) {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    
    queue<node*> q;
    q.push(root);
    
    cout << "Level order: ";
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    cout << "\n";
}

int main() {
    node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\n1. Insert node\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Preorder traversal\n";
        cout << "4. Count leaf nodes\n";
        cout << "5. Create mirror\n";
        cout << "6. Display tree\n";
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
                inorderNonRecursive(root);
                break;
                
            case 3:
                preorderNonRecursive(root);
                break;
                
            case 4:
                cout << "Leaf nodes: " << countLeafNodes(root) << "\n";
                break;
                
            case 5:
                root = createMirror(root);
                cout << "Mirror tree created!\n";
                break;
                
            case 6:
                displayTree(root);
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

<img width="299" height="795" alt="image" src="https://github.com/user-attachments/assets/6d3eb5fa-f995-4106-94ca-d50bd6dd5ef6" />
<img width="373" height="452" alt="image" src="https://github.com/user-attachments/assets/ed302689-02e5-4888-9ee0-bfde947e5dfc" />

