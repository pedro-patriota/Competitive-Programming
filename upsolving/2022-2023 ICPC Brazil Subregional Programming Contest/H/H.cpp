#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int ms = 1e4 + 17;
int connected[ms], fromCity;
vector<vector<ll>> ajdList;
vector<bool> visited;
vector<bool> processed;
vector<ll> num;
vector<ll> lowest;
int bridges = 0;
stack<ll> s;
ll i = 0, numScc = 0;

vector<ll> sizeUF, parent;


void dfs(int city){
    num[city] = i;
    lowest[city] = i;
    i++;
    visited[city] = true;
    s.push(city);

    //cout << city << endl;
    for (auto neighborhood : ajdList[city]){
        if (not visited[neighborhood]){
            dfs(neighborhood);
            lowest[city] = min(lowest[city], lowest[neighborhood]);

        }
        else{
            if (not processed[neighborhood]){
                lowest[city] = min(lowest[city], num[neighborhood]);
            }
        }
    }
    processed[city] =true;
    if (lowest[city] == num[city]){
        vector<ll> scc;
        ll sccVertex = s.top();
        s.pop();
        while (sccVertex != city){
            //scc.push_back(sccVertex);
            sccVertex = s.top();
            s.pop();
        }
        numScc++;
        //scc.push_back(sccVertex);
    }

}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, v1, v2;
    cin >> n >> m;
    num  = vector<ll>(n);
    lowest = vector<ll>(n);
    ajdList = vector<vector<ll>>(n);
    for (ll i = 0; i < m; i++){
        cin >> v1 >> v2;
        v1--;
        v2--;
        ajdList[v1].push_back(v2);
    }
    processed = visited = vector<bool>(n, false);
    for (int v  =0; v < n; v ++){
        if (not visited[v] ) dfs(v);
    }
    vector<ll>  in (n), out (n);
    set<pair<ll, ll>> sccGraph; 
    for (int v = 0; v < n; v++){
        for (auto val : ajdList[v]){
            ll sccGroup1 = lowest[v];
            ll sccGroup2 = lowest[val];

            if (sccGroup1 != sccGroup2){
                in[sccGroup2]++;
                out[sccGroup1]++;
            }
        }
    }
    ll yesIn = 0, yesOut = 0;
    for (auto val : in){
        if (val != 0){
            yesIn++;
        }
    }
    for (auto val : out){
        if (val != 0){
            yesOut++;
        }
    }
    if (numScc == 1) {cout << 0; return 0;}
    cout << max(numScc - yesIn, numScc - yesOut);
    
        
    return 0;
    
}