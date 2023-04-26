#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int>seg;
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
ll query(int pos, ll num, int l, int r, int idx){
    num += seg[idx];
    if (l == r){
        return (num);
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;


    if (pos <= m){
        return query(pos, num, l, m, left);
    }else{
        return query(pos, num, m+1, r, right);
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

    ll test_cases, nodes, val;
    cin >> test_cases;
    for (ll i = 0; i < test_cases; i++){
        cin >> nodes;
        vector<int> arr(nodes);
        seg= vector<int>(4500);
        for (ll j = 0; j <  nodes; j++){
            cin >> val;
            val --;
            arr[j] = val;
        }
        
        ll count = 0; 
        for (ll j = 0; j <  nodes; j++){
            ll init = min((int)j, arr[j]);
            ll end = max((int)j, arr[j]);
            
            count += query(arr[j], 0, 0, nodes - 1, 0);
            update(init, end, 0, nodes -1, 0, 1);
        }
        cout << count << endl;
        

    }
    
    
}