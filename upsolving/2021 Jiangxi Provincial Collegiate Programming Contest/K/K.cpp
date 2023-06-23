#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int ttest_cases;
    ll N, M;
    for (int j = 0; j < ttest_cases; j++)
    {
        cin >> N >> M;
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans += (i + 1) * (i + 1) * M;
        }
        cout << ans << endl;
    }

    return 0;
}