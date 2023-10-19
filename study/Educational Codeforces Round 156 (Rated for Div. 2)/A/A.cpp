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
    int a = 1, b = 2;
    if (n <= 6){
        cout << "NO" << endl;
        return;
    }

    n -= 3;
    if ( (n - 3)%3 == 0){
        if (n - 2 == a || n - 2 == b + 2){
            cout << "NO" << endl;
            return;
        }
        b += 2;
        n -= 2;
    }
    cout << "YES" << endl;
    cout << a << " " << b << " " << n << endl;

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