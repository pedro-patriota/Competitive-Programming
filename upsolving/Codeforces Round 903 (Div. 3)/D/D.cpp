#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, set<int>> table;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        table[arr[i]].insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] % arr[i] == 0)
            {
                int aux = sqrt(arr[j] / arr[i]);
                if (aux*aux == (arr[j] / arr[i]))
                {
                   
                    table[arr[i]*aux].insert(i);
                    table[arr[j] / aux].insert(j);
                }
            }
        }
    }
    bool isPos = false;
    for (auto [_, s] : table)
    {
        if (s.size() == n)
        {
            cout << "YES" << endl;
            isPos = true;
            break;
        }
    }
    if (not isPos)
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest)
        cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}