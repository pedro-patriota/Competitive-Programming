#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, max_rooks, x = 0, y = 0;
    cin >> n >> m >> k;
    max_rooks = min (n, m);
    if (k > max_rooks){
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j != i || k == 0){
                cout << ".";
            }
            else{
                cout << "*";
                k--;
            } 
        }
        cout << endl;
    }
        
    return 0;
    
}