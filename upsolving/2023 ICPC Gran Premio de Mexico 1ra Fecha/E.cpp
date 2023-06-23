#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<ll> needN;
vector<vector<int>> adj;
vector<int> sizeTree;
vector<int> visited;
vector<int> inDegree;
vector<int> zeroDegree;
vector<int> ans;
vector<vector<tuple<ll, int>>> bonus;
vector<vector<tuple<ll, int>>> rest;
const ll ms = (1e5 + 100);
ll seg[4 * ms];

void getSize(int node)
{
    for (auto next : adj[node])
    {
        if (not visited[next])
        {
            getSize(next);
            sizeTree[node] += sizeTree[next];
        }
    }
}

void update(int pos, ll num, int l, int r, int idx)
{
    if (l == r)
    {
        seg[idx] = num;
        return;
        
    }
    int m = (l + r) / 2;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (pos <= m)
    {
        update(pos, num, l, m, left);
    }
    else
    {
        update(pos, num, m + 1, r, right);
    }
    seg[idx] = seg[left] + seg[right];
}

int query(ll sum, int l, int r, int idx)
{
    if (l == r)
    {
        //cout << sum << " " << l << endl;
        return l;
    }
    int m = (l + r) / 2;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (seg[left] >= sum)
    {
        return query(sum, l, m, left);
    }
    else
    {
        return query(sum, m + 1, r, right);
    }
}

void solve(int node)
{
    for (auto [bonus, from] : bonus[node])
    {
        update(from, bonus, 0, ms - 1, 0);
    }
    //cout << node << " " << seg[0] << " - " << endl;
    for (auto val : adj[node])
    {
        solve(val);
    }
    for (auto [rest, from] : rest[node])
    {
        update(from, rest, 0, ms - 1, 0);
    }
    if (seg[0] < needN[node])
    {
        ans[node] = -1;
    }
    else
    {
        ans[node] = min(ans[node], query(needN[node], 0, ms - 1, 0) + 1);
    }
    for (auto [bonus, from] : bonus[node])
    {
        update(from, 0, 0, ms - 1, 0);
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll val;
    int N, Q, from, to;
    cin >> N >> Q;
    needN = vector<ll>(N);
    bonus = vector<vector<tuple<ll, int>>>(N);
    rest = vector<vector<tuple<ll, int>>>(N);
    inDegree = vector<int>(N);
    ans = vector<int>(N, 4*ms);
    visited = vector<int>(N, false);
    sizeTree = vector<int>(N, 1);
    adj = vector<vector<int>>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> needN[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> from >> to;
        from--;
        to--;
        inDegree[to]++;
        adj[from].push_back(to);
    }

    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
        {
            zeroDegree.push_back(i);
            getSize(i);
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> from >> val;
        from--;
        ll divided_bonus = val / sizeTree[from];
        bonus[from].push_back(make_tuple(divided_bonus, i));
        if (val % sizeTree[from] != 0)
        {
            rest[from].push_back(make_tuple(divided_bonus + val % sizeTree[from], i));
        }
    }
    for (auto node : zeroDegree)
    {
        solve(node);
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}