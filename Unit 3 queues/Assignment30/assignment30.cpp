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