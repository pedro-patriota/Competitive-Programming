#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll ms = 2e5 + 5;
ll seg[4*ms]; // poe oo 4*;


/* void build(vector<ll>&v, int l, int r, int idx){
    if (l == r){
        seg[idx] = 0;
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    build(v, l, m, left);
    build(v, m+1, r, right);

    seg[idx] = seg[left] + seg[right];
} */

ll query(int pos, ll num, int l, int r, int idx, vector<ll>&v){
    num += seg[idx];
    if (l == r){
        auto ans = v[l] + num;
        return (v[l] + num);
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;


    if (pos <= m){
        return query(pos, num, l, m, left,v);
    }else{
        return query(pos, num, m+1, r, right, v);
    }
}

void update(int L, int R, int l, int r, int idx, ll num){
    if (R < l || L > r ) return;
    
    if ( L <= l && r <= R){
        seg[idx] += num;
        return;
    }  
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    update(L, R, l, m, left, num);
    update(L, R, m +1, r, right, num);
    return;

}



int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll num_val, num_queries, command, n1, n2, u;
    cin >> num_val >> num_queries;
    vector<ll>arr(num_val);
    for (ll i = 0; i < num_val; i++){
        cin >> arr[i];
    }        
    for (ll i = 0; i < num_queries; i ++){
        cin >> command;
        if (command == 1){
            cin >> n1 >> n2 >> u;
            n1--;
            n2--;
            update(n1, n2, 0, num_val-1, 0, u);
        }else{
            cin >> n1;
            n1--;
            cout << query(n1, 0, 0, num_val -1, 0, arr) << endl;
        }
    }
    
    
}