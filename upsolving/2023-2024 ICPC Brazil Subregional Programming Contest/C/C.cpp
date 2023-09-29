#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

const int ms = 1e5 + 17;

multiset<int> s;
vector<vector<int>> adj (ms);
vector<bool> visited(ms, false);
vector<int> ans(ms, 0);
vector<int> arr(ms, 0);
vector<int> subs(ms);
void dfs(int v){
    visited[v] = true;
    for (auto u : adj[v]){
        if (not visited[u]){
            
            auto it = s.lower_bound(arr[u]);
            if (it == s.end()){
                s.insert(arr[u]);
            }else{
                subs[u] = (*it);
                s.erase(it);
                s.insert(arr[u]);
            }
            ans [u] = s.size();

            dfs(u);
        }
    }

    auto f = s.find(arr[v]);
    if (f != s.end()) s.erase(f);
    if (subs[v]) s.insert(subs[v]);
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i ++){
        int to; cin >> to;
        adj[i].push_back(to);
        adj[to].push_back(i);
    }
    for (int i  = 1; i <= n; i++){
        cin >> arr[i];
    }
    s.insert(arr[1]);
    ans[1] = 1;
    dfs(1);
    
    for (int i = 2; i <= n; i++){
        cout << ans[i] << " ";
    }
        
    return 0;
    
}