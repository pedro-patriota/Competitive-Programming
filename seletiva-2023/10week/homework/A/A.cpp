#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int MAX_VAL = 2e6 + 12;

int trie[MAX_VAL][2], qnt[MAX_VAL], z, test_cases, N, K, v;
ll prefXOR, ans;

void init()
{
    memset(trie[0], -1, sizeof(trie[0]));
    memset(qnt, 0, sizeof(qnt));
    z = 1;
}
void insert(int val)
{
    int cur = 0;
    for (int i = 31; i >= 0; i--)
    {
        bool bit = val & (1 << i);
        if (trie[cur][bit] == -1)
        {
            memset(trie[z], -1, sizeof(trie[z]));
            trie[cur][bit] = z++;
        }
        cur = trie[cur][bit];
        qnt[cur]++;
    }
}

ll query(int val, int K)
{
    ll cur = 0, res = 0;
    for (int i = 31; i >= 0; i--)
    {
        bool bit = val & (1 << i);
        bool bit_K = K & (1 << i);
        if (bit_K)
        {
            if (trie[cur][bit] != -1)
            {
                res += qnt[trie[cur][bit]];
            }
            cur = trie[cur][1 - bit];
        }
        else
        {
            cur = trie[cur][bit];
        }
        if (cur == -1)
        {
            return res;
        }
    }
    return res;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> N >> K;
        init();
        insert(0);
        ans = prefXOR = 0;

        for (int val = 0; val < N; val++)
        {
            cin >> v;
            prefXOR ^= v;
            ans += query(prefXOR, K);
            insert(prefXOR);
        }
        cout << ans << endl;
    }

    return 0;
}