#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

const int ms = 2e6 + 17;
vector<int> nearestPrimes(ms, 0);
vector<int> primes;
vector<bool> isPrime(ms, true);

vector<vector<ll>> table;
vector<ll> lg2;
void build(int n, vector<ll> v) {
  lg2.resize(n + 1);
  lg2[1] = 0;
  for (int i = 2; i <= n; i++) {
    lg2[i] = lg2[i >> 1] + 1;
  }
  table.resize(lg2[n] + 1);
  for (int i = 0; i < lg2[n] + 1; i++) {
    table[i].resize(n + 1);
  }
  for (int i = 0; i < n; i++) {
    table[0][i] = v[i];
  }
  for (int i = 0; i < lg2[n]; i++) {    for (int j = 0; j < n; j++) {
      if (j + (1 << i) >= n) break;
      table[i + 1][j] = max(table[i][j], table[i][j + (1 << i)]);
    }
  }
}
ll get(int l, int r) { // (l,r) inclusivo
  int k = lg2[r - l + 1];
  return max(table[k][l], table[k][r - (1 << k) + 1]);
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    isPrime[1] = true; primes.push_back(1);
    nearestPrimes[1] = 1;
    for (int i = 2; i < ms; i++){
        if (isPrime[i]){
            primes.push_back(i);
            nearestPrimes[i] = i;
            for (int j = 2*i; j < ms; j += i){
                isPrime[j] = false;
                nearestPrimes[j] = max(nearestPrimes[j], i);
            }
        }
    }
   
    int n,q;
    cin >> n >> q;
    vector<priority_queue<int, vector<int>, greater<int>>> freq (ms);
    
    vector<ll> order(n, 0);
    for (int i = 0; i < n; i++){
        int v; cin >> v;
        freq[v].push(i);
    }
    ll o = 0;
    for (int k = 2e6; k >= 2; k--){
        while (not freq[k].empty()){
            int v = freq[k].top();
            freq[k].pop();
            order[v] = ++o;
            freq[k/nearestPrimes[k]].push(v);
        }
        //freq[k] = {};
    }
    build(n, order);
    while (q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << get(l, r) << endl;
    }



    return 0;
}