#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, m, buy, sell, month, aux;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<ll> min_dp (n+1, LLONG_MAX);

    int minVal = min(m, n);
    cin >> buy;
    min_dp[0] = buy;
    for (ll j = 1; j <= minVal; j++){
        cin >> sell;
        min_dp[j] = min_dp[0] - sell;
    }
    
    for (ll i = 2; i <= n; i++){
        int minVal = min(m, n -i + 1);
        cin >> buy;
        for (ll j = 1; j <= minVal; j++){
            month = i - 1 + j;
            cin >> sell;
            aux = (buy - sell) + min_dp[month - j];
            min_dp[month] = min(min_dp[month], aux);
        }
    }
    cout << min_dp[n];

    
        
    return 0;
    
}