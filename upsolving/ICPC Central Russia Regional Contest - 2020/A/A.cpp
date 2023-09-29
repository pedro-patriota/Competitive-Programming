#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int n, k, val;
vector<vector<int>> adj;
const int ms = 1e5 +17;
vector<ii> nodes ;
vector<bool> vis;
vector<int> kChoosen;
ii a = {-1, 0};

void dfs(int node, int height){
    vis[node] = true;
    nodes[node].second  = height;
    for (auto neighborhood : adj[node]){
        if (not vis[neighborhood]){
            dfs(neighborhood, height + 1);
            nodes[node].first += nodes[neighborhood].first;
        }
    }
    nodes[node].first += 1;
    return;
}

void getK(int node){
    vis[node] = true;

    if (kChoosen.size() == k) return;
    kChoosen.push_back(node);


    for (auto neighborhood : adj[node]){
        if (not vis[neighborhood] && nodes[neighborhood].Y > a.X){
            getK(neighborhood);
           
        }
    }
    return;

}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    adj.resize(n + 1);
    nodes.resize(n + 1, {0, 0});
    vis.resize(n + 1, false);
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> val;
        adj[val].push_back(i + 1);
    }   
    dfs(1, 0);
    for (int i  = 1; i <= n; i++){
        if (nodes[i].X >= k && nodes[i].Y > a.X){
            a.X = nodes[i].Y;
            a.Y = i;
        }
    }
    if (a.X == -1){
        cout << -1;
        return 0;
    }
    vis = vector<bool>(n+1, false);
    getK((int) a.Y);

    for (auto v : kChoosen){
        cout << v << " ";
    }



    return 0;
}