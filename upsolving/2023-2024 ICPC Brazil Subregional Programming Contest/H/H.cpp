#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    const ll ms = 1e9 + 7;
    ll n, s;
    cin >> n >> s;
    vector<tuple<ll, ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        arr[i] = {from, to, cost};
    }

    sort(arr.begin(), arr.end());
    ll profit = 0;
    ll presentBreakEven = 0, presentCost = 1e18 + 17, presentTo = 0, presentFrom = 0;
    ll presentProfit = 0, newProfit;
    for (auto [from, to, cost] : arr)
    {

        if (from > presentTo && presentTo != 0)
        {
            presentCost = 1e18 + 17;
        }
        ll breakEven = (cost / s) + from;
        if (to >= breakEven)
        {
            presentProfit = max((presentTo - presentFrom + 1) * s - presentCost, (ll) 0);
            ll salary = (to - from + 1) * s - cost;
            newProfit = max((from - presentFrom) * s - presentCost +  salary, salary);
            
            if (newProfit > presentProfit  || (newProfit == presentProfit && to < presentTo))
            {
                profit += (newProfit - presentProfit);
                presentBreakEven = breakEven;presentCost = cost;presentTo = to; presentFrom = from;    
            }
        }
    }
    cout << profit << endl;

    return 0;
}