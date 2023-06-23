#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll test_cases, x, y, top, div;
    cin >> test_cases;
    for (ll i = 0; i < test_cases; i++)
    {
        vector<ll> rest;
        top = 0;
        cin >> x >> y;
        if (x == y)
        {
            rest.push_back(0);
            rest.push_back(1);
        }
        else
        {
            while (true)
            {
                div = x / y;
                rest.push_back(div);
                if (top == 1)
                {
                    break;
                }
                top = x - div * y;
                x = y;
                y = top;
            }
        }
        cout << rest.size() - 1;
        for (auto val : rest)
        {
            cout << " " << val;
        }
        cout << endl;
    }

    return 0;
}