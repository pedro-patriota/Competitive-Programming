#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    ld p, q;
    cin >> a >> b >> p >> q;
    vector<ld> dp(a+1);
    dp[0] = 0;
    p /= 100;
    q /= 100;
    if (b == 1){
        ld chooseP = 0, chooseQ = 0;
        chooseP = (ld) a*(1 + p);
        chooseQ =  (ld)a *(1 + q/(1-q));
        cout << setprecision(20) << max(chooseP, chooseQ);
        return  0;
    }

    for (int i = 1; i <= a; i++){
        ld chooseP = 0, chooseQ = 0;
        if (i - b < 0){
            dp[i] = 0;
            continue;
        }
        chooseQ += (ld) (1-q)*(1 + dp[i - b]);
        chooseP = (ld) p*(2 + dp[i - b]) + (1-p)*(dp[i - b] + 1);
        //cout << i  << " " << dp[i] << " " << chooseP << " " << chooseQ << endl;
        chooseQ += (ld) (q)*(1 + dp[i - b + 1]);
            
        
        dp[i] = (ld) max((ld) chooseP, (ld)chooseQ);
        //cout << i  << " " << dp[i] << " " << chooseP << " " << chooseQ << endl;
    }
    cout << setprecision(20) <<dp[a];

    return 0;
    
}