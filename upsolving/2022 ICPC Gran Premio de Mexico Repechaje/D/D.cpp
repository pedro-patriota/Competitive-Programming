#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define PB push_back
#define X first
#define Y second
#define br '\n'

const bool multitest = 0;


using namespace __gnu_pbds;
template<typename T>
class multi_indexed_set{

    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
      tree_order_statistics_node_update> miset;
    unordered_map<T, int> freq;

    public:
  void insert(T x){
      freq[x]++;
      miset.insert({x, freq[x]});
  }
  void erase(T x){
      if(!freq[x]) return;
      miset.erase({x, freq[x]});
      freq[x]--;
  }
  int order_of_key(T x){ return miset.order_of_key({x, 0}); }
  int count(T x) { return freq[x]; }
  int size(){ return miset.size(); }

};


void solve(){

  int m; cin >> m;
  vector<ll> op (m);
  multi_indexed_set<ll> ms;

  for (int j = 0; j < m; j++){
    int type; cin >> type;
    if(type == 1){
      ll x; cin >> x;
      ms.insert(x);
      op[j] = x;
    }else if(type == 2){
      int i; cin >> i;
      i--;
      ms.erase(op[i]);
    }else if(type == 3){
      int i; cin >> i;
      i--;
      ll x; cin >> x;
      ms.erase(op[i]);
      op[i] += x;
      ms.insert(op[i]);
    }else{
      int i; cin >> i;
      i--;
      cout << ms.order_of_key(op[i]) << br;
    }
  }

} 

int main(){
  io; 
  // freopen("digits.in", "r", stdin);
  // freopen("digits.out", "w", stdout);
  // cout << setprecision(10) << fixed;
  int t = 1;
  if(multitest) cin >> t;
  while(t--){
    solve();
  }
}