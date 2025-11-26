# Assignment 20 - Splitting a Linked List into Front and Back Sublists

## Front-Back Split of a Linked List

This program splits a singly linked list into two sublists: one containing the front half of elements and the other containing the back half. When the list has an odd number of elements, the extra element is included in the front sublist. This operation is useful in many linked list algorithms, such as merge sort.

### Operations Implemented
- **FrontBackSplit:** Divide the original linked list into two sublists—a front list with the first half (plus one if odd length), and a back list with the remaining elements.  
- **Special Cases:** Correctly handle edge cases, such as lists with fewer than two elements, ensuring no errors or incorrect splits.  
- **Validation:** The solution is tested with different lengths (2, 3, 4, etc.) to ensure correctness near boundary conditions.

### Key Concept: Splitting Using Slow and Fast Pointers

The front-back split is efficiently implemented with two pointers:
- A slow pointer advances one node at a time.
- A fast pointer advances two nodes at a time.

When the fast pointer reaches the end, the slow pointer will be at the midpoint, allowing the list to be split into front and back halves. Handling odd-length lists requires assigning the extra node to the front list. The pointers ensure an $$O(n)$$ time complexity without extra space.

### Time Complexity
- The split operation traverses the list only once, leading to $$O(n)$$ time complexity, where $$n$$ is the number of nodes.

```cpp
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

```
<img width="441" height="219" alt="image" src="https://github.com/user-attachments/assets/94d1b1b1-d568-44f9-9996-c16dc21baea1" />


### Applications
- Preprocessing step in merge sort and other divide-and-conquer algorithms on linked lists.  
- Useful in algorithms requiring partitioning or balanced division of linear data structures.  
- Fundamental technique in advanced linked list manipulations.

