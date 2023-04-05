#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> aux(n);
    map<int,int> aux_map;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        aux_map[arr[i] - k]++;
    }
    int ans = 0;
    for (auto val : arr){
        if (aux_map.count(val)){
            ans += aux_map[val];
        }
        
    }
    cout << ans << endl;
        
    
    
}