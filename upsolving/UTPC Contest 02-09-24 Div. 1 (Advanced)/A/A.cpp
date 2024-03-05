#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = false;

void solve(){
    int n, p, t, s;
    cin >> n >> p >> t >> s;
    int mx = 2*n + min(s/2, n);
    if (mx >= p || mx >= t){
        cout << "yes" << endl;
     }else{
        cout << "no" << endl;
     }
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