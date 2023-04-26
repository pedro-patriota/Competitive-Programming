#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, val, ans, res, ans_begin, ans_end, pref;
vector<ll> prefXOR;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    

    pref =0, ans = 0;
    ans_begin = ans_end = 1e10;
    prefXOR.push_back(0);
    for (ll i = 0; i < n; i++)
    {
        cin >> val;
        pref ^= val;
        for (ll j = 0; j < prefXOR.size(); j++)
        {
            res = prefXOR[j] ^ pref;
            if (res > ans || (res == ans && j+1 < ans_begin || (j+1 == ans_begin && i+1 < ans_end)))
            {
                ans = res;
                ans_begin = j+1;
                ans_end = i+1;
            }
        }
        prefXOR.push_back(pref);
    }
    cout << ans << endl;
    cout << ans_begin<<" "<<ans_end;

    return 0;
}