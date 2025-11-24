#include <iostream>
#include <queue>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};


class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // ---------- INSERT ----------
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // ---------- FIND MIN ----------
    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    // ---------- DELETE NODE ----------
    Node* deleteNode(Node* root, int key) {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // ---------- INORDER TRAVERSAL ----------
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void inorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    // ---------- PREORDER TRAVERSAL ----------
    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void preorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    // ---------- POSTORDER TRAVERSAL ----------
    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void postorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    // ---------- LEVEL ORDER TRAVERSAL ----------
    void levelOrder(Node* root) {
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    void levelOrder() {
        cout << "Level Order: ";
        levelOrder(root);
        cout << endl;
    }

    // ---------- HEIGHT ----------
    int height(Node* root) {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int height() {
        return height(root);
    }

    // ---------- DEPTH ----------
    int depth(Node* root, int key, int level = 0) {
        if (root == NULL)
            return -1;
        if (root->data == key)
            return level;
        int left = depth(root->left, key, level + 1);
        if (left != -1) return left;
        return depth(root->right, key, level + 1);
    }

    int depth(int key) {
        return depth(root, key);
    }

    // ---------- DISPLAY TREE (Sideways) ----------
    void display(Node* root, int space = 0, int gap = 5) {
        if (root == NULL) return;

        space += gap;
        display(root->right, space);
        cout << endl;
        for (int i = gap; i < space; i++)
            cout << " ";
        cout << root->data << "\n";
        display(root->left, space);
    }

    void display() {
        cout << "\nTree structure:\n";
        display(root);
    }
};

// ==========================
// MAIN FUNCTION
// ==========================
int main() {
    BST tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.display();

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelOrder();

    cout << "\nHeight of tree: " << tree.height() << endl;
    cout << "Depth of node 40: " << tree.depth(40) << endl;

    cout << "\nDeleting node 30..." << endl;
    tree.deleteValue(30);
    tree.display();
    tree.inorder();

    return 0;
}
