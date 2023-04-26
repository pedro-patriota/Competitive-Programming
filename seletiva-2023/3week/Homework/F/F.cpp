#include <bits/stdc++.h>
using namespace std;
long long m, n, i , j;
vector<deque<long long>> adj;
vector<long long> indegree;

void bfs(){
    vector<long long> top_order;
    queue<long long> q;

    for (long long i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        long long u = q.front();
        top_order.push_back(u);
        q.pop();
        for (long long v : adj[u]){
            indegree[v]--;
            if (indegree[v] == 0){
                q.push(v);
            }
        }   
    }
    for (auto val : top_order){
        cout << val+1 << " ";
    }
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    while (true){
        cin >> n >> m;
        if (m == 0 && n ==0){
            break;
        }
        adj = vector<deque<long long>>(n);
        indegree = vector<long long>(n);
        for (long long edge = 0; edge < m ; edge++){
            cin >> i >> j;
            i--;
            j--;
            indegree[j]++;
            adj[i].push_back(j);
        }
        bfs();
        cout << "\n";
    }
    
}