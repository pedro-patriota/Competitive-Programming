#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int nums, target, val, rest;
    cin >> nums;
    cin >> target; 

    multimap<int, int> freq_map;
    vector<int>arr;
    for (int i = 0; i < nums; i++){
        cin >> val;
        arr.push_back(val);
        freq_map.insert(make_pair(val, i+1));
    }
    bool found = false;
    for (auto it = freq_map.begin(); it != freq_map.end(); ++it){
        rest = target - it->first;
        if (rest > 0){
            if (rest == it->first){
                if (freq_map.count(it->first) > 1){
                    auto aux = it;
                    ++aux;
                    cout << it->second << " " << aux->second;
                    found = true;
                    break;
                }
            }else{
                auto pos = freq_map.find(rest)->second;
                if (pos > 0 && pos <= nums){
                    cout << pos << " " << it->second;
                    found = true;
                    break;
                    
                }
            }
        }
    }
    if (!found){
        cout << "IMPOSSIBLE";
    }
}