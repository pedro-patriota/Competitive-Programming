#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll MAX_VAL = 1e9 + 7;
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    string S, W;
    cin >> S >> W;
    vector<ll> counterW;
    vector<char> counterCharW;

    vector<ll> counterS;
    vector<char> counterCharS;

    counterCharW.push_back(W[0]);
    set<char> count_letters;
    count_letters.insert(W[0]);

    ll aux = 0;

    for (ll i = 1; i < W.size(); i++)
    {
        if (W[i] == W[i - 1])
        {
        }
        else
        {
            count_letters.insert(W[i]);
        }
        counterCharW.push_back(W[i]);
    }

    aux = 0;
    for (ll i = 0; i < S.size(); i++)
    {
        if (not count_letters.count(S[i]))
            continue;

        counterCharS.push_back(S[i]);
        counterS.push_back(1);
    }

    ll Wsize = counterCharW.size();
    ll Ssize = counterCharS.size();
    ll ans = 0;
    vector<vector<ll>> table_dp(Ssize + 1, vector<ll>(Wsize));
    auto last_letter = counterCharW[Wsize - 1];
    for (ll i = Ssize - 1; i >= 0; i--)
    {
        if (counterCharS[i] == last_letter)
        {
            table_dp[i][0] = table_dp[i + 1][0] + counterS[i];
        }
        else
        {
            table_dp[i][0] = table_dp[i + 1][0];
        }
    }
    for (ll j = 1; j < Wsize; j++)
    {
        for (ll i = Ssize - 1; i >= 0; i--)
        {
            if (counterCharS[i] == counterCharW[Wsize - 1 - j])
            {
                table_dp[i][j] = (table_dp[i + 1][j] + counterS[i] * table_dp[i + 1][j - 1])% MAX_VAL;
            }
            else
            {
                table_dp[i][j] = table_dp[i + 1][j];
            }
        }
    }

    ans = table_dp[0][Wsize - 1] % MAX_VAL;
    cout << ans;

    return 0;
}