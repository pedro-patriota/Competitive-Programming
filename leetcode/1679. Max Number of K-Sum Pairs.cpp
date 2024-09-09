#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,2,3,4], k = 5
Output: 2

Input: nums = [3,1,3,4,3], k = 6
Output: 1

[1, 2, 3, 4] k =10
0

k > 0
sz < 1e5
num < 1e9

1 3 4 2 k = 5
output: 2

5 k = 5
0

1 4 5 2 k = 5
1

1 4 3 3 2 k = 6
2

1 Approach
hashmap
1 0
4 0
3 0
2 0

int cnt = 2

k = 5
1 3 4 2
        ^
cnt = 2
k = 6
1 4 3 3 2
          ^
time: O(N)
space:O(N)  

2 Approach
cnt = 2

k = 6
1 2 3 3 4
      ^      
    ^

time: O(NlogN)
space: O(1)

*/

int maxOperations (vector<int>& arr, int k) {
    int sz = arr.size(), cnt = 0;
    if (sz < 2) {
        return cnt;
    }
    
    unordered_map<int, int> freq;
    for (auto val : arr) {
        freq[val]++;
    }
    for (auto val : arr) {
        if (freq[val] > 0) {
            freq[val]--;
            
            if (freq[k - val] > 0) {
                freq[k-val]--;
                cnt++;
            }
        }
    }

    return cnt;

}

int main () {
    vector<int> arr = {1, 4, 3, 3, 2};
    cout << maxOperations(arr, 6) << endl; // 2

    arr = {3, 1, 3, 4,3};
    cout << maxOperations(arr, 6) << endl; // 1
    arr = {1,2,3,4};
    cout << maxOperations(arr, 5) << endl; // 2

    arr = {1, 4, 3, 3, 2};
    cout << maxOperations(arr, 10) << endl; // 0
    

    arr = {1, 4, 5, 2};
    cout << maxOperations(arr, 5) << endl; // 1

    arr = {5};
    cout << maxOperations(arr, 5) << endl; // 0
}