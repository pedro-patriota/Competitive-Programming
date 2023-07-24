#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll n, counter = 0, a = 0;
    string s;
    cin >> n;
    cin >> s;
    bool alternate = true;

    for (int i = 0; i < n; i++){
        if (s[i] == 'a'){
            a++;
        }else{
            if (a > 1){
                counter += a;
                //cout << i << " " << a << endl;
            }
            a = 0;
            alternate = true;
        }
    }
    if (a > 1){
        counter +=  a;
    }
    cout << counter;
    
        
    return 0;
    
}