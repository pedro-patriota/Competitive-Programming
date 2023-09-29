#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
 
int main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b; 
    cin >> n;

    vector<ll> odd;

    for(int i = 0; i < n; i++){
        ll x; 
        cin >> x;
        if(x%2 == 1)
            odd.push_back(i);
    }

    cin >> a >> b;
    a = min(a, b);

    if (odd.size() == 0){
        cout << 0 << "\n";
        return 0;
    }

    if(odd.size()%2 == 1){
        cout << -1 << "\n";
        return 0;
    }

    vector<ii> dp(odd.size());

    dp[0].first = ((odd[0] - odd[odd.size()-1]) + n)%n;
    dp[0].second = odd[1] - odd[0];
    
    for(int i = 1; i < odd.size() - 1; i++){
        dp[i].first = dp[i-1].second;
        dp[i].second = dp[i-1].first + (odd[i+1] - odd[i]);
    }
    
    cout << min(dp[odd.size()-2].first, dp[odd.size()-2].second) * a << "\n";
        
    return 0;
    
}