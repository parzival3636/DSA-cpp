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
