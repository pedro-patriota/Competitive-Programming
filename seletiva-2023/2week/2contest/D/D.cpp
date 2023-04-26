#include <bits/stdc++.h>

using namespace std;
long long m, b, aux, a1, aN, sum, lar;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    cin >> b;
    lar = 0;
    aux = m;
    for (int y = b; y >= 0; y--){
        aux = m*(b - y);
        a1 = ((aux + 1)*(aux))/2;
        aN = y*(aux+1) + a1;
        sum = ((a1 + aN)*(y+1))/2;
        if (sum > lar){
            lar = sum;
        }
        
    }
    cout << lar;
    
}