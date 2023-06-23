#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
int n, k;
const ll ms = 500 + 17;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<double> arr(2*n);
    ll comb[ms][ms];
  
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    comb[0][0] = 1;
    for (int i = 1; i <= n; i++){
        comb[i][0] = 0;
        for (int j = 1;  j <= i; j++){
            comb[i][j] = comb[i-1][j-1] + comb[i - 1][j];
        } 
    }

    for (int i = n; i < 2*n; i++)
    {
        ld ans = 0, sum = 0;
        if (k == 1)
        {
            ans = (ld)(100) / (n);
        }
        else{
            for (int j = 0; j <= n - k; j++){
                sum += arr[i - j];
                ans += sum *( (ld)comb[n-2- j][k-2]/comb[n][k]);
            }
        }       
        cout << setprecision(20) << ans << " ";
    }

    return 0;
}