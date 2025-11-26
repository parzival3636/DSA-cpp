# Assignment 25 - Postfix Expression Evaluation Using Stack

## Evaluating Postfix Expressions Using a Stack

This program evaluates a postfix (Reverse Polish Notation) expression containing single-digit operands and binary operators (`+`, `-`, `*`, `/`). The operands appear before their operators, removing the need for parentheses and precedence rules.

### Operations Implemented
- **Push Operands:** When encountering an operand (digit), push it onto the stack.  
- **Evaluate Operators:** When encountering an operator, pop the top two operands from the stack, perform the operation, and push the result back onto the stack.  
- **Final Result:** After processing all symbols, the value remaining on the stack is the result of the expression.

### Key Concept: Stack-Based Postfix Evaluation

The algorithm leverages the Last-In-First-Out (LIFO) property of stacks to:
- Store operands as intermediate values.
- Apply operators to the most recent operands popped from the stack.
- Accumulate the computation stepwise until one final result remains.

### Time Complexity
- Each symbol in the expression is processed once, resulting in $$O(n)$$ time complexity for an expression of length $$n$$.

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    
    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
```
<img width="368" height="47" alt="image" src="https://github.com/user-attachments/assets/7ddd8c7f-de40-4568-9592-2473f417ff18" />


### Applications
- Expression evaluation in calculators and compilers.  
- Simplified arithmetic parsing avoiding operator precedence and parentheses.  
- Foundational example for learning stack applications in algorithms.

