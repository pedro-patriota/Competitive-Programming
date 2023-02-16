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
        for (long long j = 0; j < n; j++){
            cin >> val;
            arr[j] = val;
            best_arr[j] = (val);
            freq_map[val]++;
        }
        
        counter =0;
        sort(best_arr.begin(), best_arr.end());
        multimap<long long, long long> table;
        for (long long it = 0; it < n ; it++){
            table.insert(make_pair(best_arr[it], it));
        }
        for (long long it = 0; it < n -1 ; it++){
            table.erase(arr[it]);

            if (r - arr[it] > 0){
                counter += upper_bound(table.begin(), table.end(), r-arr[it])->second - lower_bound(table.begin(), table.end(), l - arr[it])->second;
            }
        }
        cout << counter << "\n";
        
    }
    
    
}