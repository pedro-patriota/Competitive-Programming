#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

ordered_set X;

vector<vector<ii>> table;
vector<int> lg2;
void build(int n, vector<int> v) {
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
    table[0][i] = {v[i], i};
  }
  for (int i = 0; i < lg2[n]; i++) {
    for (int j = 0; j < n; j++) {
      if (j + (1 << i) >= n) break;
      table[i + 1][j] = max(table[i][j], table[i][j + (1 << i)]);
    }
  }
}
int get(int l, int r) {
  int k = lg2[r - l + 1];
  if (table[k][l] > table[k][r - (1 << k) + 1]){
    return table[k][l].second;
  }else{
    return table[k][r - (1 << k) + 1].second;
  }

  //return max(table[k][l], table[k][r - (1 << k) + 1]);
}

int main()
{
  ios ::sync_with_stdio(0);
  cin.tie(0);

  int n, m, val, l, r;
  cin >> n >> m;
  vector<int> arr(n);
  map<int, int> valToPos;
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    arr[i] = val;
    X.insert(i);
  }
  build(n, arr);
  for (int i = 0; i < m; i++){
    cin >> l >> r;
    l--;
    r--;
    auto lKey = X.find_by_order(l);
    auto rKey = X.find_by_order(r);

    //cout << *lKey << " " << *rKey << endl;
    int largest = get(*lKey, *rKey);
    //cout << largest << endl;
    rKey++;
    for (auto it = lKey; it != rKey;){
      if (*it != largest){
        int k = *it;
        //cout <<"Key a ser deletada -> " << k << endl;
        it = X.erase(it);
      }else{
        ++it;
      }
    }
  }
  for (auto it = X.begin(); it != X.end(); it++){
    cout << arr[*it] << " ";
  }

  return 0;
}