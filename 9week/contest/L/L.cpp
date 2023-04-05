#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll N, M;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<ll> request(N);
    vector<ll> tins(M);
    ll val;
    for (ll i = 0; i < N; i++){
        cin >> request[i];
    }
    for (ll i = 0; i < M; i++){
        cin >> tins[i];
    }
    sort(request.begin(), request.end());
    sort(tins.begin(), tins.end());
    ll count = 0;
    /* if (*tins.begin() >= *request.end()){
        count =  min(tins.size(), request.size());
        cout << count;
        return 0;
    } */

    auto init  = tins.begin();
    for (auto it : request){
        auto lb = lower_bound(init, tins.end(), it);
        if (lb != tins.end()){
            count ++;
            init = ++lb;
        }else{
            break;
        }
    }
    cout << count;
    return 0;
    
    
}