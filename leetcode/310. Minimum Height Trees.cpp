#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return {0};
    }
    unordered_map<int, unordered_set<int>> adj;
    unordered_map<int, int> vis;
    for (int i = 0; i < edges.size(); i++) {
        auto p1 = edges[i][0];
        auto p2 = edges[i][1];

        vis[p1]++;
        vis[p2]++;
        adj[p1].insert(p2);
        adj[p2].insert(p1);
    }
    queue<int> q;
    for (auto [v, freq] : vis) {
        if  (freq == 1) {
            q.push(v);
        }
    }
    while (q.size() > 2) {
        int sz = q.size();
        while (sz--) {
            auto v = q.front();
            q.pop();
            for (auto nh : adj[v]) {
                if (--vis[nh] == 0) {
                    q.push(nh);
                }
            }
        }
    }
    vector<int> ans;
    while (not q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
