#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second
vector<ll> arr;
vector<vector<ll>> digits;
map<ll, map<int, int>> a;
int n;
//int mostUsed = 0;

void calc (ll num){
    ll copy = num;
    while (num > 0){
        int digit = num%10;
        digits[digit].push_back(copy);
        a[copy][digit]++;

        num /= 10; 
    }
}

ll best = 0;
ll isPos (map<int, int> freq, vector<int>& choosen, int i, int mostUsed, ll temp){
    if (i >= choosen.size()) return temp;
    if (mostUsed > 2) return 0;
    int digit = choosen[i];
    for (auto val :  digits[digit]){
        int mx = 0;
        for (auto [d,f] : a[val]){
            freq[d] += f;
            mx = max(mx, freq[d]);
        }
        best = max(best, isPos(freq, choosen, i + 1, max(mostUsed, mx), temp + val));
        for (auto [d,f] : a[val]){
            freq[d] -= f;
        }
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr = vector<ll>(n);
        digits = vector<vector<ll>>(10);
        a = map<ll, map<int, int>>();
        
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            calc(arr[i]);
        }
        
        best = 0;
        for (int i = 0; i < (1 << 10); i++){
            vector<int> choosen;
            map<int, int> freq;
            for (int digit = 0; digit < 10; digit++){
                bool indicator = (i >> digit) & 1;
                if (indicator) choosen.push_back(digit);                
            }
            isPos({}, choosen, 0, 0, (ll) 0);
        }

        cout << best << endl;
    }
    

    return 0;
}