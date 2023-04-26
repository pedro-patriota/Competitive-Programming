#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int MAX_VAL = 4e6 + 12;

int trie[MAX_VAL][2], qnt[MAX_VAL], z, operations;
ll N;
char op;
ll prefXOR, ans;

void init()
{
    memset(trie[0], -1, sizeof(trie[0]));
    memset(qnt, 0, sizeof(qnt));
    z = 1;
}
void insert(ll val)
{
    ll cur = 0;
    for (int i = 35; i >= 0; i--)
    {
        bool bit = val & (1ULL << i);
        if (trie[cur][bit] == -1)
        {
            memset(trie[z], -1, sizeof(trie[z]));
            trie[cur][bit] = z++;
        }
        cur = trie[cur][bit];
        qnt[cur]++;
    }
    return;
}
void remove(ll val)
{
    ll cur = 0;
    for (int i = 35; i >= 0; i--)
    {
        bool bit = val & (1ULL << i);
        auto copy_cur = cur;
        cur = trie[cur][bit];
        qnt[cur]--;
        if (qnt[cur] == 0)
        {
            trie[copy_cur][bit] = -1;
            //memset(trie[local_Z], -1, sizeof(trie[local_Z]));
        }
    }
    return;
}

ll query(ll val)
{
    ll cur = 0, res = 0;
    for (int i = 35; i >= 0; i--)
    {
        bool bit = val & (1ULL << i);
        
        //cout << " " << 1-bit <<(1<<i) << "-"<<cur << " ";
        if (trie[cur][1-bit] != -1)
        {
            res += (1ULL <<i);
            cur = trie[cur][1 - bit];
        }
        else{
            cur = trie[cur][bit];
        }
    }
    return res;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> operations;
    init();
    for (int i = 0; i < operations; i++)
    {
        cin >> op >> N ;
        
        if (op == '+')
        {
            insert(N);
        }
        else if (op == '-')
        {
            remove(N);
        }
        else
        {
            ll ans = query(N);
            cout << ans << endl;
        }

    }

    return 0;
}