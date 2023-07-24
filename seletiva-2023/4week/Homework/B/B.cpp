#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, p1, p2;
vector<ll> sizeUF, parent;

ll findSet(ll x)
{
    if (x == parent[x])
        return x;
    return (parent[x] = findSet(parent[x]));
}
void uniteSet(ll a, ll b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sizeUF[a] > sizeUF[b])
        {
            parent[b] = a;
            sizeUF[a] += sizeUF[b];
        }
        else
        {
            parent[a] = b;
            sizeUF[b] += sizeUF[a];
        }
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    set<ll> aux;
    vector<bool> mark(n, false);
    sizeUF = parent = vector<ll>(n);
    for (ll i = 0; i < n; i++)
    {
        sizeUF[i] = 1;
        parent[i] = i;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> p1 >> p2;
        p1--;
        p2--;
        if (!aux.count(p1))
        {
            mark[p1] = true;
            aux.insert(p1);
        }
        if (!aux.count(p2))
        {
            mark[p2] = true;
            aux.insert(p2);
        }
        uniteSet(p1, p2);
    }
    vector<set<ll>> map_sets(n);
    for (auto it : aux)
    {
        map_sets[findSet(it)].insert(it);
    }
    ll counter = 0;
    for (auto val = aux.begin(); val != aux.end(); ++val)
    {
        ll max_in_set = *--map_sets[findSet(*val)].end();
        if (max_in_set == *val)
        {
            continue;
        }
        for (ll next_val = *val + 1; next_val < max_in_set; next_val++)
        {
            if (!mark[next_val])
            {
                counter++;
                continue;
            }
            if (findSet(*val) != findSet(next_val))
            {
                ll max_out_set = *--map_sets[findSet(next_val)].end();
                if (max_out_set > max_in_set)
                    max_in_set = max_out_set;
                counter++;
                uniteSet(*val, next_val);
            }
        }
        val = lower_bound(aux.begin(), aux.end(), max_in_set);
    }

    cout << counter;
}