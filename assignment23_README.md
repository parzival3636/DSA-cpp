# Assignment 23 - Implementing Multiple Stacks Using a Single Array

## Multiple Stack Implementation Using an Array

This program implements multiple stacks (more than two) using a single fixed-size array. The goal is to dynamically share the array space among multiple stacks to optimize memory usage. The implementation supports standard stack operations and handles overflow and underflow conditions for each stack independently.

### Operations Implemented
- **Push:** Add an element to a specified stack if there is space available.  
- **Pop:** Remove and return the top element from a specified stack if it is not empty.  
- **Stack Overflow:** Detect and handle cases when a push operation is attempted on a full stack.  
- **Stack Underflow:** Detect and handle attempts to pop from an empty stack.  
- **Display:** Show all elements of each stack separately.

### Key Concept: Multiple Stacks in One Array

The array is divided logically to hold multiple stacks. Several approaches exist:

- Fixed Division: Each stack has a fixed section of the array. Simple but static and can waste space.  
- Flexible Division: Dynamically share unoccupied array spaces among stacks to improve memory utilization (complex to implement).

Each stack maintains its own top pointer to track the current top element. Checking overflow and underflow is done using array bounds and respective top pointers.

```cpp
#include <iostream>
using namespace std;

#define MAX 100

class MultiStack {
    int arr[MAX];
    int top[10];     // top of each stack
    int start[10];   // start index of each stack
    int end[10];     // end index of each stack
    int n;           // number of stacks
public:
    MultiStack(int stacks, int size) {
        n = stacks;
        int segment = size / stacks;
        for (int i = 0; i < stacks; i++) {
            start[i] = i * segment;
            end[i] = (i + 1) * segment - 1;
            top[i] = start[i] - 1;
        }
    }

    void push(int sn, int val) {
        if (top[sn] == end[sn])
            cout << "Stack " << sn + 1 << " Overflow\n";
        else {
            arr[++top[sn]] = val;
            cout << "Pushed " << val << " into Stack " << sn + 1 << endl;
        }
    }

    void pop(int sn) {
        if (top[sn] < start[sn])
            cout << "Stack " << sn + 1 << " Underflow\n";
        else
            cout << "Popped " << arr[top[sn]--] << " from Stack " << sn + 1 << endl;
    }

    void display(int sn) {
        if (top[sn] < start[sn])
            cout << "Stack " << sn + 1 << " is empty\n";
        else {
            cout << "Stack " << sn + 1 << ": ";
            for (int i = start[sn]; i <= top[sn]; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of stacks: ";
    cin >> n;

    int size;
    cout << "Enter total array size: ";
    cin >> size;

    MultiStack ms(n, size);

    int ch, sn, val;
    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter stack number (1-" << n << "): ";
                cin >> sn;
                cout << "Enter value: ";
                cin >> val;
                ms.push(sn - 1, val);
                break;
            case 2:
                cout << "Enter stack number (1-" << n << "): ";
                cin >> sn;
                ms.pop(sn - 1);
                break;
            case 3:
                cout << "Enter stack number (1-" << n << "): ";
                cin >> sn;
                ms.display(sn - 1);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 4);

    return 0;
}

```

### Time Complexity
- **Push and Pop:** $$O(1)$$ for each stack operation, given direct index manipulation without resizing.  
- **Display:** $$O(n_i)$$ per stack where $$n_i$$ is the number of elements in the ith stack.

### Applications
- Resource-limited environments requiring multiple stacks in shared memory.  
- Memory management in embedded systems.  
- Multi-threaded or parallel processing where separate stacks are needed within a shared memory space.

This method efficiently utilizes array space while providing classic stack functionality for multiple independent stacks.

***

