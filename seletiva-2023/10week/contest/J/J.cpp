#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m, p1, p2, num_user;
vector<int> sizeUF, parent, marked;

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
    marked = sizeUF = parent = vector<int>(n);

    for (ll i = 0; i < n; i++)
    {
        sizeUF[i] = 1;
        parent[i] = i;
        marked[i] = false;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> num_user;
        if (num_user == 0)
            continue;

        cin >> p1;
        p1--;

        num_user--;

        for (ll j = 0; j < num_user; j++)
        {
            cin >> p2;
            p2--;
            uniteSet(p1, p2);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << sizeUF[findSet(i)] << " ";
    }
}