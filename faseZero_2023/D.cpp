#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll input;
    cin >> input;
    cout << input << endl;
    while (input >= 10){
        ll a  = input/10;
        ll b = input - a*10;

        input = a*3 + b;
        cout << input << endl;
    }
        
    return 0;
    
}