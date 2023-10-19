#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;
const int ms = 1e3 + 7;
int n;
char arr [ms][ms];

ll check(int square){
    vector<char> l1, l2, l3, l4;
    int zero = 0 + square;
    int end = n - 1 -square;
    ll ans = 0;
    char mx = 'a';
    mx = max(arr[zero][zero], mx);
    mx = max(arr[zero][end], mx);
    mx = max(arr[end][zero], mx);
    mx = max(arr[end][end], mx);

    ans += mx - arr[zero][zero];
    ans += mx - arr[zero][end];
    ans += mx - arr[end][zero];
    ans += mx - arr[end][end];

    vector<char> mxL (end - zero + 7, 'a');
    int pos = 0;
    for (int i = zero + 1; i < end; i++){
        mxL[pos] = max(mxL[pos], arr[i][zero]);
        pos ++;
    }
    pos = 0;
    for (int i = zero + 1; i < end; i++){
        mxL[pos] = max(mxL[pos], arr[end][i]);
        pos ++;
    }
    // ---------------------
    pos = 0;
    for (int i = end - 1; i >= zero + 1; i--){
        mxL[pos] = max(mxL[pos], arr[i][end]);
        pos ++;
    }
    pos = 0;
    for (int i = end - 1; i >= zero + 1; i--){
        mxL[pos] = max(mxL[pos], arr[zero][i]);
        pos ++;
    }

    // #########################
    pos = 0;
    for (int i = zero + 1; i < end; i++){
        ans += (mxL[pos] - arr[i][zero]);
        pos ++;
    }
    pos = 0;
    for (int i = zero + 1; i < end; i++){
         ans += (mxL[pos] - arr[end][i]);
        pos ++;
    }
    // ---------------------
    pos = 0;
    for (int i = end - 1; i >= zero + 1; i--){
         ans += (mxL[pos] - arr[i][end]);
        pos ++;
    }
    pos = 0;
    for (int i = end - 1; i >= zero + 1; i--){
        ans += (mxL[pos] - arr[zero][i]);
        pos ++;
    }

    return ans;

    
}

void solve(){
    cin >> n;
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n; j++){
            char a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    ll ans = 0;
    for (int square = 0; square < n/2; square++){
        ans += check(square);
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