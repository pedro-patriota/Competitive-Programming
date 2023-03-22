#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll test_cases, l, r, a, m, maxV;
bool is_possible()
{
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (ll test = 0; test < test_cases; test++)
    {
        cin >> l >> r >> a;
        ll max_div = r / a;
        ll max_rest = a - 1;
        if (r <= max_rest)
        {
            maxV = r;
        }
        else
        {
            if (max_div * a + max_rest <= r)
            {
                maxV = max_div * a + max_rest;
            }
            else{
                maxV = (max_div-1)*a + max_rest;
            }
            if (maxV < l){
                maxV = r;
            }
        }
        cout << ((maxV/a) + maxV%a) << "\n";
    }
}