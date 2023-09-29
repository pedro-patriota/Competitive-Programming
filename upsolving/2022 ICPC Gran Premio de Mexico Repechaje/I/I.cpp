#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>
#define X first
#define Y second

const int ms = 5 * 1e5 + 17;

int seg[4 * ms], n, m;
vector<int> a(4 * ms);
vector<int> arr;

int MaxSeg[4 * ms];

void buildMax(int idx = 0, int l = 0, int r = n - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(l == r) {
    MaxSeg[idx] = a[l];
    return;
  }
  buildMax(left, l, mid); buildMax(right, mid + 1, r);
  MaxSeg[idx] = max(MaxSeg[left],MaxSeg[right]); // Merge
}

ll queryMax(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(R < l || L > r) return 0; // Valor que nao atrapalhe
  if(L <= l && r <= R) return (ll) MaxSeg[idx];
  return max(queryMax(L, R, left, l, mid), queryMax(L, R, right, mid + 1, r)); // Merge
}

// ------------------------------------------------------------------
void build(int idx = 0, int l = 0, int r = m - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(l == r) {
    seg[idx] = arr[l];
    return;
  }
  build(left, l, mid); build(right, mid + 1, r);
  seg[idx] = seg[left] + seg[right]; // Merge
}

ll query(int L, int R, int idx = 0, int l = 0, int r = m - 1) {
  int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
  if(R < l || L > r) return 0; // Valor que nao atrapalhe
  if(L <= l && r <= R) return (ll) seg[idx];
  return query(L, R, left, l, mid) + query(L, R, right, mid + 1, r); // Merge
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    buildMax();

    int q, val;
    int left, right;
    int pastId;
    cin >> q;
    for (int qr = 0; qr < q; qr ++ ){
        cin >> m;
        arr = vector<int> ();
    
        vector<pair<ll, int>> totalVal;
        set<int> usedPos;
        ll ans = 0;
        for (int i = 0; i < m; i++){

            int id; cin >> id; --id;
            if (i > 0 && (id - pastId) > 1){
                val = queryMax(pastId, id);
                arr.push_back(0);
                
                totalVal.push_back({val, arr.size() - 1});
            }
            arr.push_back(1);
            totalVal.push_back({a[id], arr.size() - 1});
            pastId = id;
        }
        sort(totalVal.begin(), totalVal.end());
        m = arr.size();
        build();
        for (int i  = m - 1;  i >= 0; i--){
            auto [val, pos] = totalVal[i];
            auto it = usedPos.upper_bound(pos);
            if (usedPos.size() == 0){
                left = 0;
                right = m - 1;
            }else if (it == usedPos.end()){
                left = *(--it) + 1;
                right = m - 1;
            }else if (it == usedPos.begin()){
                left  = 0;
                right = *it - 1;
            }else{
                right = *it - 1;
                left = *(--it) + 1;
            }

            int qntLeft, qntRight;
            qntLeft = query(left, pos);
            qntRight = query(pos, right);

            ans += (val*qntRight)*qntLeft;
            
            usedPos.insert(pos);
        }
        
        cout << ans << endl; 
        
    }

    
        
    return 0;
    
}