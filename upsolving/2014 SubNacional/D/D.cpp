#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll s, t, a, b, c, q, x, m;
vector<vector<pair<int, ll>>> adj;

const int ms = 1e4 + 17;
vector<bool> visited;
vector<ll> runSum;
ll minVal;
set<pair<int, int>> seen;

void dfs(int u, ll len)
{
    visited[u] = true;
    //cout << u << endl;
    runSum[u] = len;
    for (int i = 0; i < adj[u].size(); i++)
    {
        auto [v, w] = adj[u][i];
        if (not visited[v])
        {
            /*  seen.insert(make_pair(u, v));
             seen.insert(make_pair(u, v)); */
            dfs(v, len + w);
        }
        else
        {
            if (runSum[v] + w < len)
            {

                ll sum = len + w + runSum[v], topVertice, topLen;
                // talvez falte um pop
                // cout << " " << u << " " << v << " " << runSum[v] << " " << w << " " << len << endl;
                if (sum >= m && sum < minVal)
                {
                    minVal = sum;
                }
            }
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    

        cin >> t;

        adj = vector<vector<pair<int, ll>>>(s + 1);

        for (int i = 0; i < t; i++)
        {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        cin >> q;
        runSum = vector<ll>(s + 1);
        for (int i = 0; i < q; i++)
        {
            cin >> x >> m;
            minVal = LLONG_MAX;
            visited = vector<bool>(s + 1, false);

            dfs(x, 0);
            if (minVal == LLONG_MAX)
            {
                cout << -1;
            }
            else
            {
                cout << minVal;
            }
            cout << endl;
        }
    
    return 0;
}