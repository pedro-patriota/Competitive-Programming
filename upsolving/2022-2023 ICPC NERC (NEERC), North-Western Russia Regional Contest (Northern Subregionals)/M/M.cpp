#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

const int ms = 2e5 + 7;
int arr[4 * ms], seg[4 * ms], n;

void build(int idx = 0, int l = 0, int r = n - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(l == r) {
    seg[idx] = arr[l];
    return;
  }
  build(left, l, mid); build(right, mid + 1, r);
  seg[idx] = min(seg[left], seg[right]); // Merge
}

int query(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(R < l || L > r) return 1e9; // Valor que nao atrapalhe
  if(L <= l && r <= R) return seg[idx];
  return min (query(L, R, left, l, mid), query(L, R, right, mid + 1, r)); // Merge
}

int findNext(int L, int Val, int R = n -1,  int idx= 0, int l = 0, int r = n - 1){
    int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
    int v = seg[idx];

    if(R < l || L > r) return 1e9; // Valor que nao atrapalhe
    if (v > Val) return 1e9;
    
    if (l == r){
        return l;
    }
    int res =  findNext(L, Val, R, left, l, mid);
    if (res == 1e9) res = findNext(L, Val, R, right, mid + 1, r);
        
    return res;
    

}

void update(int V, int I, int idx = 0, int l = 0, int r = n -1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(l > I || r < I) return;
  if(l == r) {
    arr[I] = V;
    seg[idx] = V; // Aplicar Update
    return;
  }
  update(V, I, left, l, mid); update(V, I, right, mid + 1, r);
  seg[idx] = min(seg[left], seg[right]); // Merge
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int q, op, pos;
    cin >> n;
    int ans = 0;
    int m = -1;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (m == -1){
            m = arr[0];
            ans += m;
            continue;
        }
        m = min(m, arr[i]);
        ans += m;
    }

    cin >> q;

    build();
    cout << ans << endl;
    for (int i = 0; i < q; i++){
        cin >> op >> pos;
       
        int val = arr[pos];
        int leftMin = pos > 0 ?  query(0, pos - 1) : 1e9;
        
        if (op == 1){
            if (leftMin > val){
                int l = pos != n - 1 ? min(findNext(pos + 1, val), n) : n;
                ans += l - pos;
            }
            update(val + 1, pos);
        }else{
            if  (leftMin >= val){
                int l =  pos != n - 1 ? min(findNext(pos + 1, val - 1), n) : n;
                ans -= l - pos;
            }
            update(val - 1, pos);
        }
        cout << ans << endl;
    }
    
    
        
    return 0;
    
}