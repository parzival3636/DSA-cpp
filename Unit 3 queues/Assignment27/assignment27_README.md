
# Assignment 27 - Pizza Parlour Order Management Using Circular Queue

## Managing Pizza Orders Using Circular Queue Data Structure

This program simulates a pizza parlour order management system that accepts a maximum of $$n$$ orders and serves them on a First-Come-First-Served (FCFS) basis. Once placed, orders cannot be cancelled. The circular queue data structure efficiently handles the fixed capacity order queue by reusing freed spaces after orders are served.

### Operations Implemented
- **Enqueue (Place Order):** Add a new order to the rear of the circular queue if the queue is not full.  
- **Dequeue (Serve Order):** Remove the oldest order from the front of the queue to simulate order serving.  
- **isFull:** Check if the order queue has reached its maximum capacity.  
- **isEmpty:** Check if there are no pending orders.  
- **Display Orders:** List all current pending orders in queue order.

### Key Concept: Circular Queue

A circular queue treats the array as circular, so when it reaches the end, it wraps around to use any free space at the beginning. This solves the problem of wasted space typical in linear queues after dequeue operations. Front and rear pointers are used to track the queue’s start and end, with careful checks to distinguish full and empty states.

### Time Complexity
- All enqueue, dequeue, and status checking operations run in $$O(1)$$ time, suitable for real-time order management.

### Example

Consider a pizza parlour with maximum 5 order capacity:

- Enqueue order #101 → Orders queue:   
- Enqueue order #102 → Orders queue:   
- Enqueue order #103 → Orders queue:   
- Dequeue (serve) → Served order: 101, Orders queue:   
- Enqueue order #104 → Orders queue:   
- Enqueue order #105 → Orders queue:   
- Enqueue order #106 → Orders queue:  (queue full now)  
- Attempt to enqueue order #107 → Reject - queue full message displayed  
- Dequeue (serve) → Served order: 102, Orders queue:   
- Enqueue order #107 → Orders queue:  (space freed by earlier dequeue)

This example demonstrates circular wrapping of indices and correct order management.


```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct order {
    int orderId;
    char customerName[100];
    char pizzaType[50];
    int quantity;
    float totalAmount;
} order;

class PizzaParlor {
private:
    order* orders;
    int front;
    int rear;
    int capacity;
    int size;
    int orderCounter;

public:
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        orders = (order*)malloc(capacity * sizeof(order));
        if (!orders) {
            cout << "Memory allocation failed!\n";
            exit(-1);
        }
        front = -1;
        rear = -1;
        size = 0;
        orderCounter = 1;
    }

    ~PizzaParlor() {
        free(orders);
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void placeOrder(const char* name, const char* type, int qty, float amount) {
        if (isFull()) {
            cout << "Cannot accept more orders! Pizza parlor is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        orders[rear].orderId = orderCounter++;
        strncpy(orders[rear].customerName, name, 99);
        orders[rear].customerName[99] = '\0';
        strncpy(orders[rear].pizzaType, type, 49);
        orders[rear].pizzaType[49] = '\0';
        orders[rear].quantity = qty;
        orders[rear].totalAmount = amount;
        size++;

        cout << "\nOrder placed successfully!\n";
        cout << "Order ID: " << orders[rear].orderId << "\n";
        cout << "Customer: " << orders[rear].customerName << "\n";
        cout << "Pizza Type: " << orders[rear].pizzaType << "\n";
        cout << "Quantity: " << orders[rear].quantity << "\n";
        cout << "Total Amount: $" << orders[rear].totalAmount << "\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve! Pizza parlor is empty.\n";
            return;
        }

        cout << "\nServing order:\n";
        cout << "Order ID: " << orders[front].orderId << "\n";
        cout << "Customer: " << orders[front].customerName << "\n";
        cout << "Pizza Type: " << orders[front].pizzaType << "\n";
        cout << "Quantity: " << orders[front].quantity << "\n";
        cout << "Total Amount: $" << orders[front].totalAmount << "\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    void displayCurrentOrder() {
        if (isEmpty()) {
            cout << "No current order to display.\n";
            return;
        }

        cout << "\nCurrent order being prepared:\n";
        cout << "Order ID: " << orders[front].orderId << "\n";
        cout << "Customer: " << orders[front].customerName << "\n";
        cout << "Pizza Type: " << orders[front].pizzaType << "\n";
        cout << "Quantity: " << orders[front].quantity << "\n";
        cout << "Total Amount: $" << orders[front].totalAmount << "\n";
    }

    void displayAllOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "\n====== All Pending Orders ======\n";
        int count = 1;
        int i = front;
        
        do {
            cout << count << ". Order ID: " << orders[i].orderId 
                 << " | Customer: " << orders[i].customerName 
                 << " | Pizza: " << orders[i].pizzaType 
                 << " | Qty: " << orders[i].quantity 
                 << " | Amount: $" << orders[i].totalAmount << "\n";
            
            i = (i + 1) % capacity;
            count++;
        } while (i != (rear + 1) % capacity);
        
        cout << "Total pending orders: " << size << "\n";
    }

    void displayParlorStatus() {
        cout << "\n====== Pizza Parlor Status ======\n";
        cout << "Maximum capacity: " << capacity << " orders\n";
        cout << "Current orders: " << size << "\n";
        cout << "Available slots: " << (capacity - size) << "\n";
        
        if (isFull()) {
            cout << "Status: FULL - Cannot accept new orders\n";
        } else if (isEmpty()) {
            cout << "Status: EMPTY - No orders\n";
        } else {
            cout << "Status: OPERATIONAL - " << size << " orders pending\n";
        }
    }
};

int main() {
    int maxOrders;
    cout << "Enter maximum number of orders pizza parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);
    int choice;

    do {
        cout << "\n====== Pizza Parlor Management System ======\n";
        cout << "1) Place New Order\n";
        cout << "2) Serve Next Order\n";
        cout << "3) Display Current Order\n";
        cout << "4) Display All Orders\n";
        cout << "5) Display Parlor Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (parlor.isFull()) {
                    cout << "Cannot accept new orders! Parlor is full.\n";
                    break;
                }
                
                char name[100], type[50];
                int quantity;
                float amount;
                
                cout << "Enter customer name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter pizza type: ";
                cin.getline(type, 50);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter total amount: $";
                cin >> amount;
                
                parlor.placeOrder(name, type, quantity, amount);
                break;
            }
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayCurrentOrder();
                break;
            case 4:
                parlor.displayAllOrders();
                break;
            case 5:
                parlor.displayParlorStatus();
                break;
            case 0:
                cout << "Thank you for using Pizza Parlor Management System!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
```
<img width="586" height="698" alt="image" src="https://github.com/user-attachments/assets/aba7e158-858c-4cc7-9ab1-d8ee89a75439" />
<img width="678" height="539" alt="image" src="https://github.com/user-attachments/assets/d8980d53-ec1e-4068-9a68-454812016db3" />

<img width="461" height="266" alt="image" src="https://github.com/user-attachments/assets/1ac42832-0b58-4804-9210-da2df21b1a33" />

### Applications
- Order management systems in eateries and fast-food chains.  
- Any finite capacity, real-time queue management scenario such as print job scheduling or task scheduling.  
- Demonstrates fundamental circular buffer usage and fixed-size queue memory optimization in programming.

***

