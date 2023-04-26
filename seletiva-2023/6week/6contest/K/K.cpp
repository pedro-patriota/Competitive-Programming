#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sticks;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> sticks;
        if (not sticks)
        {
            break;
        }
        vector<ll> arr(sticks);
        for (ll i = 0; i < sticks; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll aux, counter = 0;
        auto last = arr.end();
        last--;
        last--;
        auto next_last = arr.end();
        next_last--;
        for (auto itr = arr.begin(); itr != last; ++itr)
        {
            for (auto next_itr = itr + 1; next_itr != next_last; ++next_itr)
            {
                aux = *itr + *next_itr;
                auto p2 = upper_bound(next_itr, arr.end(), aux);
                if (p2 != arr.end())
                {
                    auto last_pos = arr.end();
                    
                    counter += last_pos - p2;
                }
            }
        }
        cout << counter << "\n";
    }
}