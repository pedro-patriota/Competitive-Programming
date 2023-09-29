#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
const int mod = 1e9 + 7;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > r) {
            cout << 0 << endl;
            return 0;
        }
    }
    int past = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > past){
            for (int j = i; j >= 0; j--){
                arr[j] = arr[i];
            }
        }
        past = arr[i];
    }
    int ans = 1;
    for (int i = 0; i < n; i++){
        int rest = r - arr[i] + 1;
        ans = (ans*rest)%mod;
    }
    cout << ans << endl;
    
        
    return 0;
    
}