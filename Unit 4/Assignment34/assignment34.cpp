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