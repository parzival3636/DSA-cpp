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
