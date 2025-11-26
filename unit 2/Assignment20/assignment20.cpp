#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (!head) { cout << "Empty List\n"; return; }
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
    if (!source || !source->next) {
        frontRef = source;
        backRef = NULL;
        return;
    }
    Node* slow = source;
    Node* fast = source->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
}

int main() {
    Node* head = NULL;
    Node* front = NULL;
    Node* back = NULL;
    int n, val;

    cout << "=== FrontBackSplit of Linked List ===\n";
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "List must contain at least one element.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "\nOriginal List: ";
    display(head);

    FrontBackSplit(head, front, back);

    cout << "\nFront Half: ";
    display(front);

    cout << "Back Half: ";
    display(back);

    return 0;
}
