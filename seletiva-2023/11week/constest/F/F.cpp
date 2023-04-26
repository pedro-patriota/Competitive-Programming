#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, T, K, P, p1, from, to, minutes;
    cin >> N >> M >> T >> K >> P;
    vector<vector<pair<ll,ll>>>adj_list (N);
    vector<ll>laugh (N);
    for (ll i = 0; i < P; i++){
        cin >> p1;
        p1--;
        laugh[p1] = K;
    } 
    for (ll i = 0; i < M; i++){
        cin >> from >> to >> minutes;
        from--;
        to--;
        minutes *= 60;
        adj_list[from].push_back(make_pair(to, minutes));

    }
    ll s = 0;
    vector<ll>dist(N, __LONG_LONG_MAX__);
    dist[s] = 0;
    priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
    pq.push(pair<ll, ll>(0, s));

    while (!pq.empty()){
        pair<ll, ll> front = pq.top();
        pq.pop();
        ll d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto v : adj_list[u]){
            if (dist[u] + v.second + laugh[v.first] < dist[v.first]){
                dist[v.first] = dist[u] + v.second + laugh[v.first];
                pq.push(pair<ll, ll> (dist[v.first], v.first));
            }
        }
    }
    if (dist[N -1] > T*60){
        cout << -1;
    }else{
        cout << dist[N-1];
    }
    

        
    return 0;
    
}