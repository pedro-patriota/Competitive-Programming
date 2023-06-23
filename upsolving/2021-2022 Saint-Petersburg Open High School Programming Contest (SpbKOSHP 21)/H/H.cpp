#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, k;
    cin >> a >> b;
    vector<pair<ll, ll>> actions;
    while (a != 0 && b != 0){
        if (abs(a) > 1e18 || abs(b) >1e18){
            return -1;
        }
        ll val = max(abs(a), abs(b));
        if (val == abs(a)){
            k = abs(a/b);
            if ((a > 0 && b > 0) || (a < 0 && b < 0)){
                a = a - k*b;
                actions.push_back(make_pair(1, -k));
            }else if ((a < 0 && b > 0) || (a > 0 && b < 0)){
                a = a + k*b;
                actions.push_back(make_pair(1, k));
            }
        }else{
            k = abs(b/a);
            if ((a > 0 && b > 0) || (a < 0 && b < 0)){
                b = b - k*a;
                actions.push_back(make_pair(2, -k));
            }else if ((b < 0 && a > 0) || (b > 0 && a < 0)){
                b = b + k*a;
                actions.push_back(make_pair(2, k));
            }
        }
    }
    cout << actions.size() << endl;
    for (auto val : actions){
        cout << val.first << " " << val.second << endl;
    }
    return 0;
    
}