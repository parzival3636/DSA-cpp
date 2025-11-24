# Assignment 17 - Addition of Two Polynomials Using Singly Linked List

## Polynomial Addition Using Singly Linked List

This program performs the addition of two polynomials represented using singly linked lists. Each node in the list holds the coefficient and exponent (power) of a term of the polynomial. The linked list structure allows dynamic representation of polynomials with any number of terms and supports efficient traversal and manipulation.

### Operations Implemented
- **Input Polynomial:** Accept polynomial terms (coefficient and power) from the user and insert them into a singly linked list.  
- **Display Polynomial:** Traverse and display the polynomial in traditional mathematical notation.  
- **Add Polynomials:** Traverse two polynomial lists simultaneously, adding coefficients of terms with the same power and merging terms into a resultant polynomial list.  
- **Memory Management:** Delete all dynamically allocated nodes at the end to prevent memory leaks.

### Key Concept: Singly Linked List for Polynomial Representation

A singly linked list stores polynomial terms as nodes where each node contains:
- `coeff` (coefficient of the term)  
- `pow` (exponent/power of the term)  
- `next` pointer to the next term node

The nodes are typically arranged in descending order of powers for correct polynomial representation. Polynomial addition involves traversing both lists simultaneously and adding coefficients of terms with equal powers, or directly appending terms when powers differ.

### Time Complexity
- **Insertion:** $$O(n)$$ to insert a new term at the end of the list (where $$n$$ is the number of terms so far).  
- **Addition:** $$O(m + n)$$ where $$m, n$$ are the number of terms in the two polynomials, since each list is traversed once.  
- **Display:** $$O(k)$$ where $$k$$ is the number of terms in the polynomial being displayed.

### Applications
- Mathematical operations on polynomials such as addition, subtraction, multiplication, and differentiation.  
- Computer algebra systems for symbolic expression handling.  
- Engineering and scientific computations involving polynomial models.  

This structured approach using singly linked lists facilitates operational flexibility for polynomial arithmetic and dynamic memory management while maintaining simple, readable code.

```cpp
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
```

<img width="526" height="477" alt="image" src="https://github.com/user-attachments/assets/e2b72c45-f8d1-4b34-a4cd-a2db88b302b3" />


