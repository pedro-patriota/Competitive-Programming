#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll p1, p2;
    cin >> p1 >> p2;
    if (p1 == p2){
        cout << "infinity" << endl;
    }

    ll relative_val = p1 - p2;
    vector<ll> prime_numbers;
    map<ll, ll> prime_map;
    
    while (relative_val % 2 == 0){
        prime_map[2]++;
        relative_val /= 2;
    }
    for (int i = 3; i< sqrt(relative_val); i+=2){
        while (relative_val % i == 0 && p1%i == p2){

            prime_map[i]++;
            relative_val /= i;
        }
    }
    if (relative_val > 2){
        prime_map[relative_val]++;
    }

    ll ans = 1;
    for (auto val : prime_map){
        ans *= (val.second + 1);
    }
    cout << ans;

    
    
}