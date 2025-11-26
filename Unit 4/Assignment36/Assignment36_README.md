# Assignment 36 - Assigning Student Roll Numbers Using Binary Search Tree

## Using Trees to Assign Roll Numbers Based on Previous Year Results

This program uses a binary search tree (BST) to assign roll numbers to students in order of their academic performance from the previous year. The student with the highest marks is assigned roll number 1, the next highest roll number 2, and so forth.

### Operations Implemented
- **Create BST:** Insert student nodes with their marks as keys and associated student information as node data, maintaining BST properties.  
- **Inorder Traversal:** Traverse the BST in descending order (right-root-left) of marks to assign roll numbers starting from 1 to the top scorer.  
- **Assign Roll Numbers:** During traversal, assign roll numbers sequentially based on descending rank.

### Key Concepts: BST for Ranking and Sequential Assignment

- Using marks as keys ensures the highest marks are located in the rightmost nodes.  
- Inorder traversal modified to right-root-left order visits students from highest to lowest marks efficiently.  
- The rank (roll number) is assigned dynamically during traversal for an accurate sorted ordering.

### Time Complexity
- **Insertion:** Average $$O(\log n)$$, worst $$O(n)$$ based on tree balance.  
- **Traversal & Roll Assignment:** $$O(n)$$, visiting each student once.

### Example

Given student marks:  
- Alice: 85  
- Bob: 92  
- Charlie: 78  
- Diana: 95  
- Evan: 88

BST insertion organizes nodes by marks. The descending order traversal yields roll numbers:

1. Diana (95) — Roll No. 1  
2. Bob (92) — Roll No. 2  
3. Evan (88) — Roll No. 3  
4. Alice (85) — Roll No. 4  
5. Charlie (78) — Roll No. 5  

### Applications
- Automating rank and roll number assignment in educational institutions.  
- Efficient ranking in contests or sports using tree-based data structures.  
- Teaching sorted data processing and order statistics in computer science curricula.



```cpp
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
```
## Output:
<img width="567" height="263" alt="image" src="https://github.com/user-attachments/assets/0ccb426f-73c3-44e0-89ac-6b524e4e18b9" />

