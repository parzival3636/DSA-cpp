#include <iostream>
#include <string>
using namespace std;

struct student_rrl {
    int roll_rrl;
    string name_rrl;
    string year_rrl;
    string div_rrl;
};

int main() {
    int n_rrl;
    cout << "Enter number of students: ";
    cin >> n_rrl;
    cin.ignore(); 

    student_rrl *arr = new student_rrl[n_rrl];

    cout << "Enter roll number, name, year, division for each student:\n";
    for (int i = 0; i < n_rrl; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> arr[i].roll_rrl;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, arr[i].name_rrl);
        cout << "Year (S.Y., T.Y., B.Tech.): ";
        getline(cin, arr[i].year_rrl);
        cout << "Division: ";
        getline(cin, arr[i].div_rrl);
    }

    int target_roll;
    cout << "\nEnter roll number you want to search: ";
    cin >> target_roll;

    bool found = false;
    for (int i = 0; i < n_rrl; i++) {
        if (arr[i].roll_rrl == target_roll) {
            cout << "\nStudent found!\n";
            cout << "Roll No: " << arr[i].roll_rrl << endl;
            cout << "Name: " << arr[i].name_rrl << endl;
            cout << "Year: " << arr[i].year_rrl << endl;
            cout << "Division: " << arr[i].div_rrl << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "\nStudent not found!";
    }

    delete[] arr;
    return 0;
}
