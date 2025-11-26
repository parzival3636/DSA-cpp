# Assignment 22 - Infix to Postfix Conversion Using Stack

## Converting Infix Expressions to Postfix Using Stack

This program converts an infix arithmetic expression (where operators are written between operands, e.g., `a - b * c`) into its equivalent postfix expression (where operators follow operands, e.g., `abc*-`) using a stack. This transformation simplifies expression evaluation by eliminating the need for precedence rules during computation.

### Operations Implemented
- **Operator Precedence and Associativity:** Determine precedence levels of operators (`+`, `-`, `*`, `/`, `^`) to decide processing order.  
- **Handling Parentheses:** Push opening parentheses onto the stack and pop until opening when encountering closing parentheses to maintain grouping.  
- **Conversion Steps:** Scan infix expression character by character, appending operands to output, pushing operators onto the stack while handling precedence and associativity, and popping operators as needed.  
- **Stack Draining:** After scanning the expression, pop and append all remaining operators from the stack.

### Key Concept: Stack-Based Shunting Yard Algorithm

The algorithm uses a stack to temporarily hold operators with rules:
- If an operand is seen, append it to the output.
- If an operator is seen, pop from the stack to output while the operator at the top of the stack has higher or equal precedence (accounting for associativity), then push the current operator.
- If opening parenthesis, push it.
- If closing parenthesis, pop until opening parenthesis is found.

Step-by-step tracing shows the character read, action taken, current stack contents (top to bottom), and output so far, which aids understanding and debugging.

### Time Complexity
- The algorithm processes each character in the expression once, leading to an overall $$O(n)$$ time complexity for an expression of length $$n$$.


```cpp
#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

string stackContents(stack<char> s) {
    string r;
    vector<char> v;
    while (!s.empty()) { v.push_back(s.top()); s.pop(); }
    for (int i = (int)v.size()-1; i>=0; --i) r.push_back(v[i]);
    return r.empty() ? "∅" : r;
}

string infixToPostfixWithTrace(const string &infix) {
    stack<char> st;
    string out;
    cout << left << setw(6) << "Char" << setw(20) << "Action" << setw(20) << "Stack(top→bottom)" << "Output so far\n";
    cout << "----------------------------------------------------------------\n";

    for (char ch : infix) {
        if (isspace(ch)) continue;
        if (isalnum(ch)) {
            out.push_back(ch);
            cout << setw(6) << ch << setw(20) << "Append to output" << setw(20) << stackContents(st) << out << '\n';
        } else if (ch == '(') {
            st.push(ch);
            cout << setw(6) << ch << setw(20) << "Push '('" << setw(20) << stackContents(st) << out << '\n';
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                out.push_back(st.top()); st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
            cout << setw(6) << ch << setw(20) << "Pop until '('" << setw(20) << stackContents(st) << out << '\n';
        } else if (isOperator(ch)) {
            string action;
            while (!st.empty() && isOperator(st.top()) &&
                   ((prec(st.top()) > prec(ch)) || (prec(st.top()) == prec(ch) && ch != '^'))) {
                out.push_back(st.top());
                st.pop();
            }
            st.push(ch);
            action = "Handle operator";
            cout << setw(6) << ch << setw(20) << action << setw(20) << stackContents(st) << out << '\n';
        } else {
            cout << setw(6) << ch << setw(20) << "Ignored/Unknown" << setw(20) << stackContents(st) << out << '\n';
        }
    }

    while (!st.empty()) {
        if (st.top() != '(' && st.top() != ')') out.push_back(st.top());
        st.pop();
    }
    cout << setw(6) << "-" << setw(20) << "Draining stack" << setw(20) << "∅" << out << '\n';
    return out;
}

int main() {
    string expr;
    cout << "Enter infix expression (e.g. a-b*c-d/e+f): ";
    getline(cin, expr);
    string postfix = infixToPostfixWithTrace(expr);
    cout << "\nPostfix: " << postfix << '\n';
    return 0;
}



//a-b*c-d/e+f
```
<img width="540" height="311" alt="image" src="https://github.com/user-attachments/assets/e1f12d71-5e4b-4a51-830f-a3a8ec8eda9d" />

### Applications
- Expression evaluation engines in calculators and compilers.  
- Rearranging mathematical expressions for stack-based or postfix machines.  
- Syntax parsing in programming language processing.



***
