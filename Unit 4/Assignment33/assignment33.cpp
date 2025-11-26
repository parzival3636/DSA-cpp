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