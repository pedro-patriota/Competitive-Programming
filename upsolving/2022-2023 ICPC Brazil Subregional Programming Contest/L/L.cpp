#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<pair<ll, ll>, pair<ll, ll>> edgeMap;
vector<vector<ll, ll>> adjList;
multiset<pair<ll, ll>> inSet;
const int ms = 1e5 + 17;
int visited[ms];
int color;

solve(){
    


}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);


    ll n;
    adjList = vector<vector<ll>> (n+1);
    vector<pair<ll, ll>> edges;
    vector<ll> colorArr (n+1);
    vector<ll> qntColor (n+1);
    vector<ll> in(n+1);

    for (int i = 0; i < n; i++) cin >> colorArr[i]; qntColor[coloArr[i]]++;
    for (int i  = 0; i < n-1; i++){
        ll v, l;
        cin >> v >> l;
        in[v]++;
        in[l]++;
        
        edges.push_back(make_pair(v , l));
        adjList[v].push_back(l);
        adjList[l].push_back(v);
    }
    solve();
    ll qnt;
    for (int i  =0; i < n; i++){
        qnt = in[i];
        inSet.insert(make_pair(qnt, i));
    }
    set<pair<ll, map<ll, ll> >> usedColors;

    for (auto [qnt, v] : inSet){
        if (not visited[v]) {
            visited[v] = true;
            color = colorArr[v];
            qnt = qntColor[color];
            usedColors
            ll temp = 0;
            for (auto u : adjList[v]){
                pair<ll, ll> p;
                if (edgeMap.count(make_pair(v, u))){
                    p = make_pair(v, u);
                }else{
                    p = make_pair(u, v);
                }
                if (visited[u]){
                    temp += edgeMap[p];
                    continue;
                };

                edgeMap[p] += qnt -1 + temp;

            }
        }
    }

    
    
    return 0;
    
}