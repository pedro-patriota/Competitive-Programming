#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_a_b(stack<int>& st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    return {a, b};
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (auto s : tokens) {
        if (s == "+") {
            auto [a, b] = get_a_b(st);
            st.push(a+b);

        } else if (s == "-") {
            auto [a, b] = get_a_b(st);
            st.push(a-b);

        } else if (s == "*") {
            auto [a, b] = get_a_b(st);
            st.push(a*b);

        } else if (s == "/") {
            auto [a, b] = get_a_b(st);
            st.push(a/b);

        } else {
            st.push(stoi(s));
        }
    }   
    return st.top();
}

int main () {

}
