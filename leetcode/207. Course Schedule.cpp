#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj (numCourses);
    for (auto arr : prerequisites) {
        adj[arr[1]].push_back(arr[0]);
    }

    vector<int> in (adj.size());
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            in[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (not q.empty()) {
        auto v = q.front();
        ans.push_back(v);
        q.pop();

        for (auto nh : adj[v]) {
            if (--in[nh] == 0) {
                q.push(nh);
            }
        }
    }
    return ans.size() == in.size();

}

int main () {

}
