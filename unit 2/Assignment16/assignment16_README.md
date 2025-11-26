

# Assignment 16 - Generalized Linked List (GLL) for Set Implementation

## Generalized Linked List Representation of a Set

This program implements a **Set** data structure using a **Generalized Linked List (GLL)** to represent nested set elements in a hierarchical and flexible manner. The GLL supports storing atomic elements as well as sublists (nested sets), allowing the representation of complex nested structures similar to mathematical sets.

### Operations Implemented
- **Insertion of Elements:** Insert atomic elements or nested subsets into the GLL at appropriate positions.  
- **Display Set:** Traverse the GLL recursively to display all elements and nested subsets using proper set notation with curly braces `{}`.  
- **Empty Set Handling:** Correctly represent empty subsets within the generalized list structure.  
- **Recursive Traversal:** Support recursive traversal for nested elements at any depth within the set.

### Key Concept: Generalized Linked List (GLL)

A Generalized Linked List extends a normal singly linked list by allowing each node to represent either:
- An atomic element (a single data item), or  
- A pointer to another GLL, representing a nested subset.

This dual nature is achieved using a flag or indicator in each node to identify whether it is an atom or a sublist pointer. This structure enables efficient storage and traversal of hierarchical nested sets.

### Time Complexity
- **Insertion:** Inserting an element or sublist at a specified position generally requires traversal of the list to that position, costing $$O(n)$$ time where $$n$$ is the number of nodes at that level. For deeply nested lists, recursive insertions add to the traversal cost.  
- **Display (Traversal):** Displaying the entire set involves recursively visiting all nodes. The time complexity is $$O(N)$$, where $$N$$ is the total number of atomic elements and sublists in the entire nested structure.  
- **Deletion (if implemented):** Similar to insertion, deletion involves locating the target node, generally $$O(n)$$ at that level, plus recursive deletions for nested sublists.

```cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct node {
    int flag;
    char data[100]; 
    struct node *down;
    struct node *next;
} node;

node* getNode(int flag, const char* data = nullptr) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newnode->flag = flag;
    if (flag == 0 && data) {
        strncpy(newnode->data, data, 99);
        newnode->data[99] = '\0';
    } else {
        newnode->data[0] = '\0';
    }
    newnode->down = nullptr;
    newnode->next = nullptr;
    return newnode;
}

void insertData(node* &head, const char* value) {
    node* newnode = getNode(0, value);
    if (!head) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
    cout << "Inserted element: " << value << endl;
}

void insertSublist(node* &head) {
    cout << "Creating sublist...\n";
    node* sublist = nullptr;
    int n;
    cout << "Enter number of elements in sublist: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char val[100];
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertData(sublist, val);
    }

    node* newnode = getNode(1);
    newnode->down = sublist;

    if (!head)
        head = newnode;
    else {
        node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
    cout << "Sublist inserted successfully!\n";
}

void display(node* head) {
    cout << "{ ";
    node* temp = head;
    while (temp) {
        if (temp->flag == 0)
            cout << temp->data;
        else
            display(temp->down);

        if (temp->next)
            cout << ", ";
        temp = temp->next;
    }
    cout << " }";
}

bool search(node* head, const char* target) {
    node* temp = head;
    while (temp) {
        if (temp->flag == 0 && strcmp(temp->data, target) == 0)
            return true;
        else if (temp->flag == 1 && search(temp->down, target))
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteGLL(node* &head) {
    while (head) {
        if (head->flag == 1)
            deleteGLL(head->down);
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = nullptr;
    int choice;

    do {
        cout << "\n====== Generalized Linked List Operations ======\n";
        cout << "1) Insert Element (Atom)\n";
        cout << "2) Insert Sublist\n";
        cout << "3) Display Set\n";
        cout << "4) Search Element\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char val[100];
                cout << "Enter element to insert: ";
                cin >> val;
                insertData(head, val);
                break;
            }
            case 2:
                insertSublist(head);
                break;
            case 3:
                cout << "\nGLL Representation:\n";
                display(head);
                cout << "\n";
                break;
            case 4: {
                char target[100];
                cout << "Enter element to search: ";
                cin >> target;
                if (search(head, target))
                    cout << target << " found in GLL.\n";
                else
                    cout << target << " not found.\n";
                break;
            }
            case 0:
                cout << "Exiting program...\n";
                deleteGLL(head);
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}


```


<img width="564" height="470" alt="image" src="https://github.com/user-attachments/assets/2cbad0ef-9a09-4385-b734-d1e67dd2cab5" />

<img width="542" height="829" alt="image" src="https://github.com/user-attachments/assets/7f7e0ec9-3654-4951-ae90-92b0b3fedb77" />





### Applications
- Mathematical set representation with nested subsets.  
- Symbolic computation systems and parsing nested expressions.  
- Data modeling requiring hierarchical and recursive data storage.  

