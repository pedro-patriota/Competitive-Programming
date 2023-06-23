#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int max_L = 1e5 + 5;
int seg[4*max_L];

void build(vector<int>&v, int l, int r, int idx){
    if (l == r){
        seg[idx] = v[l];
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    build(v, l, m, left);
    build(v, m+1, r, right);
    
    if (seg[left] == seg[right]){
        seg[idx] = seg[left];
    }else{
        seg[idx] = -1;
    }
}
int query(int L, int R, int l, int r, int idx){
    if (l > R || r < L ){
        return INT_MAX;
    }
    if (l >= L && r <= R){
        return seg[idx];
    }
    int m = (l + r)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    return min(query(L, R, l, m, left), query(L, R, m+1, r, right));
}

void update (int pos, int num, int l, int r, int idx){
    if (l == r){
        seg[idx] = num;
        return;
    }
    int m = (l + r)/2;
    int left = 2*idx  +1;
    int right = 2*idx + 2;

    if (pos <= m){
        update(pos, num, l, m, left);
    }else{
        update(pos, num, m+1, r, right);
    }

    if (seg[left] == seg[right]){
        seg[idx] = seg[left];
    }else{
        seg[idx] = -1;
    }
}


int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, q, from, to;
    int res, res2;
    char op;
    cin >> n >> q;
    vector<int> v (n, true);
    build(v, 0, n-1, 0);
    for (int i  = 0; i < q; i++){
        cin >> op >> from;
        from--;
        if (op == '?'){
            cin >> to;
            to--;
            if (from < to){
                res = query(from, to, 0, n -1, 0);
                res2 = min(query(to, n-1, 0, n-1, 0), query(0, from, 0, n-1, 0));
            }else{
                res = query(to, from, 0, n -1, 0);
                res2 = min(query(from, n-1, 0, n-1, 0), query(0, to, 0, n-1, 0));
            }
           
            res = max(res, res2);
            if (res == 1){
                cout << "possible\n";
            }else{
                cout << "impossible\n";
            }
        }else if (op == '-'){
            update(from, 0, 0, n-1, 0);
        }else if (op == '+'){
            update(from, 1, 0, n-1, 0);
        }
    }

    
        
    return 0;
    
}