#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string input;
int sz, ans;

bool solve(ll m){
    if (input.length() % m != 0){
        return false;
    }
    ll cache = input.length() / m;
    for (int i = cache; i < input.length(); i++){
        auto a = input[i];
        auto b = input[i % cache];
        if (input[i] != input[i % cache]){
            return false;
        }
    }
    return true;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> input){
        if (input == "*"){
            break;
        }
        sz = input.length();
        ans = 1;
        vector<int> z_function (sz, 0);

        for (int i = 1, l = 0, r = 0; i < sz; i++){ // l = left, r = right and i = current
            if (i <= r) {
                z_function[i] = min(r - i + 1, z_function[i-l]);  // if i is in the range of r, then we can use the previous value of z_function[i]
            }
            while (z_function[i] + i < sz && input[z_function[i]] == input[z_function[i]+i] ) {
                z_function[i]++; 
            }
            if (i + z_function[i] - 1  > r) {
                l = i, r = i + z_function[i] -1;
            }
        }

        for (int i  = 1; i < sz; i++){
            if (z_function[i] >= i && i + z_function[i] == sz && z_function[i]%i == 0){
                ans = max(ans, sz/i);
                break;
            }
        }    
        cout << ans << endl;
        
    }
    
    
}