# Assignment 30 - Customer Call Queue Management Using Linked List in Call Center

## Managing Incoming Customer Calls Using Linked List Queue

This program simulates a call center queue system where customer calls are managed in a First-Come-First-Served (FCFS) manner. Calls arrive and are enqueued dynamically and handled by customer service agents who dequeue calls to assist customers. The queue uses a linked list to provide flexible, dynamic memory management and efficient operations.

### Operations Implemented
- **Enqueue Call:** Insert a new customer call at the rear of the linked list queue as calls arrive.  
- **Dequeue Call:** Remove the front call from the queue when an agent becomes available to assist the customer.  
- **Wait When Empty:** The system remains idle or waits if no calls are pending for service.  
- **Display Queue:** Optionally show all calls waiting to be served.

### Key Concept: Linked List Queue for Dynamic Real-Time Management

A singly linked list queue structure is ideal for handling dynamic and unpredictable call volumes that cannot be predetermined. Each node stores a customer call and a pointer to the next node. Enqueue and dequeue operations run in constant time by maintaining pointers to the front and rear of the queue.

### Time Complexity
- Both enqueue and dequeue operations operate in $$O(1)$$ time thanks to linked list pointers.  
- Displaying calls runs in $$O(n)$$, where $$n$$ is the number of waiting calls.

### Example

Sample operations:

- Call from Customer A arrives → Enqueue → Queue: [A]  
- Call from Customer B arrives → Enqueue → Queue: [A, B]  
- Agent assists → Dequeue → Served A, Queue: [B]  
- Call from Customer C arrives → Enqueue → Queue: [B, C]  
- Agent assists → Dequeue → Served B, Queue: [C]  
- Agent assists → Dequeue → Served C, Queue: [] (empty, system waits)


```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct call {
    int callId;
    char customerName[100];
    char phoneNumber[15];
    char issue[200];
    int priority;
    struct call* next;
} call;

call* createCall(int id, const char* name, const char* phone, const char* issueDesc, int pri) {
    call* newCall = (call*)malloc(sizeof(call));
    if (!newCall) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newCall->callId = id;
    strncpy(newCall->customerName, name, 99);
    newCall->customerName[99] = '\0';
    strncpy(newCall->phoneNumber, phone, 14);
    newCall->phoneNumber[14] = '\0';
    strncpy(newCall->issue, issueDesc, 199);
    newCall->issue[199] = '\0';
    newCall->priority = pri;
    newCall->next = nullptr;
    return newCall;
}

class CallCenter {
private:
    call* front;
    call* rear;
    int callCounter;
    int totalCallsHandled;

public:
    CallCenter() {
        front = nullptr;
        rear = nullptr;
        callCounter = 1001;
        totalCallsHandled = 0;
    }

    ~CallCenter() {
        while (front) {
            call* temp = front;
            front = front->next;
            free(temp);
        }
    }

    void enqueueCall(const char* name, const char* phone, const char* issue, int priority) {
        call* newCall = createCall(callCounter++, name, phone, issue, priority);
        
        if (!rear) {
            front = rear = newCall;
        } else {
            rear->next = newCall;
            rear = newCall;
        }
        
        cout << "\n====== New Call Received ======\n";
        cout << "Call ID: " << newCall->callId << "\n";
        cout << "Customer: " << newCall->customerName << "\n";
        cout << "Phone: " << newCall->phoneNumber << "\n";
        cout << "Issue: " << newCall->issue << "\n";
        cout << "Priority: " << newCall->priority << "\n";
        cout << "Call added to queue successfully!\n";
    }

    void dequeueCall() {
        if (!front) {
            cout << "No calls in queue! System waiting for new calls...\n";
            return;
        }
        
        call* temp = front;
        cout << "\n====== Connecting Call to Agent ======\n";
        cout << "Call ID: " << front->callId << "\n";
        cout << "Customer: " << front->customerName << "\n";
        cout << "Phone: " << front->phoneNumber << "\n";
        cout << "Issue: " << front->issue << "\n";
        cout << "Priority: " << front->priority << "\n";
        
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        
        free(temp);
        totalCallsHandled++;
        cout << "Call connected to agent successfully!\n";
    }

    void displayCurrentCall() {
        if (!front) {
            cout << "No calls currently waiting.\n";
            return;
        }
        
        cout << "\n====== Next Call in Queue ======\n";
        cout << "Call ID: " << front->callId << "\n";
        cout << "Customer: " << front->customerName << "\n";
        cout << "Phone: " << front->phoneNumber << "\n";
        cout << "Issue: " << front->issue << "\n";
        cout << "Priority: " << front->priority << "\n";
    }

    void displayAllCalls() {
        if (!front) {
            cout << "No calls in the queue.\n";
            return;
        }
        
        cout << "\n====== All Calls in Queue ======\n";
        call* temp = front;
        int position = 1;
        
        while (temp) {
            cout << position << ". Call ID: " << temp->callId 
                 << " | Customer: " << temp->customerName 
                 << " | Phone: " << temp->phoneNumber 
                 << " | Priority: " << temp->priority << "\n";
            temp = temp->next;
            position++;
        }
        cout << "Total calls waiting: " << position - 1 << "\n";
    }

    void displayCallCenterStatus() {
        cout << "\n====== Call Center Status ======\n";
        int waitingCalls = 0;
        call* temp = front;
        
        while (temp) {
            waitingCalls++;
            temp = temp->next;
        }
        
        cout << "Calls waiting: " << waitingCalls << "\n";
        cout << "Total calls handled today: " << totalCallsHandled << "\n";
        cout << "Next Call ID: " << callCounter << "\n";
        
        if (waitingCalls == 0) {
            cout << "Status: IDLE - No calls waiting\n";
        } else if (waitingCalls < 5) {
            cout << "Status: NORMAL - " << waitingCalls << " calls waiting\n";
        } else if (waitingCalls < 10) {
            cout << "Status: BUSY - " << waitingCalls << " calls waiting\n";
        } else {
            cout << "Status: OVERLOADED - " << waitingCalls << " calls waiting\n";
        }
    }

    bool hasCalls() {
        return front != nullptr;
    }

    int getWaitingCallsCount() {
        int count = 0;
        call* temp = front;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    CallCenter center;
    int choice;

    do {
        cout << "\n====== Call Center Management System ======\n";
        cout << "1) Receive New Call\n";
        cout << "2) Connect Call to Agent\n";
        cout << "3) View Next Call\n";
        cout << "4) Display All Calls\n";
        cout << "5) Display Center Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char name[100], phone[15], issue[200];
                int priority;
                
                cout << "Enter customer name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter phone number: ";
                cin.getline(phone, 15);
                cout << "Enter issue description: ";
                cin.getline(issue, 200);
                cout << "Enter priority (1-5, 1=Highest): ";
                cin >> priority;
                
                if (priority < 1 || priority > 5) {
                    cout << "Invalid priority! Using default priority 3.\n";
                    priority = 3;
                }
                
                center.enqueueCall(name, phone, issue, priority);
                break;
            }
            case 2:
                center.dequeueCall();
                if (!center.hasCalls()) {
                    cout << "All calls handled. System waiting for new calls...\n";
                }
                break;
            case 3:
                center.displayCurrentCall();
                break;
            case 4:
                center.displayAllCalls();
                break;
            case 5:
                center.displayCallCenterStatus();
                break;
            case 0:
                cout << "\n====== System Shutdown ======\n";
                cout << "Calls remaining in queue: " << center.getWaitingCallsCount() << "\n";
                cout << "Thank you for using Call Center System!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
```
<img width="471" height="688" alt="image" src="https://github.com/user-attachments/assets/aea058bb-4ef6-429f-bba8-6f677238a5fb" />
<img width="457" height="550" alt="image" src="https://github.com/user-attachments/assets/a1e5d3a6-c8d1-4a56-8643-03aef64806be" />
<img width="462" height="557" alt="image" src="https://github.com/user-attachments/assets/b9e8275f-500e-4f62-b176-a431dfe37cdd" />
<img width="375" height="212" alt="image" src="https://github.com/user-attachments/assets/9d79b836-9ff7-40d2-9b99-6c1f5458ff2f" />


### Applications
- Call center customer management ensuring fair call servicing.  
- Real-time queue management in customer support systems or help desks.  
- Education on practical linked list applications for dynamic queue handling.

This linked list approach assures efficient, scalable, and orderly call queue management suitable for busy call centers.
