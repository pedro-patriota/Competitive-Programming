#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define iii pair<pair<int, int>, int>
#define X first
#define Y second

const int ms = 1e5 + 17;
int from, to, n, m, beg, finish, v;
vector<vector<ii>> adj;
ii best[ms];


void Dijkstra(int node){
    priority_queue<iii, vector<iii>, greater<iii>> q;
	
    q.push({{0, 0}, node});
    while (!q.empty()){
        int levelSz = q.size();
        while (levelSz--){
            auto [dist, curr] = q.top();
            auto [qntWait, dayFrom] = dist;
            q.pop();
            
            if (qntWait > best[curr].first) continue;
           
            for (auto [day, to] : adj[curr]){

                int newWait = (7 + ((day - dayFrom) % 7)) % 7 + 1;
            
                if (qntWait + newWait <  best[to].first){
                    best[to] = {qntWait + newWait, (day + 1)%7};
                    q.push({best[to], to});
                    continue;
                }
            }
            
        }
    }

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> beg >> finish;
    beg--;
    finish--;
    adj.resize(n);
    for (int i = 0; i < ms; i++){
        best[i] = {1e9 + 17, 1e9 + 17};
    }
    for (int i  = 0; i < m; i++){
        cin >> from >> to >> v;
        from--;
        to--;
        v--;    
        adj[from].push_back({v, to});
        adj[to].push_back({v, from});
    }

    best[beg] = {0, 0};
    Dijkstra(beg);
    cout << best[finish].first << endl;
    
    
        
    return 0;
    
}