# Assignment 29 - Implementing Two Queues Using a Single Array

## Managing Multiple Queues in a Single Array

This program implements two independent queues using a single array. It supports enqueue (adding elements), dequeue (removing elements), and displaying elements of each queue separately. The goal is to utilize array space efficiently while managing multiple queues simultaneously.

### Operations Implemented
- **Add to Queue:** Insert an element into one of the two queues if space is available.  
- **Delete from Queue:** Remove the front element from a specified queue if it is not empty.  
- **Display Queue:** Show all elements currently present in either of the two queues.

### Key Concept: Two Queues Using Single Array

Two techniques are commonly used to manage two queues in one array:

- **Fixed Division:** Split the array into two fixed parts, each acting as an independent queue (simple but can waste space).  
- **Flexible Division:** One queue starts from the front, the other from the rear, growing towards each other, maximizing space utilization (more complex but efficient).

Each queue maintains its own front and rear indices, with careful checks to avoid overflow or underflow conditions.

### Time Complexity
- **Add and Delete:** $$O(1)$$ for both queues since operations access indices directly.  
- **Display:** $$O(n)$$ per queue, where $$n$$ is the number of elements in the queue.

### Example

Assuming an array of size 10, split as two fixed parts for simplicity:

- Enqueue 5 into Queue 1 → Queue 1:[1]
- Enqueue 7 into Queue 2 → Queue 2:[2]
- Enqueue 3 into Queue 1 → Queue 1:[3][1]
- Dequeue from Queue 1 → Removed 5, Queue 1:[3]
- Display Queue 2 → Output:[2]

This example shows basic enqueue, dequeue, and display operations on two queues within one array.



### Applications
- Resource-constrained systems requiring multiple queues in shared memory  
- Task scheduling for different priority levels or independent processes  
- Simulating multiplexed queue systems in computing and communication  


```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class MultipleQueues {
private:
    int* arr;
    int front1, rear1;
    int front2, rear2;
    int capacity;
    int size1, size2;

public:
    MultipleQueues(int cap) {
        capacity = cap;
        arr = (int*)malloc(capacity * sizeof(int));
        if (!arr) {
            cout << "Memory allocation failed!\n";
            exit(-1);
        }
        front1 = rear1 = -1;
        front2 = rear2 = -1;
        size1 = size2 = 0;
    }

    ~MultipleQueues() {
        free(arr);
    }

    bool isQueueFull(int queueNum) {
        if (queueNum == 1) {
            return size1 == capacity / 2;
        } else {
            return size2 == capacity / 2;
        }
    }

    bool isQueueEmpty(int queueNum) {
        if (queueNum == 1) {
            return size1 == 0;
        } else {
            return size2 == 0;
        }
    }

    void addToQueue(int queueNum, int value) {
        if (isQueueFull(queueNum)) {
            cout << "Queue " << queueNum << " is full! Cannot add element.\n";
            return;
        }

        if (queueNum == 1) {
            if (front1 == -1) {
                front1 = rear1 = 0;
            } else {
                rear1 = (rear1 + 1) % (capacity / 2);
            }
            arr[rear1] = value;
            size1++;
            cout << "Element " << value << " added to Queue 1\n";
        } else {
            if (front2 == -1) {
                front2 = rear2 = capacity / 2;
            } else {
                int nextPos = (rear2 - capacity / 2 + 1) % (capacity / 2) + capacity / 2;
                rear2 = nextPos;
            }
            arr[rear2] = value;
            size2++;
            cout << "Element " << value << " added to Queue 2\n";
        }
    }

    int deleteFromQueue(int queueNum) {
        if (isQueueEmpty(queueNum)) {
            cout << "Queue " << queueNum << " is empty! Cannot delete element.\n";
            return -1;
        }

        int deletedValue;
        if (queueNum == 1) {
            deletedValue = arr[front1];
            if (front1 == rear1) {
                front1 = rear1 = -1;
            } else {
                front1 = (front1 + 1) % (capacity / 2);
            }
            size1--;
            cout << "Element " << deletedValue << " deleted from Queue 1\n";
        } else {
            deletedValue = arr[front2];
            if (front2 == rear2) {
                front2 = rear2 = -1;
            } else {
                front2 = (front2 - capacity / 2 + 1) % (capacity / 2) + capacity / 2;
            }
            size2--;
            cout << "Element " << deletedValue << " deleted from Queue 2\n";
        }
        return deletedValue;
    }

    void displayQueue(int queueNum) {
        if (isQueueEmpty(queueNum)) {
            cout << "Queue " << queueNum << " is empty!\n";
            return;
        }

        cout << "Queue " << queueNum << " elements: ";
        if (queueNum == 1) {
            int i = front1;
            int count = 0;
            while (count < size1) {
                cout << arr[i] << " ";
                i = (i + 1) % (capacity / 2);
                count++;
            }
        } else {
            int i = front2;
            int count = 0;
            while (count < size2) {
                cout << arr[i] << " ";
                i = (i - capacity / 2 + 1) % (capacity / 2) + capacity / 2;
                count++;
            }
        }
        cout << "\n";
    }

    void displayQueueStatus() {
        cout << "\n====== Multiple Queues Status ======\n";
        cout << "Queue 1 - Size: " << size1 << "/" << capacity/2 
             << " | " << (isQueueEmpty(1) ? "Empty" : "Has elements") << "\n";
        cout << "Queue 2 - Size: " << size2 << "/" << capacity/2 
             << " | " << (isQueueEmpty(2) ? "Empty" : "Has elements") << "\n";
        cout << "Total capacity used: " << (size1 + size2) << "/" << capacity << "\n";
    }

    void displayBothQueues() {
        cout << "\n====== Both Queues Contents ======\n";
        displayQueue(1);
        displayQueue(2);
    }
};

int main() {
    int capacity;
    cout << "Enter total capacity for both queues: ";
    cin >> capacity;

    MultipleQueues mq(capacity);
    int choice;

    do {
        cout << "\n====== Multiple Queues Operations ======\n";
        cout << "1) Add to Queue 1\n";
        cout << "2) Add to Queue 2\n";
        cout << "3) Delete from Queue 1\n";
        cout << "4) Delete from Queue 2\n";
        cout << "5) Display Queue 1\n";
        cout << "6) Display Queue 2\n";
        cout << "7) Display Both Queues\n";
        cout << "8) Display Queue Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter element to add to Queue 1: ";
                cin >> value;
                mq.addToQueue(1, value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter element to add to Queue 2: ";
                cin >> value;
                mq.addToQueue(2, value);
                break;
            }
            case 3:
                mq.deleteFromQueue(1);
                break;
            case 4:
                mq.deleteFromQueue(2);
                break;
            case 5:
                mq.displayQueue(1);
                break;
            case 6:
                mq.displayQueue(2);
                break;
            case 7:
                mq.displayBothQueues();
                break;
            case 8:
                mq.displayQueueStatus();
                break;
            case 0:
                cout << "Exiting Multiple Queues System...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
```
