#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll max_val = 1e11 + 5;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll A, B;
    vector<ll> sqrt_val;
    vector<ll> interesting;
    for (ll i = 1; i*i< max_val; i++){
        if (i*i % 10 != 0){
            sqrt_val.push_back(i*i);
        }
    }
    for (auto val : sqrt_val){
        string to_str = to_string(val);
        string new_to_str = "";
        for (int i = to_str.size() -1; i >=0; i-- ){
            new_to_str += to_str[i];
        }
        ll new_val = stoll(new_to_str);
        if (binary_search(sqrt_val.begin(), sqrt_val.end(), new_val)){
            interesting.push_back(val);
        }
    }
    cin >> A >> B;
    auto low = lower_bound(interesting.begin(), interesting.end(), A);
    auto up = upper_bound(interesting.begin(), interesting.end(), B);
    cout << up - low;
    
        
    return 0;
    
}