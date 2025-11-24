#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

Node* createNode(int c, int p) {
    Node* newNode = new Node();
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

void insert(Node*& head, int c, int p) {
    Node* newNode = createNode(c, p);
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            insert(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    
    while (poly1) {
        insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    
    while (poly2) {
        insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    
    return result;
}

void display(Node* poly) {
    while (poly != NULL) {
        cout << poly->coeff;
        if (poly->pow > 0)
            cout << "x^" << poly->pow;
        if (poly->next != NULL)
            cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

void inputPoly(Node*& poly) {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
    
    for(int i = 0; i < terms; i++) {
        int coeff, pow;
        cout << "Enter coefficient for term " << i+1 << ": ";
        cin >> coeff;
        cout << "Enter power for term " << i+1 << ": ";
        cin >> pow;
        insert(poly, coeff, pow);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    cout << "Enter first polynomial:\n";
    inputPoly(poly1);

    cout << "\nEnter second polynomial:\n";
    inputPoly(poly2);

    cout << "\nFirst Polynomial: ";
    display(poly1);

    cout << "Second Polynomial: ";
    display(poly2);

    result = addPoly(poly1, poly2);
    cout << "Sum: ";
    display(result);

    while(poly1) {
        Node* temp = poly1;
        poly1 = poly1->next;
        delete temp;
    }
    while(poly2) {
        Node* temp = poly2;
        poly2 = poly2->next;
        delete temp;
    }
    while(result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}