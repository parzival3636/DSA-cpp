#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct bstnode {
    int data;
    struct bstnode* left;
    struct bstnode* right;
} bstnode;

bstnode* createNode(int value) {
    bstnode* newNode = (bstnode*)malloc(sizeof(bstnode));
    if (!newNode) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bstnode* insertNode(bstnode* root, int value) {
    if (!root) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        cout << "Duplicate value " << value << " not allowed!\n";
    }
    
    return root;
}

bstnode* findMin(bstnode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

bstnode* deleteNode(bstnode* root, int value) {
    if (!root) {
        cout << "Value " << value << " not found in BST!\n";
        return root;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left) {
            bstnode* temp = root->right;
            free(root);
            cout << "Value " << value << " deleted successfully!\n";
            return temp;
        } else if (!root->right) {
            bstnode* temp = root->left;
            free(root);
            cout << "Value " << value << " deleted successfully!\n";
            return temp;
        }
        
        bstnode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        cout << "Value " << value << " deleted successfully!\n";
    }
    
    return root;
}

void levelwiseDisplay(bstnode* root) {
    if (!root) {
        cout << "BST is empty!\n";
        return;
    }
    
    queue<bstnode*> q;
    q.push(root);
    int level = 1;
    
    cout << "\n====== Level-wise BST Display ======\n";
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level " << level << ": ";
        
        for (int i = 0; i < levelSize; i++) {
            bstnode* current = q.front();
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
        level++;
    }
}

void inorderTraversal(bstnode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(bstnode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(bstnode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

bool searchNode(bstnode* root, int value) {
    if (!root) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

void displayBST(bstnode* root) {
    if (!root) {
        cout << "BST is empty!\n";
        return;
    }
    
    cout << "\n====== BST Traversals ======\n";
    cout << "Inorder (Sorted): ";
    inorderTraversal(root);
    cout << "\n";
    
    cout << "Preorder: ";
    preorderTraversal(root);
    cout << "\n";
    
    cout << "Postorder: ";
    postorderTraversal(root);
    cout << "\n";
}

void freeBST(bstnode* root) {
    if (root) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    bstnode* root = nullptr;
    int choice;
    
    do {
        cout << "\n====== Binary Search Tree Operations ======\n";
        cout << "1) Create/Insert Node\n";
        cout << "2) Delete Node\n";
        cout << "3) Search Node\n";
        cout << "4) Level-wise Display\n";
        cout << "5) Display All Traversals\n";
        cout << "6) Display BST Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Value " << value << " inserted successfully!\n";
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            }
            case 3: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value)) {
                    cout << "Value " << value << " found in BST!\n";
                } else {
                    cout << "Value " << value << " not found in BST!\n";
                }
                break;
            }
            case 4:
                levelwiseDisplay(root);
                break;
            case 5:
                displayBST(root);
                break;
            case 6: {
                cout << "\n====== BST Status ======\n";
                if (!root) {
                    cout << "BST is empty!\n";
                } else {
                    cout << "BST contains elements.\n";
                    cout << "Root value: " << root->data << "\n";
                    cout << "Inorder traversal (sorted): ";
                    inorderTraversal(root);
                    cout << "\n";
                }
                break;
            }
            case 0:
                cout << "Exiting BST Operations...\n";
                freeBST(root);
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}