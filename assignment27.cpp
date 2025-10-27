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