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
    int a, b;
    cin >> a >> b;
    if (abs(a - b)%2 == 0){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
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