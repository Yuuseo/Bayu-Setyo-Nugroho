#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
            postfix += " "; 
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += " ";
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+(2*b^3)/(f-g)+d*h";
    cout << "Ekspresi Infix   : " << infix << endl;
    cout << "Ekspresi Postfix : " << infixToPostfix(infix) << endl;
    return 0;
}