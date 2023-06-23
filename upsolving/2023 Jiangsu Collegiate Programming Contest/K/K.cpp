#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
set<string> resSet;
set<string> resStandard;
    ll n, m, k;
bool used = true;
vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void solve(ll m, string standard){
    if (resSet.size() >= n){
        return;
    }

    if (standard.size() == m+ 1){
        string reversed = standard;
        reverse(reversed.begin(), reversed.end());
        if (k > 2 &&  resStandard.count(reversed)){
            return;
        }
        string res = "";
        for (ll i = 0; i < k; i++){
            res += standard[i%standard.size()];
        }
        resSet.insert(res);
        resStandard.insert(standard);
        return;
    }

    for (int i = 0; i < alphabet.size(); i++){
        solve(m, standard + alphabet[i]);
    }
} 


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> m >> k;
    if (m >= k){
        cout << "No";
        return 0;
    }



    for (ll i = 0; i <= m; i++){
        resStandard = set<string>();

        if (resSet.size() >= n){
            used = false;
            break;
        }
        solve(i, "");
        
    }
    if (not used){
        auto it = resSet.end();
        it--;
        resSet.erase(it);
        solve(m, "");
    }
    if (resSet.size() < n){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (auto val : resSet){
        cout << val << endl;
    }
    
        
    return 0;
    
}