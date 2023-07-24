#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Rabin Karp
class RabinKarp
{
public:
    ll base, mod, sz;
    string s;
    vector<ll> pot, has;
    RabinKarp(const string &str, ll b = 997, ll m = 1e9 + 7)
        : base(b), mod(m), s(str)
    {
        sz = str.length();
        pot.resize(sz + 1);
        has.resize(sz + 1);
        build();
    }
    void build()
    {
        pot[0] = 1;
        has[0] = s[0];
        for (int i = 1; i < sz; i++)
        {
            pot[i] = (pot[i - 1] * base) % mod;
            has[i] = ((has[i - 1] * base) + s[i]) % mod;
        }
    }
    ll getKey(ll l, ll r)
    { // inclusivo
        ll ans = has[r];
        if (l > 0)
            ans = (((ans - pot[r - l + 1] * has[l - 1]) % mod + mod) % mod);
        return ans;
    }
};
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll sz = s.size();
    stack<int> balanced;
    ll left, right;
    RabinKarp sHash(s);

    ll key;
    map<ll, pair<ll, ll>> patterns;
    vector<ll> vectS;
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(')
        {
            if (balanced.size() == 0)
                left = i;
            balanced.push(0);
        }
        else
        {
            balanced.pop();
            if (balanced.size() == 0)
            {
                right = i;
                key = sHash.getKey(left, right);
                //cout << key << " " <<  left << " " << right << endl;
                patterns[key] = make_pair(left, right);
                vectS.push_back(key);
            }
        }
    }

    string newS = "";
    if (patterns.size() == 1)
        cout << "no" << endl;
    else
    {
        int newI = 0;
        for (int i = 0; i < vectS.size(); i++)
        {
            if (i - 1 < 0){
                newI = vectS.size() - 1;
            }else{
                newI = i - 1;
            }
            key = vectS[newI];
            auto [l, r] = patterns[key];
            //out <<  key<< " " << l << " " << r << endl;
            for (int chr = l; chr <= r; chr++)
            {
                newS += s[chr];
            }
        }

        cout << newS;
    }

    return 0;
}