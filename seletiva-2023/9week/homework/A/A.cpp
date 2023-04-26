#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll num_val, num_queries, command, n1, n2;
const ll ms = 2e5 + 5;
ll seg[1000]; // poe oo 4*;

void build(vector<ll>&v, int l, int r, int idx){
    if (l == r){
        seg[idx] = v[l];
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    build(v, l, m, left);
    build(v, m+1, r, right);

    seg[idx] = seg[left] + seg[right];
}

ll query(int L, int R, int l, int r, int idx){
    if (R < l || L > r ) return 0;
    
    if ( L <= l && r <= R) return seg[idx];
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    return query(L, R, l, m, left) + query(L, R, m +1, r, right);

}

void update(int pos, ll num, int l, int r, int idx){
    if (l == r){
        seg[idx] = num;
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (pos <= m){
        update(pos, num, l, m, left);
    }else{
        update(pos, num, m+1, r, right);
    }
    seg[idx] = seg[left] + seg[right];
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_val >> num_queries;
    vector<ll>arr(num_val);
    for (ll i = 0; i < num_val; i++){
        cin >> arr[i];
    }
    build(arr, 0, num_val-1, 0 );
    for (ll i = 0; i < num_queries; i++){
        cin >> command >> n1 >> n2;
        n1--;
        n2--;
        if (command == 2){
            cout << query(n1, n2, 0, num_val-1, 0) << endl;
        }else{
            n2++;
            update(n1, n2, 0, num_val - 1, 0);
        }
    }

    
    
}