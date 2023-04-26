#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num, ans;



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll num_input;
    cin >> num_input;
    for (ll i = 0; i < num_input; i++){
        cin >> num;
        ans = 0;
        while (num >= 5)
        {
            num /= 5;
            ans += num;
        }
        cout << ans << "\n";
        
    }
    
    
    
}