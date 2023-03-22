#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll limit = 1e9 + 7;
const ll m = 2;

void matrixMulti(vector<vector<ll>> matrix, vector<vector<ll>> p , vector<vector<ll>>& result){
    for (ll i = 0; i < m; i++){
        for (ll j = 0; j < m; j++){
            for (ll k = result[i][j] = 0; k < m; k++){
                result[i][j] = (result[i][j] +  (matrix[i][k]*p[k][j])%limit)%limit;
                result[i][j] = result[i][j];
            }
        }
    }
}
void matrixPow (vector<vector<ll>> matrix, ll b, vector<vector<ll>>& ans){
    
    for (ll i = 0; i < m; i++){
        ans[i][i] = 1;
    }
    while(b){
        if (b&1) matrixMulti(ans, matrix, ans);
        matrixMulti(matrix, matrix, matrix);
        b >>= 1;
    }

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll fibo;
    vector<vector<ll>> Z = {{1,1}, {1, 0}};
    vector<vector<ll>> result(m, vector<ll>(m));
    cin >> fibo;
    if (fibo == 0){
        cout << 0;
        return 0;
    }
    if (fibo == 1){
        cout << 1;
        return 0;
    } // this fibo starts with F0
    matrixPow(Z, fibo -1, result);
    cout << result[0][0]*1 + result[0][0]*0;

    
}