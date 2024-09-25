#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<pair<int, bool>>>& new_roads, vector<bool>& visited) {
    visited[node] = true;
    int ans = 0;
    for (auto [nh, is_built] : new_roads[node]) {
        if (not visited[nh]) {
            ans += (int) not is_built;
            ans += dfs(nh, new_roads, visited);
        }
    }
    return ans;
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, bool>>> new_roads(n);
    vector<bool> visited(n, false);
    for (int con = 0; con < n-1; con++) {
        int from = connections[con][0], to = connections[con][1];
        new_roads[from].push_back({to, false});
        new_roads[to].push_back({from, true});
    }   
    return dfs(0, new_roads, visited);
}

int main () {

}