#include <bits/stdc++.h>
using namespace std;

/*
n = 3
"((()))","(()())","(())()","()(())","()()()"

n = 2
()() (()) ...

n = 0
_

n = 1
()

()) (() )))(((   (())...

left = 0
right = 0
n = 3
ans = {}
curr = ""

if left == n && right == n
    return ans

if (left < n) 
    generateParenthesis(curr + '(', left + 1, ...)
if (left > right) :
    generateParenthesis(curr + ')' , right + 1, ...)


time: O(n^2)
space: O(1) not considering
*/

void generateParenthesis(vector<string>& ans, int left, int right, int n, string curr) {
    if (left == n && right == n) {
        ans.push_back(curr);
    } else {
        if (left < n) {
            generateParenthesis(ans, left + 1, right, n, curr + '(');
        }
        if (left > right) {
            generateParenthesis(ans, left, right + 1, n, curr + ')');
        }
    }
}

int main () {
    vector<string> ans = {};
    generateParenthesis(ans, 0, 0, 4, "");
    for (auto str : ans) {
        cout << str << " ";
    }
    cout << endl;

}