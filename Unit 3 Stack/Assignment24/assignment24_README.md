# Assignment 24 - Balanced Parentheses Checker Using Stack

## Checking Balanced Parentheses in a String

This program checks whether a given string containing only parentheses characters—`(`, `)`, `{`, `}`, `[`, `]`—is balanced. Balanced parentheses mean every opening bracket has a matching closing bracket of the same type, and the brackets are properly nested and closed in correct order.

### Operations Implemented
- **Push Opening Brackets:** When encountering an opening bracket, push it onto a stack.  
- **Match Closing Brackets:** When encountering a closing bracket, check the top of the stack. If it matches the corresponding opening bracket, pop it; otherwise, the string is unbalanced.  
- **Final Stack Check:** After processing the entire string, if the stack is empty, parentheses are balanced; otherwise, they are unbalanced.

### Key Concept: Stack-Based Validation

Utilizing a stack is ideal for validating nested structures because:
- Opening brackets are pushed as placeholders.
- Closing brackets trigger a check to ensure matching with the most recent unclosed opening bracket.
- The last-in-first-out nature of the stack precisely models the nested bracket structure.

### Time Complexity
- The algorithm examines each character once, resulting in $$O(n)$$ time complexity for an input string of length $$n$$.

```cpp
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

```
## Output:
<img width="423" height="114" alt="image" src="https://github.com/user-attachments/assets/6e39e7e0-a000-44c5-8df0-eb58c0740dda" />


### Applications
- Syntax checking in compilers and interpreters for programming languages.  
- Validating input formats with nested delimiters.  
- Foundational problem-solving in data structure courses.  

