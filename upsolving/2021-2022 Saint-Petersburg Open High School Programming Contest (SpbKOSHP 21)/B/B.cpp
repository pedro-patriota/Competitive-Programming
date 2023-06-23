#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, discovered = 0, i = 1, j = 1, s, l, r;
    cin >> n;
    set<pair<int, int>> impos;
    vector<ll> arr(n + 1);
    int max_3 = n / 3;

    for (int k = 0; k < max_3 * 3; k++)
    {
        if (k % 3 == 0)
        {
            printf("? %lld %lld\n", i, j);
            fflush(stdout);
            cin >> s >> l >> r;
            if (s == -1 && l == -1 && r == -1)
            {
                return 0;
            }
            impos.insert(make_pair(l, r));
            arr[i] = s;
            i += 2;
            j += 2;
        }
        else if (k % 3 == 1)
        {
            printf("? %lld %lld\n", i, j);
            fflush(stdout);
            cin >> s >> l >> r;
            if (s == -1 && l == -1 && r == -1)
            {
                return 0;
            }
            impos.insert(make_pair(l, r));
            arr[i] = s;
            i -= 2;
        }
        else
        {
            printf("? %lld %lld\n", i, j);
            fflush(stdout);
            cin >> s >> l >> r;
            if (s == -1 && l == -1 && r == -1)
            {
                return 0;
            }
            impos.insert(make_pair(l, r));
            arr[i + 1] = s - arr[i] - arr[j];
            i += 3;
            j += 1;
        }
    }
    if (n - max_3 * 3 >= 1)
    {
        printf("? %lld %lld\n", i, j);
        fflush(stdout);
        cin >> s >> l >> r;
        if (s == -1 && l == -1 && r == -1)
        {
            return 0;
        }
        impos.insert(make_pair(l, r));
        arr[i] = s;
        j += 1;
    }
    if (n - max_3 * 3 >= 2)
    {
        printf("? %lld %lld\n", i, j);
        fflush(stdout);
        cin >> s >> l >> r;
        if (s == -1 && l == -1 && r == -1)
        {
            return 0;
        }
        impos.insert(make_pair(l, r));
        arr[i + 1] = s - arr[i];
    }
    printf("!\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}