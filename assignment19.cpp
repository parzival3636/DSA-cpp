#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float percentage;
};

struct Node {
    Student data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* createNode(Student s) {
    Node* newNode = new Node();
    newNode->data = s;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Student s) {
    Node* newNode = createNode(s);
    if (!head) head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(Student s) {
    Node* newNode = createNode(s);
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(Student s, int pos) {
    if (pos <= 1) { insertAtBeginning(s); return; }
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) { insertAtEnd(s); return; }
    Node* newNode = createNode(s);
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete temp;
}

void deleteAtEnd() {
    if (!head) return;
    Node* temp = head;
    if (!temp->next) { head = NULL; delete temp; return; }
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

void deleteAtPosition(int pos) {
    if (!head) return;
    if (pos == 1) { deleteAtBeginning(); return; }
    Node* temp = head;
    for (int i = 1; temp && i < pos; i++) temp = temp->next;
    if (!temp) return;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    delete temp;
}

void display() {
    Node* temp = head;
    cout << "\nStudent Records:\n";
    while (temp) {
        cout << "Roll No: " << temp->data.roll_no
             << " | Name: " << temp->data.name
             << " | Percentage: " << temp->data.percentage << "%\n";
        temp = temp->next;
    }
}

int main() {
    int choice, pos;
    Student s;
    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Display\n8.Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 8) break;
        switch (choice) {
            case 1:
                cout << "Enter Roll No, Name, Percentage: ";
                cin >> s.roll_no >> s.name >> s.percentage;
                insertAtBeginning(s);
                break;
            case 2:
                cout << "Enter Roll No, Name, Percentage: ";
                cin >> s.roll_no >> s.name >> s.percentage;
                insertAtEnd(s);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter Roll No, Name, Percentage: ";
                cin >> s.roll_no >> s.name >> s.percentage;
                insertAtPosition(s, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}



































// #include <iostream>
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

// void insertAtBeginning(dnode* &head, int data) {
//     dnode* newnode = createDNode(data);
    
//     if (!head) {
//         head = newnode;
//     } else {
//         newnode->next = head;
//         head->prev = newnode;
//         head = newnode;
//     }
//     cout << "Inserted " << data << " at beginning\n";
// }

// void insertAtEnd(dnode* &head, int data) {
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
//     cout << "Inserted " << data << " at end\n";
// }

// void insertAfterNode(dnode* &head, int afterData, int data) {
//     if (!head) {
//         cout << "List is empty!\n";
//         return;
//     }
    
//     dnode* temp = head;
//     while (temp && temp->data != afterData) {
//         temp = temp->next;
//     }
    
//     if (!temp) {
//         cout << "Node with value " << afterData << " not found!\n";
//         return;
//     }
    
//     dnode* newnode = createDNode(data);
//     newnode->next = temp->next;
//     newnode->prev = temp;
    
//     if (temp->next) {
//         temp->next->prev = newnode;
//     }
//     temp->next = newnode;
    
//     cout << "Inserted " << data << " after " << afterData << "\n";
// }

// void deleteFromBeginning(dnode* &head) {
//     if (!head) {
//         cout << "List is empty!\n";
//         return;
//     }
    
//     dnode* temp = head;
//     head = head->next;
//     if (head) head->prev = nullptr;
//     cout << "Deleted " << temp->data << " from beginning\n";
//     free(temp);
// }

// void deleteFromEnd(dnode* &head) {
//     if (!head) {
//         cout << "List is empty!\n";
//         return;
//     }
    
//     dnode* temp = head;
//     while (temp->next) {
//         temp = temp->next;
//     }
    
//     if (temp->prev) {
//         temp->prev->next = nullptr;
//     } else {
//         head = nullptr;
//     }
    
//     cout << "Deleted " << temp->data << " from end\n";
//     free(temp);
// }

// void deleteNode(dnode* &head, int data) {
//     if (!head) {
//         cout << "List is empty!\n";
//         return;
//     }
    
//     dnode* temp = head;
//     while (temp && temp->data != data) {
//         temp = temp->next;
//     }
    
//     if (!temp) {
//         cout << "Node with value " << data << " not found!\n";
//         return;
//     }
    
//     if (temp->prev) {
//         temp->prev->next = temp->next;
//     } else {
//         head = temp->next;
//     }
    
//     if (temp->next) {
//         temp->next->prev = temp->prev;
//     }
    
//     cout << "Deleted node with value " << data << "\n";
//     free(temp);
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
//         cout << "\n====== Doubly Linked List Operations ======\n";
//         cout << "1) Insert at beginning\n";
//         cout << "2) Insert at end\n";
//         cout << "3) Insert after node\n";
//         cout << "4) Delete from beginning\n";
//         cout << "5) Delete from end\n";
//         cout << "6) Delete specific node\n";
//         cout << "7) Display list\n";
//         cout << "0) Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
        
//         switch (choice) {
//             case 1: {
//                 int data;
//                 cout << "Enter data to insert: ";
//                 cin >> data;
//                 insertAtBeginning(head, data);
//                 break;
//             }
//             case 2: {
//                 int data;
//                 cout << "Enter data to insert: ";
//                 cin >> data;
//                 insertAtEnd(head, data);
//                 break;
//             }
//             case 3: {
//                 int afterData, data;
//                 cout << "Enter node value to insert after: ";
//                 cin >> afterData;
//                 cout << "Enter data to insert: ";
//                 cin >> data;
//                 insertAfterNode(head, afterData, data);
//                 break;
//             }
//             case 4:
//                 deleteFromBeginning(head);
//                 break;
//             case 5:
//                 deleteFromEnd(head);
//                 break;
//             case 6: {
//                 int data;
//                 cout << "Enter node value to delete: ";
//                 cin >> data;
//                 deleteNode(head, data);
//                 break;
//             }
//             case 7:
//                 displayDLL(head);
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