#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxD = 1e12 + 5;
vector<ll> getDivisors(ll num)
{
    vector<ll> divisors;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
            if (i * i != num)
            {
                divisors.push_back(num / i);
            }
        }
    }
    return divisors;
}

int main()
{
    ll ans, rest, aux, sol;
    ios ::sync_with_stdio(0);
    cin.tie(0);

    printf("? %lld\n", maxD);
    fflush(stdout);
    cin >> ans;

    rest = maxD - ans;
    ans =  (2*rest)-1;
    printf("? %lld\n", ans);
    fflush(stdout);
    cin >> aux;
    if (aux == rest - 1)
    {
        sol =  rest;
    }else{
        sol = aux + 1;
    }
    
    printf("! %lld\n", sol);
    fflush(stdout);
    

    return 0;
}