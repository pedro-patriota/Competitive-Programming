#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

bool multiTest = true;

int sumDigits(int x)
{
    int sum = 0, cp = x;
    while (cp > 0)
    {
        sum += cp % 10;
        cp = cp / 10;
    }
    return sum;
}

void solve()
{

    int x, k, sum;
    cin >> x >> k;

    sum = sumDigits(x);
    while (sum % k != 0)
    {
        x++;
        sum = sumDigits(x);
    }
    cout << x << endl;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    if (multiTest)
        cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}