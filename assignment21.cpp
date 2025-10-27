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
