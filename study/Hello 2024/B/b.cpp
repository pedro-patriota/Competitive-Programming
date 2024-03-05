#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

bool multiTest = true;

int n, ans;
char k;
void solve(){
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++){
        cin >> k;
        ans += k == '+' ? 1 : -1;
    }
    cout << abs(ans) << endl;
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