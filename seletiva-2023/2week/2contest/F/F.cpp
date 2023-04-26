#include <bits/stdc++.h>
using namespace std;

long long test_cases, length, val, count_R, count_B, sum_R, sum_B;
vector<long long> arr;
bool found;
void solver(long long sum_B, long long sum_R, long long count_R, long long count_B, long long i){
    if (!(count_R < count_B)){
        return;
    }
    if (count_R < count_B && sum_R > sum_B){
        found = true;
        return;
    }
    if (!(sum_R > sum_B)){
        long long biggest_min = arr[i];
        solver (sum_B - biggest_min, sum_R, count_R, count_B -1, i-1);
        if (found){
            return;
        }
        solver(sum_B - biggest_min, sum_R + biggest_min, count_R + 1, count_B - 1, i-1);
    }
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_cases;
    for (int i = 0; i < test_cases; i++){
        arr = vector<long long>();
        sum_B = 0;
        sum_R = 0;
        found = false;
        cin >> length;
        for (int i =0; i < length; i++){
            cin >> val;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());
        count_B = length/2 + 1;
        count_R = length - count_B;
        for (int i = 0; i < count_B; i++){
            sum_B += arr[i];
        }
        for (int i = count_B; i < length; i++){
            sum_R += arr[i];
        }
        solver(sum_B, sum_R, count_R, count_B, count_B - 1);
        if (found){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << "\n";
    }
    
}