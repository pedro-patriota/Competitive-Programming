#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m, n, from, to, dist;
vector<pair<ll, pair<ll, ll>>> adj;
vector<ll>parent, sizeUF;
void init (){
    for (ll i = 0; i < m; i++){
        parent[i] = i;
        sizeUF[i] = 1;
    }
}
ll findSet(ll x){
    if (x==parent[x]) return x;
    return (parent[x] = findSet(parent[x]));
}
void uniteSet(ll a, ll b){
    a = findSet(a);
    b = findSet(b);
    if (a != b){
        if (sizeUF[a] > sizeUF[b]){
            parent[b] = a;
            sizeUF[a] += sizeUF[b];
        }else{
            parent[a] = b;
            sizeUF[b] += sizeUF[a];
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    while (true)
    {
        cin >> m >> n;
        if (not m && not n){
            break;
        }
        adj = vector<pair<ll, pair<ll, ll>>>();
        sizeUF = parent = vector<ll>(m);
        for (ll i = 0; i < n; i++){
            cin >> from >> to >> dist;
            adj.push_back(make_pair(dist, make_pair(from, to)));           
        }
        ll mst_cost = 0;
        sort(adj.begin(), adj.end());
        init();
        for (ll i = 0; i < n; i++){
            auto front = adj[i];
            if (not (findSet(front.second.first) == findSet(front.second.second))){
                uniteSet(front.second.first, front.second.second);
            }else{
                mst_cost += front.first;
                
            }
        }
        cout << mst_cost << "\n";


    }
    
    
}