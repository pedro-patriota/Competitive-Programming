#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate) {
    int cnt = senate.size(), first_r, first_d;
    queue<int> alive_r, alive_d;

    for (int i = 0; i < cnt; i++) {
        if (senate[i] == 'R') {
            alive_r.push(i);
        } else {
            alive_d.push(i);
        }
    }
    while (not alive_d.empty() && not alive_r.empty()) {
        first_d = alive_d.front();
        first_r = alive_r.front();
        alive_r.pop();
        alive_d.pop();
        if (first_d < first_r) {
            alive_d.push(cnt++);
        } else {
            alive_r.push(cnt++);
        }
    }
    if (alive_d.empty()) {
        return "Radiant";
    } else {
        return "Dire";
    }
}

int main () {

}