#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
    char c = exp[i];

    if (isdigit(c)) {
        st.push(c - '0');
    }
    else {
        int val2 = st.top(); st.pop();
        int val1 = st.top(); st.pop();

        switch (c) {
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
    string postfix;

    cout << "Masukkan ekspresi postfix: ";
    cin >> postfix;

    cout << "Hasil evaluasi: " << evaluatePostfix(postfix) << endl;

    return 0;
}