#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll N, C, M, c1, from, to;
vector<int> has_cheese ;
vector<vector<int>> adj_list;

void largest_bfs (int s){
    vector<bool> visited (N);
    priority_queue < pair<int, int>, vector<pair<int, int>> > pq;
    vector<int>dist(N, INT_MIN);
    dist[s] = has_cheese[s];
    pq.push(pair<int, int>(dist[s], s));
    visited[s] = true;
    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto d = pq.top().first;
        pq.pop();
        for (auto v : adj_list[u]){
            if (has_cheese[v] + d > dist[v]){
                visited[v] =true;
                dist[v] =  has_cheese[v] + d;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << dist[N-1] << endl;
    return;
    
}
void min_bfs (int s){
    vector<bool> visited (N);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int>dist(N, INT_MAX);
    dist[s] = has_cheese[s];
    pq.push(pair<int, int>(dist[s], s));
    visited[s] = true;
    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto d = pq.top().first;
        pq.pop();
        for (auto v : adj_list[u]){
            if (has_cheese[v] + d < dist[v]){
                visited[v] =true;
                dist[v] =  has_cheese[v] + d;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << dist[N-1] << endl;
    return;
    
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C >> M;
    adj_list = vector<vector<int>> (N);
    has_cheese = vector<int> (N);
    for (ll i = 0; i < C; i++){
        cin >> c1;
        c1--;
        has_cheese[c1] = 1;
    }
    for (ll i = 0; i < M; i++){
        cin >> from  >> to;
        from --;
        to--;
        adj_list[from].push_back(to);
    }
    min_bfs(0);
    largest_bfs(0);
    
        
    return 0;
    
}