#include <bits/stdc++.h>
using namespace std;
long long test_cases, num_rungs, temp, r, l, m, maximum, last, val;
vector<long long> bamboo;    
multimap<long long, long long> bammboo_map;

bool is_possible(long long m){
    if (m < maximum){
        return true;
    }
    auto first = bammboo_map.lower_bound(m);
    for (int i = first->second ; i < num_rungs; i++){
        if (m < bamboo[i]){
            return false;
        }
        if (m == bamboo[i]){
            m--;
        }
    }
    return true;

}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test_cases;
    for (int j = 0; j < test_cases; j++){
        cin >> num_rungs;
        bamboo = vector<long long>(num_rungs);
        bammboo_map = multimap<long long, long long>();
        cin >> bamboo[0];
        r  = bamboo[0];
        maximum = -1;
        last = bamboo[0];
        for (int i = 1; i < num_rungs; i++){
            cin >> val;
            temp = val - last;
            bamboo[i] = temp;

            bammboo_map.insert(make_pair(temp, i));
            
            r += temp;
            if (temp > maximum){
                maximum = temp;
            }
            last = val;
        }
        l = maximum;
        while (l < r){
            m = (l + r)/2;
            if (is_possible(m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        cout << "Case " << j + 1 << ": " << l << "\n";

    }

}