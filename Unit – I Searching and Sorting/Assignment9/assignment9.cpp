#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int roll;       // assigned after sorting
    string name;
    int marks;
};

// Print current order as: Name(marks) ...
void printOrder(Student arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << "(" << arr[i].marks << ")";
        if (i != n-1) cout << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // consume newline

    Student *cls = new (nothrow) Student[n];
    if (!cls) {
        cout << "Memory allocation failed!\n";
        return 1;
    }

    // Input names and marks
    cout << "\nEnter name and marks for each student:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << " Name: ";
        getline(cin, cls[i].name);
        cout << "Student " << i + 1 << " Marks: ";
        cin >> cls[i].marks;
        cin.ignore(); // consume newline before next getline
        cls[i].roll = 0; // init
    }

    cout << "\nOriginal order (Name(Marks)):\n";
    printOrder(cls, n);

    // Bubble Sort (descending order by marks) with pass-by-pass analysis
    cout << "\n--- Bubble Sort (assign topper roll 1) ---\n";
    int totalSwaps = 0;
    int passesUsed = 0;

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        cout << "\nPass " << pass + 1 << ":\n";

        for (int j = 0; j < n - 1 - pass; ++j) {
            // For descending order: if left < right, swap
            if (cls[j].marks < cls[j + 1].marks) {
                ++totalSwaps;
                swapped = true;
                cout << "  Swap " << totalSwaps << ": swapping "
                     << cls[j].name << "(" << cls[j].marks << ") and "
                     << cls[j + 1].name << "(" << cls[j + 1].marks << ") -> ";

                // swap whole student structs
                Student temp = cls[j];
                cls[j] = cls[j + 1];
                cls[j + 1] = temp;

                printOrder(cls, n);
            }
        }

        ++passesUsed;
        if (!swapped) {
            cout << "  No swaps in this pass — array is already sorted.\n";
            break; // optimization: array sorted early
        } else {
            cout << "  After pass " << pass + 1 << ": ";
            printOrder(cls, n);
        }
    }

    // Assign roll numbers: topper (highest marks) gets roll 1
    for (int i = 0; i < n; ++i) {
        cls[i].roll = i + 1;
    }

    // Final output
    cout << "\n--- Final Roll Assignment (Topper = Roll 1) ---\n";
    cout << left << setw(6) << "Roll" << setw(25) << "Name" << "Marks\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << left << setw(6) << cls[i].roll
             << setw(25) << cls[i].name
             << cls[i].marks << '\n';
    }

    cout << "\nTotal passes used: " << passesUsed << endl;
    cout << "Total swaps made: " << totalSwaps << endl;

    delete[] cls;
    return 0;
}
