#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num_Val, val;
vector<ll> arr;
multiset <ll> aux_arr;
ll recur(multiset<ll> temp)
{

    if (temp.size() == 1)
    {
        return *temp.begin();
    }
    else
    {
        multiset<ll> gdc_arr;
        for (auto it = temp.begin(); it != temp.end(); it++){
            auto aux = it;
            aux++;
            if (aux == temp.end()){
                auto past = it;
                past--;
                gdc_arr.insert(__gcd(*it, *past));
            }else{
                gdc_arr.insert(__gcd(*it, *aux));
                it++;
            }
        }
        return recur(gdc_arr);
    }
}

ll solve()
{
    ll max = 0;
    for (ll i = 0; i < num_Val; i++)
    {
        auto aux = arr[i];
        aux_arr.erase(aux_arr.find(aux));
        ll max_gdc = recur(aux_arr);
        if (max_gdc > max){
            max = max_gdc;
        }
        aux_arr.insert(aux);
    }
    return max;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_Val;
    arr = vector<ll>(num_Val);
    for (ll i = 0; i < num_Val; i++)
    {
        cin >> arr[i];
        aux_arr.insert(arr[i]);
    }
    ll ans = solve();
    cout << ans;

}