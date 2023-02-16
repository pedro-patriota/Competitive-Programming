#include <bits/stdc++.h>
using namespace std;
long long test_cases, n, l, r, val, p1, p2, counter,  minim, maxim, maxim_dis;
vector<long long> arr;
vector<long long> best_arr;
map<long long, long long> freq_map;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> test_cases;
    for (long long i = 0; i < test_cases; i++){
        cin >> n >> l >> r;
        
        arr = vector<long long>(n);
        best_arr = vector<long long>(n);
        for (long long val = 0; val < n; val++){
            cin >> arr[val];
        }
        sort(arr.begin(), arr.end());
        auto init = arr.begin()+1;
        counter = 0;
        for (long long it = 0; it < n -1; it++){
            auto val = arr[it];
            long long rest_L = l-val;            
            long long rest_R = r - val;
            auto lower_b = lower_bound(init, arr.end(), rest_L);            
            auto upper_b = upper_bound(init, arr.end(), rest_R);

            counter += upper_b - lower_b;

        }
        cout << counter << "\n";
        
    }
    
    
}