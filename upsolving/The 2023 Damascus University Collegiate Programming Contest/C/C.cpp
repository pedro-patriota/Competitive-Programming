#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2){
        cout << i << " ";
    }
    cout << endl;
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