#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num_input, n, Mod;
const ll m = 3;

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

    cin >> num_input;
    for (ll i = 0; i < num_input; i++){
        cin >> n;
        cin >> Mod;
        ll sum = ((1 + n-1)*(n-1))/2;
        ll ans;
        vector<vector<ll>> Z = {{1, 1, sum}, {1, 0 , 0}, {0, 1, 0}};
        vector<vector<ll>> result(m, vector<ll>(m));
        if (n == 0){
            ans = 0;
        }else if (n == 1){
            ans = 1;
        }else{
            matrixPow(Z, n - 1, result);
            ans = 1*Z[0][0] + 0*Z[0][1] + 1*Z[0][2];
        }
        cout << ans%Mod << "\n";

    }
        
    
    
}