#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<char> st;
    stack<int> result;
    s = '(' + s + ')';

    for (auto l : s) {
        if (l == ')') {
            while (st.top() != '(') {
                char c = st.top();
                st.pop();
                if (c == ' ') {
                    continue;
                }
                if (c != '+' && c != '-'){
                    result.push(c - '0');
                } else {
                    int next = st.top() - '0';
                    int last = result.top();
                    st.pop();
                    result.pop();
                    if (c == '+') {
                        result.push(last+next);
                    } else {
                        result.push(last-next);
                    }
                }
            }
        } else {
            st.push(l);
        }
    }   
    return result.top();
}

int main () {

}
