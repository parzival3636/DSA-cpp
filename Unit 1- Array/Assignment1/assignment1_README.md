# String Operations in C++

##**Aim:**
Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single dimensional arrays without using built-in string library functions

## 📘 Description
This program performs basic **string operations** in C++ without using the built-in string library.  
It supports the following operations:

1. **Calculate Length** – Find the length of a string.  
2. **Copy String** – Copy one string to another.  
3. **Reverse String** – Reverse the characters of a string.  
4. **Concatenate Strings** – Join two strings into one.  
5. **Exit** – Exit the program.

The program uses **character arrays** and implements all operations using loops.

---

## ⚙️ How to Compile and Run

**Program**.

```cpp

#include <iostream>
using namespace std;


int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 
}

void stringReverse(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void stringConcat(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int i = 0;
    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i];
        i++;
    }
    str1[len1 + i] = '\0'; 
}

int main() {
    char str1[100], str2[50], strCopy[100];
    int choice;

    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Calculate Length\n";
        cout << "2. Copy String\n";
        cout << "3. Reverse String\n";
        cout << "4. Concatenate Strings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                cout << "Length of the string: " << stringLength(str1) << endl;
                break;

            case 2:
                cout << "Enter a string to copy: ";
                cin.getline(str1, 100);
                stringCopy(str1, strCopy);
                cout << "Copied string: " << strCopy << endl;
                break;

            case 3:
                cout << "Enter a string to reverse: ";
                cin.getline(str1, 100);
                stringReverse(str1);
                cout << "Reversed string: " << str1 << endl;
                break;

            case 4:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 50);
                stringConcat(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
```










---

Output:


<img width="600" height="882" alt="image" src="https://github.com/user-attachments/assets/482cf0b6-46c1-40bd-9370-2158afc34697" />



