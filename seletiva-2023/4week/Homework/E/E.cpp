#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p_ll pair<ll, ll>

ll test_cases, n, m, S, T, init, finish, w;
priority_queue<p_ll, vector<p_ll>, greater<p_ll>> pq;
vector<long long> dist;
vector<vector<p_ll>> adj;



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test_cases;
    for (ll i =0; i < test_cases; i++){
        cin >> n >> m >> S >> T;
        dist = vector<long long>(n, LLONG_MAX);
        pq = priority_queue<p_ll, vector<p_ll>, greater<p_ll>>();                                           
        adj = vector<vector<p_ll>>(n);
        pq.push(p_ll(S, 0));
        dist[S] = 0;
        for (ll cable = 0; cable < m; cable++){
            cin >> init  >> finish >> w;
            adj[init].push_back(make_pair(finish, w));
            adj[finish].push_back(make_pair(init, w));
        }
        while (!pq.empty()){
            p_ll front = pq.top();
            pq.pop();
            ll u = front.first, d = front.second;
            if (d > dist[u]){
                continue;
            }
            for (auto it : adj[u]){
                if (dist[u] + it.second < dist[it.first]){
                    dist[it.first] = dist[u] + it.second;
                    pq.push(p_ll(it.first, dist[it.first]));
                }
            }
        }
        if (dist[T] == LLONG_MAX){
            cout << "Case #" << i+1 << ": " << "unreachable" << "\n";
        }else{
            cout << "Case #" << i+1 << ": " << dist[T] << "\n";

        }
    }

    
}