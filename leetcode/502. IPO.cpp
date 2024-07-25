#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int sz = capital.size();
    k = min(k, sz);
    priority_queue<int> pq;
    vector<ii> arr (sz);
    for (int i = 0; i < sz; i++) {
        arr[i] = {capital[i], profits[i]};
    }
    sort(arr.begin(), arr.end());
    for (auto [cap, prof] : arr) {        
        while (cap > w && k-- && not pq.empty()) {
            w += pq.top();
            pq.pop();
        }
        if (k == 0) {
            return w;
        }
        if (cap <= w) {
            pq.push(prof);
        }

    }
    while (k-- && not pq.empty()) {
        w += pq.top();
        pq.pop();
    }
    return w;
}
