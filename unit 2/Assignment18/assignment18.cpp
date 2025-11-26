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















//#include <iostream>
// #include <cstdlib>
// using namespace std;

// typedef struct dnode {
//     int data;
//     struct dnode* prev;
//     struct dnode* next;
// } dnode;

// dnode* createDNode(int data) {
//     dnode* newnode = (dnode*)malloc(sizeof(dnode));
//     if (!newnode) {
//         cout << "Memory allocation failed!\n";
//         exit(-1);
//     }
//     newnode->data = data;
//     newnode->prev = nullptr;
//     newnode->next = nullptr;
//     return newnode;
// }

// void bubbleSortDLL(dnode* &head) {
//     if (!head || !head->next) return;
    
//     int swapped;
//     dnode* ptr;
//     dnode* lptr = nullptr;
    
//     do {
//         swapped = 0;
//         ptr = head;
        
//         while (ptr->next != lptr) {
//             if (ptr->data > ptr->next->data) {
//                 int temp = ptr->data;
//                 ptr->data = ptr->next->data;
//                 ptr->next->data = temp;
//                 swapped = 1;
//             }
//             ptr = ptr->next;
//         }
//         lptr = ptr;
//     } while (swapped);
// }

// void insertDLL(dnode* &head, int data) {
//     dnode* newnode = createDNode(data);
    
//     if (!head) {
//         head = newnode;
//     } else {
//         dnode* temp = head;
//         while (temp->next) {
//             temp = temp->next;
//         }
//         temp->next = newnode;
//         newnode->prev = temp;
//     }
// }

// void displayDLL(dnode* head) {
//     if (!head) {
//         cout << "List is empty!\n";
//         return;
//     }
    
//     dnode* temp = head;
//     cout << "NULL <-> ";
//     while (temp) {
//         cout << temp->data << " <-> ";
//         temp = temp->next;
//     }
//     cout << "NULL\n";
// }

// void deleteDLL(dnode* &head) {
//     while (head) {
//         dnode* temp = head;
//         head = head->next;
//         free(temp);
//     }
// }

// int main() {
//     dnode* head = nullptr;
//     int choice;
    
//     do {
//         cout << "\n====== Doubly Linked List Bubble Sort ======\n";
//         cout << "1) Insert element\n";
//         cout << "2) Display list\n";
//         cout << "3) Bubble Sort\n";
//         cout << "0) Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
        
//         switch (choice) {
//             case 1: {
//                 int data;
//                 cout << "Enter element to insert: ";
//                 cin >> data;
//                 insertDLL(head, data);
//                 cout << "Element inserted successfully!\n";
//                 break;
//             }
//             case 2:
//                 cout << "Doubly Linked List: ";
//                 displayDLL(head);
//                 break;
//             case 3:
//                 bubbleSortDLL(head);
//                 cout << "List sorted using Bubble Sort!\n";
//                 break;
//             case 0:
//                 cout << "Exiting program...\n";
//                 deleteDLL(head);
//                 break;
//             default:
//                 cout << "Invalid choice! Try again.\n";
//         }
//     } while (choice != 0);
    
//     return 0;
// }