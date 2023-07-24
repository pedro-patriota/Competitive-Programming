#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m, l, r, med;
vector<pair<ll, ll>> invest;
const ll ms = 2*1e9 + 17;

bool is_possible(ll days){
    ll sum = 0, perdDay, cost;

    for (int i  = 0 ; i <  n ; i ++){
        perdDay = invest[i].first;
        cost = invest[i].second;

        if (days*perdDay < cost){
            continue;
        }else{
            sum += days*perdDay - cost;
        }

        if (sum >= m){
            return true;
        }
        
    }
    return false;

}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll perDay, cost;
    cin >> n >> m;
    invest = vector<pair<ll, ll>>(n);
    for (int i = 0; i < n ; i ++){
        cin >> perDay >> cost;
        invest[i].first = perDay;
        invest[i].second = cost;

    }
    l = 0;
    r = ms;
    while (l < r ){
        ll med = (l + r)/2;

        if (is_possible(med)){
            r = med;
        }else{
            l = med + 1;
        }
    }
    cout << l;
        
    return 0;
    
}