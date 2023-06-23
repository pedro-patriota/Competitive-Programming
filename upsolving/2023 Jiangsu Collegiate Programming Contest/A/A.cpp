#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll counter = 0;
string tester(string n, ll m){
    string begin, mid, end;
    begin = n.substr(0, n.size()/2);
    mid = n;
    end = n.substr(n.size()/2, n.size());
    for (ll i = 0; i < end.size(); i++){
        end[i] = (end[i] - 'a' + 1)%26 + 'a';
    }
    counter ++;
    //cout << counter << " " << end.substr(max((ll) 0, (ll) end.size() - 52), end.size()) << endl;
    string res = begin + mid + end;
    if (res.size()/2 > m){
       /*  cout << res.size()/2 << " " << counter << endl;
        cout << endl;
        cout << res.substr(res.size()/2, res.size()) << endl << endl << endl; */
        return res;
    }
    
    return tester(res, m);
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    string input, res;
    cin >> n >> m;
    cin >> input;
    res = tester(input, m);
    res = res.substr(res.size() - m, res.size());
    
    for (ll i = 0; i < res.size(); i++){
        res[i] = (res[i] - 'a' + (16 - counter))%26 + 'a';
    }
    cout << res;
        
    return 0;
    
}