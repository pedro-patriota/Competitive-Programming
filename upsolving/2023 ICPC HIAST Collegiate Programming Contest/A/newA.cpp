#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

vector<vector<ll>> dp;
vector<vector<int>> digits;
vector<ll> pow3 (14);

bool calc(ll num, vector<int> &digits)
{
    while (num > 0)
    {
        int digit = num % 10;
        digits[digit]++;
        if (digits[digit] > 2) return false;
        num /= 10;
    }
    return true;
}
int getBit(int i, int bitmask){
    return (bitmask/pow3[i])%3;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    ll w;
    cin >> t;
    pow3[0] = 1;
    for (int i = 1; i < 11; i++){
        pow3[i] = 3*pow3[i-1];
    }
    while (t--)
    {
        cin >> n;
        vector<ll> arr(n + 7);
        digits = vector<vector<int>> (n + 7, vector<int>(10));
        dp = vector<vector<ll>> (n +7, vector<ll>(pow3[10], 0));

        for (int i = 0; i < n; i++) {
            cin >> w;
            if (calc(w, digits[i])){
                arr[i] = w;
            }else{
                arr[i] = -1;
            }
            
        }

        for (int bitmask = 0; bitmask < pow3[10]; bitmask++){
            for (int i = 0; i < n; i++){
                dp[i + 1][bitmask] = max(dp[i+1][bitmask], dp[i][bitmask]);
                if (arr[i] == -1) continue;
                int newMask = bitmask; bool isPos = true;
                for (int d = 0; d < 10; d++){
                    if (getBit(d, newMask) + digits[i][d] > 2){
                        isPos = false;
                        break;
                    }
                    newMask += digits[i][d]*pow3[d];
                }
                if (not isPos) continue;
                dp[i+1][newMask] = max(dp[i+1][newMask], dp[i][bitmask] + arr[i]);
            }
        }
        ll sum = 0;
        for (int bitmask = 0; bitmask < pow3[10]; bitmask++){
            sum = max(sum, dp[n][bitmask]);
        } 
        cout << sum << endl;
    }
    
    return 0;
}

