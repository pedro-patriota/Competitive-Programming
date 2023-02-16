#include <bits/stdc++.h>
using namespace std;
long long test_cases, perm_size, pos, mid, temp;
long long *arr;
set<long long> possible_num;
bool found, past;

/* void is_possible(long long act_pos, long long *arr, set<long long> possible_num){
    if (act_pos == perm_size -1){
        found = true;
    }
    if (act_pos == 0){
        for (auto val : possible_num){
            if (val != act_pos){
                is_pos
            }
        }
    }

} */

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> test_cases;
    for (long long i = 0; i < test_cases; i++){
        cin >> perm_size;
        arr = new long long[perm_size];
        pos = 0;
        for (long long j = perm_size; j > 0; j--){
            possible_num.insert(j);
            arr[pos] = j;
            pos++;
        }
        mid = (perm_size)/2;
        if (mid + 1 == arr[mid]){
            if (mid + 2 >= perm_size || mid -2 < 0){
                cout << -1 << "\n";
            }
            else{
                if (mid - 3 == 0){
                    temp = arr[mid];
                    arr[mid] = arr[mid -1];
                    arr[mid -1] = temp;
                    
                }else{
                    temp = arr[mid];
                    arr[mid] = arr[mid -2];
                    arr[mid -2] = temp;
                }
                for (long long j = 0; j < perm_size; j++){
                    cout << arr[j] << " ";
                }
                cout << "\n";
            }
        }else{
            for (long long j = 0; j < perm_size; j++){
                cout << arr[j] << " ";
            }
            cout << "\n";
        }
        
        
    }
    
}