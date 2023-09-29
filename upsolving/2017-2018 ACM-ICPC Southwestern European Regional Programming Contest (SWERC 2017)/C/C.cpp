#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll mod = 1e9;
const int m = 256; // size of matrix

struct Matrix { 
  ll mat[m][m];
  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
        for(int k = ans.mat[i][j] = 0; k < m; k++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
    return ans;
  }
};

ll fibo [] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
ll n, columns;

Matrix mt;
void makeRelations(){

    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < (1 << n ); j++){
            ll numberWays = 1;
            int consectiveZeros = 0;
            for (int digit = 0; digit < n; digit++){
            
                bool iDigit = (i >> digit) & 1;
                bool jDigit =  (j >> digit) & 1;

                    if (iDigit & jDigit) {
                    numberWays = 0;
                    break;
                }
                if (iDigit) {
                    numberWays *= fibo[consectiveZeros];
                    consectiveZeros = 0;
                    continue;   
                }
                if (not jDigit){
                    consectiveZeros++;
                }else{
                    numberWays *= fibo[consectiveZeros];
                    consectiveZeros = 0;
                }

            }
            numberWays *= fibo[consectiveZeros];

            mt.mat[i][j] = numberWays;
        }
    }
}

Matrix fexp(ll b) {
    Matrix ans;
    for (int i = 0; i < (1 << n); i++){
        ans.mat[i][i] = 1;
        
    }
    while(b) {
        if(b & 1) ans = ans * mt;
        mt = mt * mt;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    
    Matrix ans;
    cin >> n >> columns;
    makeRelations();
    ans = fexp (columns);
    cout << ans.mat[0][0] << endl;
    


        
    return 0;
    
}