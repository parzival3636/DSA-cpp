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