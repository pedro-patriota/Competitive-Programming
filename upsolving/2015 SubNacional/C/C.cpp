#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    
    int a, b;
    cin >> a >> b;
    if (a == b){
        cout << a;
    }else{
        cout << max(a, b);
    }
    cout << endl;
        
    return 0;
    
}