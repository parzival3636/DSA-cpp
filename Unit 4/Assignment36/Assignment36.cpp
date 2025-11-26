#include <iostream>
#include <string>
using namespace std;

struct Node_sak {
    string name_sak;
    int marks_sak;
    int roll_sak;
    Node_sak *left_sak, *right_sak;
};

Node_sak* createNode_sak(string name_sak, int marks_sak) {
    Node_sak* newNode_sak = new Node_sak;
    newNode_sak->name_sak = name_sak;
    newNode_sak->marks_sak = marks_sak;
    newNode_sak->roll_sak = 0;
    newNode_sak->left_sak = newNode_sak->right_sak = NULL;
    return newNode_sak;
}

Node_sak* insert_sak(Node_sak* root_sak, string name_sak, int marks_sak) {
    if (root_sak == NULL)
        return createNode_sak(name_sak, marks_sak);
    if (marks_sak < root_sak->marks_sak)
        root_sak->left_sak = insert_sak(root_sak->left_sak, name_sak, marks_sak);
    else
        root_sak->right_sak = insert_sak(root_sak->right_sak, name_sak, marks_sak);
    return root_sak;
}

void assignRoll_sak(Node_sak* root_sak, int &roll_sak) {
    if (root_sak == NULL)
        return;
    assignRoll_sak(root_sak->right_sak, roll_sak);
    root_sak->roll_sak = ++roll_sak;
    assignRoll_sak(root_sak->left_sak, roll_sak);
}

void display_sak(Node_sak* root_sak) {
    if (root_sak == NULL)
        return;
    display_sak(root_sak->left_sak);
    cout << "Roll No: " << root_sak->roll_sak
         << "  Name: " << root_sak->name_sak
         << "  Marks: " << root_sak->marks_sak << endl;
    display_sak(root_sak->right_sak);
}

int main() {
    Node_sak* root_sak = NULL;
    int n_sak, marks_sak;
    string name_sak;

    cout << "Enter number of students: ";
    cin >> n_sak;

    for (int i = 0; i < n_sak; i++) {
        cout << "Enter student name: ";
        cin >> name_sak;
        cout << "Enter marks: ";
        cin >> marks_sak;
        root_sak = insert_sak(root_sak, name_sak, marks_sak);
    }

    int roll_sak = 0;
    assignRoll_sak(root_sak, roll_sak);

    cout << "\nStudents with Assigned Roll Numbers (Topper = Roll No. 1):\n";
    display_sak(root_sak);

    return 0;
}