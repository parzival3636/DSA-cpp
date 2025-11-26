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
