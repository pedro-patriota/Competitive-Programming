#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long long arr_size, val, rest;
    long long target, counter = 0;
    cin >> arr_size;
    cin >> target;
    vector<long long>table(arr_size);
    
    for (int i = 0; i < arr_size; i++){
        cin >> val;
        table[i] = val;
    }    
    
    long long arr_size_left = arr_size/2;
    vector<long long>comb1;
    
    for (int mask =0; mask < (1 << arr_size_left); mask++){
        long long sum = 0;
        for (int j = 0; j < mask; j++){
            if ((mask >> j) & 1){
                sum += table[j];
            }
            if (sum > target){
                break;
            }
        }
        if (sum == target){
            counter += 1;
        }else if (sum < target){
        comb1.push_back(sum);
        }

    }
    long long arr_size_right = arr_size - arr_size_left;
    vector<long long>comb2;

    for (int mask =0; mask < (1 << arr_size_right); mask++){
        long long sum = 0;
        for (int j = 0; j < mask; j++){
            if ((mask >> j) & 1){
                sum += table[arr_size_left + j];
            }
            if (sum > target){
                break;
            }
        }
        if (sum == target){
            counter += 1;
        }else if (sum < target){
            comb2.push_back(sum);
        }

    }
    sort(comb2.begin(), comb2.end());
    for (auto it : comb1){
        long long rest = target - it;
        auto in_bet = equal_range(comb2.begin(), comb2.end(), rest);
        counter += in_bet.second - in_bet.first;
    }
    cout << counter;
    
}