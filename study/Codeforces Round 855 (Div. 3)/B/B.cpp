#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve(){   
    int n, k; cin >> n; cin >> k;
    string s; cin >> s;
    int ans = 0;
    vector<ii> alfa (26, {0, 0});
    for (int i = 0; i < n; i++){
        char c = s[i];
        int id = tolower(c) - 'a';
        if (toupper(c) == c){
            alfa[id].Y += 1;
        }else{
            alfa[id].X += 1;
        }
    }
    for (int i = 0; i < 26; i++){
        //cout <<  'a' + i << "-> " <<alfa[i].X << " " << alfa[i].Y << endl;
        int mn = min(alfa[i].X, alfa[i].Y);
        ans += mn;
        if (k > 0){
            int diff = abs(alfa[i].X - alfa[i].Y);
            int rest = min(k, diff/2);
            ans += rest;
            k -= rest;
        }
    }
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