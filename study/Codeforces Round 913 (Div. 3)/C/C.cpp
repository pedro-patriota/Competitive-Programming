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
    int n;
    string s;
    cin >> n >> s;
    vector<int> alfa(26, 0);
    int mx = 0;
    for (int i = 0 ; i < s.size(); i++){
        mx = max(mx, ++alfa[s[i] - 'a']);
    }
    int ans =  max(n%2, 2*mx - n);
    cout << ans << endl;
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