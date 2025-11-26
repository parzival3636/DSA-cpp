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
