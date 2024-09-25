#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> right, invert;
    vector<int> ans;
    int opposite, sz;
    for (auto asteroid : asteroids) {
        sz = abs(asteroid);
        if (asteroid < 0) {
            while (true) {
                if (right.empty()) {
                    ans.push_back(asteroid);
                    break;
                }
                opposite = right.top();
                if (opposite > sz) {
                    break;
                }
                right.pop();
                if (opposite == sz) {
                    break;
                }
            }
        } else {
            right.push(sz);
        }
    }
    while (not right.empty()) {
        opposite = right.top();
        invert.push(opposite);
        right.pop();
    }
    while (not invert.empty()) {
        opposite = invert.top();
        ans.push_back(opposite);
        invert.pop();
    }
    return ans;
}

int main () {

}