#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

void solve(){
    vector<int> freq (37, 0);
    int n, num; cin >> n; ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> num;
        int msb = 31 - __builtin_clz(num);
        ans += freq[msb];
        freq[msb]++;
    }
    cout << ans<< endl;
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