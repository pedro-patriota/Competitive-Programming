#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

int test (int n, vector<bool>& s){
    vector<int> arr = {0};
    for (int i = 1; i <= n; i++){
        arr.push_back(i);
    }
    int ans = 0;
    while (arr[0] == 0){
        bool isPos = true;
        for (int i = 1; i < arr.size() - 1; i++){
            if (arr[i] > arr[i + 1] && not s[i]){
                isPos = false;
                break;
            }
        }
        if (isPos) ans++;
        next_permutation(arr.begin(), arr.end());
    }

    return ans;
}

void solve(){
    int n, sz;
    cin >> n >> sz;
    vector<bool> s (n + 7);
    for (int i = 0; i < sz; i++){
        int idx; cin >> idx;
        s[idx] = true;
    }
    cout << test(n, s) << endl;
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