#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in(numCourses, 0);
    vector<int> order;
    
    for (int i = 0; i < prerequisites.size(); i++) {
        int to = prerequisites[i][0];
        int from = prerequisites[i][1];

        in[to]++;
        adj[from].push_back(to);
    }

    queue<int> pq;
    for (int i = 0; i < numCourses; i++) {
        if (in[i] == 0) {
            pq.push(i);
        }
    }

    while (not pq.empty()) {
        auto node = pq.front();
        order.push_back(node);

        pq.pop();

        for (auto nh : adj[node]) {
            if (--in[nh] == 0) {
                pq.push(nh);
            }
        }
    }

    if (order.size() != numCourses)
        return {};
    return order;
}

int main()
{
   
    return 0;
}