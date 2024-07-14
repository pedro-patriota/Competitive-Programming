#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    stack<string> dir;
    string word = "", ans = "";
    path += '/';
    for (auto letter : path) {
        if (letter == '/') {
            if (word != "") {
                if (word == "..") {
                    if (not dir.empty()) {
                        dir.pop();
                    }
                } else if (word != "."){
                    dir.push(word);
                }
            }
            word = "";
        } else {
            word += letter;
        }
    }
    if (dir.empty()) {
        return "/";
    }
    while (not dir.empty()) {
        word = dir.top();
        ans = "/" + word + ans;
        dir.pop();
    }
    return ans;
}
int main () {

}
