#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long num_input, val;
    cin >> num_input;
    vector<long>arr;
    vector<long>sum_arr (num_input, -10000000001);
    long best_sum;
    for (int i = 0; i < num_input; i ++){
        cin >> val;
        arr.push_back(val);
    }
    sum_arr[num_input - 1] = arr[num_input - 1];
    best_sum = sum_arr[num_input - 1];
    for (int i = num_input - 2; i >= 0 ; i--){
        if (arr[i] > sum_arr[i+1] + arr[i]){
            sum_arr[i] = arr[i];
        }else{
            sum_arr[i] = sum_arr[i+1] + arr[i];
        }
        if (sum_arr[i] > best_sum){
            best_sum = sum_arr[i];
        }
    }
    cout << best_sum;

}