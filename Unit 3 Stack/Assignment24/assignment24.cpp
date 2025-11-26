// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// bool isBalanced(string expr) {
//     stack<char> s;
//     for (char ch : expr) {
//         if (ch == '(' || ch == '{' || ch == '[')
//             s.push(ch);
//         else if (ch == ')' || ch == '}' || ch == ']') {
//             if (s.empty()) return false;
//             char top = s.top();
//             s.pop();
//             if ((ch == ')' && top != '(') ||
//                 (ch == '}' && top != '{') ||
//                 (ch == ']' && top != '['))
//                 return false;
//         }
//     }
//     return s.empty();
// }

// int main() {
//     string expr;
//     cout << "Enter a string of parentheses: ";
//     cin >> expr;

//     if (isBalanced(expr))
//         cout << "The string is Balanced.\n";
//     else
//         cout << "The string is Not Balanced.\n";

//     return 0;
// }




#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            
            char top = s.top();
            s.pop();
            
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    string input;
    cout << "Enter parentheses expression: ";
    cin >> input;
    
    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}
