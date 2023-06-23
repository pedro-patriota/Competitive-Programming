#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll LIM = 2e7 + 17;
bool is_prime[LIM];

vector<ll> sieve(){
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    vector<ll> primes;
    for (ll i = 2; i < LIM; i++){
        if (is_prime[i]){
            primes.push_back(i);
            for (ll j = i*2; j < LIM; j += i){
                is_prime[j] = false;
            }
        }
    }

    return primes;
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> prime_arr = sieve();
    ll n, p, ans = 0, max_size = 0;
    cin >> n;
    vector<ll> input (n);
    for (ll i = 0; i < n; i++){
        cin >> input[i];
    }
    if (n == 1){
        bool found = binary_search(prime_arr.begin(), prime_arr.end(), input[0]);
        if (found){
            cout << 0;
        }else{
            cout << 1;
        }
        return 0;
    }
    if (n == 2){
        bool found = binary_search(prime_arr.begin(), prime_arr.end(), input[0]);
        bool found1 = binary_search(prime_arr.begin(), prime_arr.end(), input[1]);
        if (not found1 || not found){
            max_size = 1;
        }
    }
    for (ll i = 0; i < n; i++){
        ans = 0;
        for (ll j = i + 1; j < n; j++){
            p = input[i] + input[j];
            bool found = binary_search(prime_arr.begin(), prime_arr.end(), p);
            if (not found){
                ans++;
            }
        }
        if (ans > max_size){
            max_size = ans + 1;
        }
        
    }
    cout << max_size;

    return 0;
    
}