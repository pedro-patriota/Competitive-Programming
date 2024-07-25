#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto v : nums) {
        if (pq.size() < k) {
            pq.push(v);
        } else if (pq.top() < v) {
            pq.push(v);
            pq.pop();
        }
    }
    return pq.top();
}

