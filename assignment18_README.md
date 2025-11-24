# Assignment 18 - Implement Bubble Sort Using Doubly Linked List

## Bubble Sort on Doubly Linked List

This program implements the bubble sort algorithm on a doubly linked list. The doubly linked list holds integer elements that can be dynamically inserted. The bubble sort repeatedly traverses the list, compares adjacent node values, and swaps their data if they are out of order until the entire list is sorted.

### Operations Implemented
- **Insertion at End:** Add new elements at the end of the doubly linked list.  
- **Bubble Sort:** Repeatedly traverse and swap adjacent elements if unordered, using the doubly linked list's bidirectional traversal capabilities.  
- **Display:** Print the doubly linked list elements in order.

### Key Concept: Doubly Linked List

A doubly linked list has nodes with three fields: data, pointer to the previous node, and pointer to the next node. This structure allows traversal in both directions, which can improve the efficiency of some operations compared to singly linked lists. Bubble sort here uses the data-swap approach rather than rearranging node pointers for simplicity.

### Time Complexity
- **Insertion:** $$O(n)$$ to insert at the end due to list traversal.  
- **Bubble Sort:** $$O(n^2)$$ worst and average case, where $$n$$ is the number of nodes, because each pair of elements is compared multiple times.  
- **Display:** $$O(n)$$ to print all elements.


```cpp
#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to perform Bubble Sort on Doubly Linked List
void bubbleSort(Node* head) {
    if (head == NULL)
        return;

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL; // marks the last sorted node

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // last node is now sorted
    } while (swapped);
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "=== Bubble Sort using Doubly Linked List ===\n";
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "\nList before sorting:\n";
    display(head);

    bubbleSort(head);

    cout << "\nList after sorting:\n";
    display(head);

    return 0;
}
```

### Applications
- Sorting linked lists where random access is not available.  
- Educational purposes to understand sorting algorithms on linked structures.  

***


