#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
#define PB push_back

const int ms = 1e6 + 17;
bool multiTest = false;
ii poolHeight[ms];

void solve(){
    int n, ans = 0;
    cin >> n;
    int arr[n+7];
    for (int i = 0; i < n ; i ++){
        cin >> arr[i];
    }
    if (n < 3){
        cout << 0 << endl;
        return;
    }
    int parts = 0, left_peak = arr[0] > arr[1] ? arr[0] : 0, right_peak = 0, n_parts = 0;
    for (int i = 1; i < n -1; i++){

        int h = arr[i];
        int prev = arr[i-1];
        int next = arr[i+1];
        
        if (h > prev && h > next){
            auto [past_parts, past_n_parts] = poolHeight[h];
            if (left_peak == 0) {
                left_peak = h;
            }
            else {
                right_peak = h;
                
                parts -= past_parts;
                n_parts -= past_n_parts;

                ans = max(ans, n_parts*min(left_peak, right_peak) - parts);
                if (right_peak >= left_peak){
                    left_peak = right_peak;
                    parts = n_parts = right_peak = 0;
                }
            }
        }else if (left_peak > 0){
            parts += h;
            n_parts++;
        }
    }
    if (arr[n-1] > arr[n-2]) right_peak = arr[n-1];
    ans = max(ans, n_parts*min(left_peak, right_peak) - parts);

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