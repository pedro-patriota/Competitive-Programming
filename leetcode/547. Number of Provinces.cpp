#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> adj;
unordered_set<int> vis;
void dfs(int v) {
    vis.insert(v);
    for (auto nh :  adj[v]) {
        if (not vis.count(nh)) {
            dfs(nh);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    for (int i = 0; i < isConnected.size(); i++) {
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1) {
                adj[i].insert(j);
            }
        }
    }  
    int cnt = 0;
    for (int i = 0; i < isConnected.size(); i++) {
        if (not vis.count(i)) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}
