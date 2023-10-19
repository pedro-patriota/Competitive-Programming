#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve(){
    int n; cin >> n;
    vector<int> arr(n + 7);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> dp (n + 7, 1e9);
    dp[n] = 0;
    for (int i = n -1; i >= 0; i--){
        if (i + arr[i] + 1 <= n){
            dp[i] = min(dp[i + arr[i] + 1], dp[i + 1] + 1);
        }else{
            dp[i] = dp[i + 1] + 1;
        }
    }
    cout << dp[0] << endl;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest) cin >> t;
    while(t--){
        solve();
    }
    return 0;
    
}