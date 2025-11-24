# Assignment 38 - Efficient Employee Record Search and Sorting Using Tree

## Searching and Sorting Employee Records Using Binary Search Tree (BST)

This program manages employee records using a binary search tree (BST) where each node stores employee details including a unique employee ID (`emp_id`). The BST is organized by `emp_id` to enable efficient search and sorting.

### Operations Implemented
- **Insert Employee Records:** Add employee nodes to the BST based on `emp_id`, maintaining sorted order with smaller `emp_id` in the left subtree and larger in the right.  
- **Search Employee:** Efficiently find an employee record using BST search properties by comparing `emp_id`.  
- **Sort Employees:** Display all employee records in ascending order of `emp_id` via inorder traversal of the BST.

### Key Concepts: BST for Efficient Lookup and Order

- BST maintains elements in sorted order enabling $$O(\log n)$$ average-time search, insertion, and traversal.  
- Inorder traversal visits nodes in ascending order based on `emp_id`, achieving sorting naturally without extra overhead.

### Time Complexity
- **Insertion and Search:** Average case $$O(\log n)$$, worst case $$O(n)$$ for skewed trees.  
- **Inorder Traversal (Sorting):** $$O(n)$$, where $$n$$ is the number of employees.

### Example

Suppose the following employee records are inserted:

| emp_id | Name        | Department  |
|--------|-------------|-------------|
| 105    | Alice       | Sales       |
| 102    | Bob         | Engineering |
| 110    | Charlie     | HR          |
| 104    | Diana       | Marketing   |

- Searching for `emp_id = 104` yields: Diana, Marketing  
- Inorder traversal outputs employees sorted by `emp_id`:  
  102 Bob, 104 Diana, 105 Alice, 110 Charlie


```cpp
#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int emp_id;
    string name;
    float salary;
    Employee *left, *right;
};

Employee* createNode(int id, string n, float s) {
    Employee* newNode = new Employee;
    newNode->emp_id = id;
    newNode->name = n;
    newNode->salary = s;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Employee* insert(Employee* root, int id, string name, float salary) {
    if (root == NULL)
        return createNode(id, name, salary);
    if (id < root->emp_id)
        root->left = insert(root->left, id, name, salary);
    else if (id > root->emp_id)
        root->right = insert(root->right, id, name, salary);
    else
        cout << "Duplicate Employee ID not allowed!\n";
    return root;
}

Employee* search(Employee* root, int id) {
    if (root == NULL || root->emp_id == id)
        return root;
    if (id < root->emp_id)
        return search(root->left, id);
    return search(root->right, id);
}

void inorder(Employee* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "Emp ID: " << root->emp_id 
             << " | Name: " << root->name 
             << " | Salary: " << root->salary << endl;
        inorder(root->right);
    }
}

int main() {
    Employee* root = NULL;
    int choice;
    do {
        cout << "\n--- Employee Record Menu ---";
        cout << "\n1. Insert Record";
        cout << "\n2. Search Record";
        cout << "\n3. Display All (Sorted by emp_id)";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float salary;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Salary: ";
            cin >> salary;
            root = insert(root, id, name, salary);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            Employee* emp = search(root, id);
            if (emp != NULL)
                cout << "Record Found -> ID: " << emp->emp_id 
                     << ", Name: " << emp->name 
                     << ", Salary: " << emp->salary << endl;
            else
                cout << "Record Not Found.\n";
        } 
        else if (choice == 3) {
            cout << "\nEmployee Records (Sorted by emp_id):\n";
            inorder(root);
        }
    } while (choice != 4);
    return 0;
}
```

### Applications
- Employee management systems for quick record retrieval and reporting.  
- Database indexing for sorted query results.  
- Any system requiring dynamic insertion and efficient search with sorted output.

