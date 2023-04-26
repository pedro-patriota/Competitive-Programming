#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll coins, obj, temp, rest;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> coins >> obj;
    vector<int> arr(coins);
    vector<int> dp(coins + 1);
    dp[0] = INT_MAX;
    for (ll i = 0; i < coins; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (ll i = 1; i <= coins; i++)
    {
        temp = 0;
        temp += obj / arr[i - 1];
        rest = obj - temp * arr[i - 1];

        while (rest != 0)
        {
            auto it = lower_bound(arr.begin(), arr.end(), rest);
            if ((*it != rest))
            {
                if (it == arr.begin())
                {
                    break;
                }
                it--;
            }
            temp += rest / (*it);
            rest = rest - (rest / (*it)) * (*it);
        }

        if (rest == 0)
        {
            dp[i] = min((ll)dp[i - 1], temp);
        }
        else
        {
            dp[i] = INT_MAX;
        }
    }
    if (dp[coins] != INT_MAX)
    {
        cout << dp[coins];
    }
    else
    {
        cout << -1;
    }
}