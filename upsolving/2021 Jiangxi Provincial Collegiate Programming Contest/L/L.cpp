#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int max_L = 1e5 + 17;
int seg[8 * max_L];
ll ans = 0, aux;

int query(int pos, ll num, int l, int r, int idx)
{
    if (pos >= l && pos <= r && seg[idx] == 1)
    {
        aux = r;
        return seg[idx];
    }
    if (l == r){
        return seg[idx];
    }
    int m = (l + r) / 2;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (pos <= m)
    {
        return query(pos, num, l, m, left);
    }
    else
    {
        return query(pos, num, m + 1, r, right);
    }
}

void update(int L, int R, int l, int r, int idx, ll num)
{
    if (R < l || L > r)
        return;

    if (L <= l && r <= R)
    {
        if (seg[idx] != 1){
            seg[idx] = num;
           
        }
        return;

    }
    int m = (l + r) / 2;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    update(L, R, l, m, left, num);
    update(L, R, m + 1, r, right, num);
    
    return;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    ll n, x1, y1, x2, y2;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        aux= -1;
     
        x1 *= 2;
        x2 *= 2;
        update(x1, x2, 0, 2*max_L -1, 0, 1);
        
    }
    bool past = false;
    for (int i = 3; i < 2*max_L - 1; i += 2){
        if (query(i, 0, 0, 2*max_L-1, 0)){
            ans++;
        }
    }
    cout << ans;

    return 0;
}