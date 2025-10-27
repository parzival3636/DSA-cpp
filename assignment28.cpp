#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct passenger {
    int ticketNumber;
    char name[100];
    char destination[100];
    char flightNumber[20];
    struct passenger* next;
} passenger;

passenger* createPassenger(int ticketNum, const char* name, const char* dest, const char* flight) {
    passenger* newPassenger = (passenger*)malloc(sizeof(passenger));
    if (!newPassenger) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newPassenger->ticketNumber = ticketNum;
    strncpy(newPassenger->name, name, 99);
    newPassenger->name[99] = '\0';
    strncpy(newPassenger->destination, dest, 99);
    newPassenger->destination[99] = '\0';
    strncpy(newPassenger->flightNumber, flight, 19);
    newPassenger->flightNumber[19] = '\0';
    newPassenger->next = nullptr;
    return newPassenger;
}

class TicketQueue {
private:
    passenger* front;
    passenger* rear;
    int passengerCount;
    int ticketCounter;

public:
    TicketQueue() {
        front = nullptr;
        rear = nullptr;
        passengerCount = 0;
        ticketCounter = 1001;
    }

    ~TicketQueue() {
        while (front) {
            passenger* temp = front;
            front = front->next;
            free(temp);
        }
    }

    void insertPassenger(const char* name, const char* dest, const char* flight) {
        passenger* newPassenger = createPassenger(ticketCounter++, name, dest, flight);
        
        if (!rear) {
            front = rear = newPassenger;
        } else {
            rear->next = newPassenger;
            rear = newPassenger;
        }
        passengerCount++;
        
        cout << "\nPassenger added to queue successfully!\n";
        cout << "Ticket Number: " << newPassenger->ticketNumber << "\n";
        cout << "Name: " << newPassenger->name << "\n";
        cout << "Destination: " << newPassenger->destination << "\n";
        cout << "Flight: " << newPassenger->flightNumber << "\n";
    }

    void displayFrontPassenger() {
        if (!front) {
            cout << "No passengers in the queue!\n";
            return;
        }
        
        cout << "\n====== Front Passenger Details ======\n";
        cout << "Ticket Number: " << front->ticketNumber << "\n";
        cout << "Name: " << front->name << "\n";
        cout << "Destination: " << front->destination << "\n";
        cout << "Flight: " << front->flightNumber << "\n";
    }

    void removeFrontPassenger() {
        if (!front) {
            cout << "No passengers to remove from queue!\n";
            return;
        }
        
        passenger* temp = front;
        cout << "\nRemoving passenger from queue:\n";
        cout << "Ticket Number: " << front->ticketNumber << "\n";
        cout << "Name: " << front->name << "\n";
        cout << "Destination: " << front->destination << "\n";
        cout << "Flight: " << front->flightNumber << "\n";
        
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        
        free(temp);
        passengerCount--;
        cout << "Passenger served successfully!\n";
    }

    void displayQueueStatus() {
        cout << "\n====== Ticket Queue Status ======\n";
        cout << "Passengers waiting: " << passengerCount << "\n";
        
        if (!front) {
            cout << "Queue is empty.\n";
            return;
        }
        
        cout << "\nPassengers in queue (in order):\n";
        passenger* temp = front;
        int position = 1;
        
        while (temp) {
            cout << position << ". " << temp->name << " (Ticket: " << temp->ticketNumber 
                 << ", Flight: " << temp->flightNumber << ")\n";
            temp = temp->next;
            position++;
        }
    }

    int getPassengerCount() {
        return passengerCount;
    }
};

int main() {
    TicketQueue queue;
    int choice;

    do {
        cout << "\n====== Ticket Agent Queue System ======\n";
        cout << "1) Insert New Passenger\n";
        cout << "2) Display Front Passenger\n";
        cout << "3) Remove Front Passenger\n";
        cout << "4) Display Queue Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char name[100], destination[100], flight[20];
                cout << "Enter passenger name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter destination: ";
                cin.getline(destination, 100);
                cout << "Enter flight number: ";
                cin.getline(flight, 20);
                
                queue.insertPassenger(name, destination, flight);
                break;
            }
            case 2:
                queue.displayFrontPassenger();
                break;
            case 3:
                queue.removeFrontPassenger();
                break;
            case 4:
                queue.displayQueueStatus();
                break;
            case 0:
                cout << "\nExiting Ticket Agent Queue System...\n";
                cout << "Number of passengers remaining in queue: " << queue.getPassengerCount() << "\n";
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}