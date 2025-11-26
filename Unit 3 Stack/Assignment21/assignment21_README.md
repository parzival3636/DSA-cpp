# Assignment 21 - Stock Price Tracker Using Stack Implemented by Linked List

## Stock Price Tracker Using Stack Data Structure

This program simulates a simple stock price tracker that records daily stock prices input by the user. The prices are stored in a stack implemented using a singly linked list. The stack structure allows efficient tracking of the most recent prices and supports viewing or removing them in Last-In-First-Out (LIFO) order.

### Operations Implemented
- **record(price):** Push a new stock price onto the top of the stack, adding it to the history.  
- **remove():** Pop and return the most recent price from the stack, effectively removing it from the tracked history.  
- **latest():** Peek at the top of the stack to retrieve the most recent price without removing it.  
- **isEmpty():** Check if the stack is empty, i.e., if no prices have been recorded.

### Key Concept: Stack Using Linked List

A stack follows Last-In-First-Out (LIFO) semantics, where elements are added and removed only from the top. Implementing a stack using a linked list leverages dynamic memory allocation without fixed size limits common in arrays. Each node holds the stock price and a pointer to the next node. The top of the stack points to the most recent price node, enabling constant time push, pop, and peek operations.

### Time Complexity
- **record (push):** $$O(1)$$ — new node inserted at the beginning of the linked list.  
- **remove (pop):** $$O(1)$$ — top node removed from the linked list.  
- **latest (peek):** $$O(1)$$ — top node's data accessed without modification.  
- **isEmpty:** $$O(1)$$ — checking if the top pointer is NULL.


```cpp
#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void record(int price) {
    Node* newNode = new Node();
    newNode->price = price;
    newNode->next = top;
    top = newNode;
    cout << "Recorded stock price: " << price << endl;
}

int removePrice() {
    if (isEmpty()) {
        cout << "No prices to remove.\n";
        return -1;
    }
    int removed = top->price;
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << "Removed latest price: " << removed << endl;
    return removed;
}

int latest() {
    if (isEmpty()) {
        cout << "No prices recorded.\n";
        return -1;
    }
    cout << "Latest stock price: " << top->price << endl;
    return top->price;
}

void display() {
    if (isEmpty()) {
        cout << "No stock prices recorded.\n";
        return;
    }
    cout << "\nAll Recorded Stock Prices (latest first):\n";
    Node* temp = top;
    while (temp) {
        cout << temp->price << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, price;
    while (true) {
        cout << "\n=== Stock Price Tracker ===\n";
        cout << "1. Record new price\n2. Remove latest price\n3. View latest price\n4. Check if empty\n5. Display all prices\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter price: ";
                cin >> price;
                record(price);
                break;
            case 2:
                removePrice();
                break;
            case 3:
                latest();
                break;
            case 4:
                if (isEmpty()) cout << "No prices recorded.\n";
                else cout << "Prices are available.\n";
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

```

### Applications
- Real-time price tracking where recent values are accessed or undone frequently.  
- Undo mechanisms in applications requiring state rollback.  
- Any Last-In-First-Out requirement with dynamically changing data size.

