#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll w, h, hi;
vector<ll> arrH;
const ll inf = LLONG_MAX;

bool isPos(ll height)
{
    // if (width < 2 && height < 2) return 0;
    if (height % 2 == 1)
        return false;

    return true;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    arrH = vector<ll>(w);
    hi = 1e18;
    for (ll i = 0; i < w; i++)
    {
        cin >> arrH[i];
        hi = min(hi, arrH[i]);
        if (arrH[i] > h)
        {
            cout << "impossible" << endl;
            return 0;
        }
    }
    if (hi == h)
    {
        cout << "possible" << endl;
        return 0;
    }
    ll lwBrickHeight = 0;
    for (int i = 0; i < w; i++)
    {
        ll height = arrH[i];
        ll toBeFilled = h - height - lwBrickHeight;

        if (toBeFilled <= 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
        if (not isPos(toBeFilled))
        {
             lwBrickHeight++;
        }
        else
        {
            lwBrickHeight = max((ll)0, lwBrickHeight - 1);
        }
    }
    cout << "possible" << endl;
    return 0;

    /* } */

    return 0;
}