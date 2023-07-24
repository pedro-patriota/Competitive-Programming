#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    ll x, y, lap = 1;
    cin >> x >> y;
    double restY = (double) (lap*x)/y;
    //cout << restY << endl;
    while(lap - restY < 1){
        lap++;
        restY = (double) (lap*x)/y;
    }
    cout << lap << endl;
    
        
    return 0;
    
}