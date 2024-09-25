#include <bits/stdc++.h>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> pq_left, pq_right;
    long long sz = costs.size(), ans = 0, min_left, min_right, left = 0,
        right = sz - 1;

    for (int i = 0; i < candidates; i++) {
        if (left <= right) {
            pq_left.push(costs[left++]);
        }
        if (left <= right) {
            pq_right.push(costs[right--]);
        }
    }

    while (k--) {
        if (pq_left.empty()) {
            ans += pq_right.top();
            pq_right.pop();
            continue;
        }
        if (pq_right.empty()) {
            ans += pq_left.top();
            pq_left.pop();
            continue;
        }

        min_left = pq_left.top();
        min_right = pq_right.top();

        if (min_left <= min_right) {
            ans += min_left;
            pq_left.pop();
            if (left <= right) {
                pq_left.push(costs[left++]);
            }
        } else {
            ans += min_right;
            pq_right.pop();
            if (left <= right) {
                pq_right.push(costs[right--]);
            }
        }
    }
    return ans;
}


int main () {

}