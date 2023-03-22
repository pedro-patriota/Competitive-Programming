#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>primes;
vector<ll>primesTo2;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    vector<bool>is_prime(1e6, true);
    int num_cases;
    cin >> num_cases;

    for (ll i = 2; i*i < 1e12; i++){
        if (is_prime[i]){
            primes.push_back(i);
            for (ll j = i*2; j < 1e6; j += i){
                is_prime[j] = false;
            }
        }
    }
    for (auto it : primes){
        ll val = it;
        val *= val;
        while (val < 1e12){
            primesTo2.push_back(val);
            val *= it;
        }
    }
    sort(primesTo2.begin(), primesTo2.end());
    ll init, end, copy_end;
    for (int test = 0 ; test < num_cases; test++){
        cin >> init >> end;
        ll counter = upper_bound(primesTo2.begin(), primesTo2.end(), end) - upper_bound(primesTo2.begin(), primesTo2.end(), init -1);
        
        cout << counter << "\n";
    }
    
    
}